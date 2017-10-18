/*
 * Copyright 2017, Data61
 * Commonwealth Scientific and Industrial Research Organisation (CSIRO)
 * ABN 41 687 119 230.
 *
 * This software may be distributed and modified according to the terms of
 * the BSD 2-Clause license. Note that NO WARRANTY is provided.
 * See "LICENSE_BSD2.txt" for details.
 *
 * @TAG(DATA61_BSD)
 */

/* Include Kconfig variables. */
#include <autoconf.h>

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <limits.h>

#include <allocman/bootstrap.h>
#include <allocman/vka.h>

#include <sel4platsupport/timer.h>
#include <sel4platsupport/plat/serial.h>

#include <sel4debug/register_dump.h>
#include <sel4platsupport/device.h>
#include <sel4platsupport/platsupport.h>
#include <sel4utils/vspace.h>
#include <sel4utils/stack.h>
#include <sel4utils/process.h>

#include <simple/simple.h>
#include <simple-default/simple-default.h>

#include <utils/util.h>

#include <vka/object.h>
#include <vka/capops.h>
#include <vka/object_capops.h>

#include <sel4/types_gen.h>

#include <vspace/vspace.h>

#include "test.h"

#define TESTS_APP "sel4test-tests"

#include "lib_test.h"

#include <sync/mutex.h>
#include <sync/sem.h>
#include <sync/condition_var.h>
#include <sync/bin_sem.h>
#include <sel4bench/sel4bench.h>

/* ammount of untyped memory to reserve for the driver (32mb) */
#define DRIVER_UNTYPED_MEMORY (1 << 25)
/* Number of untypeds to try and use to allocate the driver memory.
 * if we cannot get 32mb with 16 untypeds then something is probably wrong */
#define DRIVER_NUM_UNTYPEDS 16

/* dimensions of virtual memory for the allocator to use */
#define ALLOCATOR_VIRTUAL_POOL_SIZE ((1 << seL4_PageBits) * 100)

/* static memory for the allocator to bootstrap with */
#define ALLOCATOR_STATIC_POOL_SIZE ((1 << seL4_PageBits) * 20)
static char allocator_mem_pool[ALLOCATOR_STATIC_POOL_SIZE];

/* static memory for virtual memory bootstrapping */
static sel4utils_alloc_data_t data;

/* environment encapsulating allocation interfaces etc */
static struct env env;
/* the number of untyped objects we have to give out to processes */
static int num_untypeds;
/* list of untypeds to give out to test processes */
static vka_object_t untypeds[CONFIG_MAX_NUM_BOOTINFO_UNTYPED_CAPS];
/* list of sizes (in bits) corresponding to untyped */
static uint8_t untyped_size_bits_list[CONFIG_MAX_NUM_BOOTINFO_UNTYPED_CAPS];

allocman_t *allocman;
seL4_Word reply_eps[CLIENT_MAX];

#define IPCBUF_FRAME_SIZE_BITS 12
#define IPCBUF_VADDR 0x7000000



seL4_CPtr ep_object;

/* initialise our runtime environment */
static void
init_env(env_t env)
{
    reservation_t virtual_reservation;
    int error;

    /* create an allocator */
    allocman = bootstrap_use_current_simple(&env->simple, ALLOCATOR_STATIC_POOL_SIZE, allocator_mem_pool);
    if (allocman == NULL) {
        ZF_LOGF("Failed to create allocman");
    }

    /* create a vka (interface for interacting with the underlying allocator) */
    allocman_make_vka(&env->vka, allocman);

    /* create a vspace (virtual memory management interface). We pass
     * boot info not because it will use capabilities from it, but so
     * it knows the address and will add it as a reserved region */
    error = sel4utils_bootstrap_vspace_with_bootinfo_leaky(&env->vspace,
                                                           &data, simple_get_pd(&env->simple),
                                                           &env->vka, platsupport_get_bootinfo());
    if (error) {
        ZF_LOGF("Failed to bootstrap vspace");
    }

    /* fill the allocator with virtual memory */
    void *vaddr;
    virtual_reservation = vspace_reserve_range(&env->vspace,
                                               ALLOCATOR_VIRTUAL_POOL_SIZE, seL4_AllRights, 1, &vaddr);
    if (virtual_reservation.res == 0) {
        ZF_LOGF("Failed to provide virtual memory for allocator");
    }

    bootstrap_configure_virtual_pool(allocman, vaddr,
                                     ALLOCATOR_VIRTUAL_POOL_SIZE, simple_get_pd(&env->simple));

    error = vka_alloc_endpoint(&env->vka, &env->endpoint);
    ZF_LOGF_IFERR(error, "Failed to allocate new endpoint object.\n");

    env->client_num ++;

}



/* Free a list of objects */
static void
free_objects(vka_object_t *objects, unsigned int num)
{
    for (unsigned int i = 0; i < num; i++) {
        vka_free_object(&env.vka, &objects[i]);
    }
}

/* Allocate untypeds till either a certain number of bytes is allocated
 * or a certain number of untyped objects */
static unsigned int
allocate_untypeds(vka_object_t *untypeds, size_t bytes, unsigned int max_untypeds)
{
    unsigned int num_untypeds = 0;
    size_t allocated = 0;

    /* try to allocate as many of each possible untyped size as possible */
    for (uint8_t size_bits = seL4_WordBits - 1; size_bits > PAGE_BITS_4K; size_bits--) {
        /* keep allocating until we run out, or if allocating would
         * cause us to allocate too much memory*/
        while (num_untypeds < max_untypeds &&
               allocated + BIT(size_bits) <= bytes &&
               vka_alloc_untyped(&env.vka, size_bits, &untypeds[num_untypeds]) == 0) {
            allocated += BIT(size_bits);
            num_untypeds++;
        }
    }
    return num_untypeds;
}

/* extract a large number of untypeds from the allocator */
static unsigned int
populate_untypeds(vka_object_t *untypeds)
{
    /* First reserve some memory for the driver */
    vka_object_t reserve[DRIVER_NUM_UNTYPEDS];
    unsigned int reserve_num = allocate_untypeds(reserve, DRIVER_UNTYPED_MEMORY, DRIVER_NUM_UNTYPEDS);

    /* Now allocate everything else for the tests */
    unsigned int num_untypeds = allocate_untypeds(untypeds, UINT_MAX, ARRAY_SIZE(untyped_size_bits_list));
    /* Fill out the size_bits list */
    for (unsigned int i = 0; i < num_untypeds; i++) {
        untyped_size_bits_list[i] = untypeds[i].size_bits;
    }

    /* Return reserve memory */
    free_objects(reserve, reserve_num);

    /* Return number of untypeds for tests */
    if (num_untypeds == 0) {
        ZF_LOGF("No untypeds for tests!");
    }

    return num_untypeds;
}

/* copy untyped caps into a processes cspace, return the cap range they can be found in */
static seL4_SlotRegion
copy_untypeds_to_process(sel4utils_process_t *process, vka_object_t *untypeds, int num_untypeds)
{
    seL4_SlotRegion range = {0};

    for (int i = 0; i < num_untypeds; i++) {
        seL4_CPtr slot = sel4utils_copy_cap_to_process(process, &env.vka, untypeds[i].cptr);

        /* set up the cap range */
        if (i == 0) {
            range.start = slot;
        }
        range.end = slot;
    }
    assert((range.end - range.start) + 1 == num_untypeds);
    return range;
}

/* map the init data into the process, and send the address via ipc */
static void *
send_init_data(env_t env, seL4_CPtr endpoint, sel4utils_process_t *process)
{
    /* map the cap into remote vspace */
    void *remote_vaddr = vspace_map_pages(&process->vspace, &env->init_frame_cap_copy, NULL, seL4_AllRights, 1, PAGE_BITS_4K, 1);
    assert(remote_vaddr != 0);

    /* now send a message telling the process what address the data is at */
    /* seL4_MessageInfo_t info = seL4_MessageInfo_new(seL4_Fault_NullFault, 0, 0, 1);
    seL4_SetMR(0, (seL4_Word) remote_vaddr);
    seL4_Send(endpoint, info); */

    return remote_vaddr;
}

/* copy the caps required to set up the sel4platsupport default timer */
static void
copy_timer_caps(test_init_data_t *init, env_t env, sel4utils_process_t *test_process)
{
    /* Copy PS default timer's IRQ cap to child process. */
    init->timer_irq_cap = sel4utils_copy_cap_to_process(test_process, &env->vka, env->timer_objects.timer_irq_path.capPtr);
    ZF_LOGF_IF(init->timer_irq_cap == 0,
               "Failed to copy PS default timer IRQ cap to test child "
               "process.");

    /* untyped cap for timer device untyped */
    init->timer_paddr = env->timer_objects.timer_paddr;
    init->timer_dev_ut_cap = sel4utils_copy_cap_to_process(test_process, &env->vka, env->timer_objects.timer_dev_ut_obj.cptr);
    ZF_LOGF_IF(init->timer_dev_ut_cap == 0,
               "Failed to copy PS default timer device-ut to test child.");

    arch_copy_timer_caps(init, env, test_process);
}

static void
copy_serial_caps(test_init_data_t *init, env_t env, sel4utils_process_t *test_process)
{
    init->serial_irq_cap = sel4utils_copy_cap_to_process(test_process, &env->vka,
                                               env->serial_objects.serial_irq_path.capPtr);
    ZF_LOGF_IF(init->serial_irq_cap == 0,
               "Failed to copy PS default serial IRQ cap to test child "
               "process.");

    arch_copy_serial_caps(init, env, test_process);
}

/* Run a single test.
 * Each test is launched as its own process. */
int
run_test(struct testcase *test)
{
    UNUSED int error;
    sel4utils_process_t test_process;

    /* Test intro banner. */
    printf("  %s\n", test->name);

    error = sel4utils_configure_process(&test_process, &env.vka, &env.vspace,
                                        env.init->priority, TESTS_APP);
    assert(error == 0);

    /* set up caps about the process */
    env.init->stack_pages = CONFIG_SEL4UTILS_STACK_SIZE / PAGE_SIZE_4K;
    env.init->stack = test_process.thread.stack_top - CONFIG_SEL4UTILS_STACK_SIZE;
    env.init->page_directory = sel4utils_copy_cap_to_process(&test_process, &env.vka, test_process.pd.cptr);
    env.init->root_cnode = SEL4UTILS_CNODE_SLOT;
    env.init->tcb = sel4utils_copy_cap_to_process(&test_process, &env.vka, test_process.thread.tcb.cptr);
    env.init->domain = sel4utils_copy_cap_to_process(&test_process, &env.vka, simple_get_init_cap(&env.simple, seL4_CapDomain));
    env.init->asid_pool = sel4utils_copy_cap_to_process(&test_process, &env.vka, simple_get_init_cap(&env.simple, seL4_CapInitThreadASIDPool));
    env.init->asid_ctrl = sel4utils_copy_cap_to_process(&test_process, &env.vka, simple_get_init_cap(&env.simple, seL4_CapASIDControl));
#ifdef CONFIG_IOMMU
    env.init->io_space = sel4utils_copy_cap_to_process(&test_process, &env.vka, simple_get_init_cap(&env.simple, seL4_CapIOSpace));
#endif /* CONFIG_IOMMU */
#ifdef CONFIG_ARM_SMMU
    env.init->io_space_caps = arch_copy_iospace_caps_to_process(&test_process, &env);
#endif
    env.init->cores = simple_get_core_count(&env.simple);
    /* setup data about untypeds */
    env.init->untypeds = copy_untypeds_to_process(&test_process, untypeds, num_untypeds);
    copy_timer_caps(env.init, &env, &test_process);
    copy_serial_caps(env.init, &env, &test_process);
    /* copy the fault endpoint - we wait on the endpoint for a message
     * or a fault to see when the test finishes */
    seL4_CPtr endpoint = sel4utils_copy_cap_to_process(&test_process, &env.vka, test_process.fault_endpoint.cptr);

    /* WARNING: DO NOT COPY MORE CAPS TO THE PROCESS BEYOND THIS POINT,
     * AS THE SLOTS WILL BE CONSIDERED FREE AND OVERRIDDEN BY THE TEST PROCESS. */
    /* set up free slot range */
    env.init->cspace_size_bits = CONFIG_SEL4UTILS_CSPACE_SIZE_BITS;
    env.init->free_slots.start = endpoint + 1;
    env.init->free_slots.end = (1u << CONFIG_SEL4UTILS_CSPACE_SIZE_BITS);
    assert(env.init->free_slots.start < env.init->free_slots.end);
    /* copy test name */
    strncpy(env.init->name, test->name + strlen("TEST_"), TEST_NAME_MAX);
    /* ensure string is null terminated */
    env.init->name[TEST_NAME_MAX - 1] = '\0';
#ifdef CONFIG_DEBUG_BUILD
    seL4_DebugNameThread(test_process.thread.tcb.cptr, env.init->name);
#endif

    /* set up args for the test process */
    char endpoint_string[WORD_STRING_SIZE];
    char sel4test_name[] = { TESTS_APP };
    char *argv[] = {sel4test_name, endpoint_string};
    snprintf(endpoint_string, WORD_STRING_SIZE, "%lu", (unsigned long)endpoint);
    /* spawn the process */
    error = sel4utils_spawn_process_v(&test_process, &env.vka, &env.vspace,
                            ARRAY_SIZE(argv), argv, 1);
    assert(error == 0);

    /* send env.init_data to the new process */
    void *remote_vaddr = send_init_data(&env, test_process.fault_endpoint.cptr, &test_process);

    /* wait on it to finish or fault, report result */
    seL4_MessageInfo_t info = seL4_Recv(test_process.fault_endpoint.cptr, NULL);

    int result = seL4_GetMR(0);
    if (seL4_MessageInfo_get_label(info) != seL4_Fault_NullFault) {
        sel4utils_print_fault_message(info, test->name);
        sel4debug_dump_registers(test_process.thread.tcb.cptr);
        result = FAILURE;
    }

    /* unmap the env.init data frame */
    vspace_unmap_pages(&test_process.vspace, remote_vaddr, 1, PAGE_BITS_4K, NULL);

    /* reset all the untypeds for the next test */
    for (int i = 0; i < num_untypeds; i++) {
        cspacepath_t path;
        vka_cspace_make_path(&env.vka, untypeds[i].cptr, &path);
        vka_cnode_revoke(&path);
    }

    /* destroy the process */
    sel4utils_destroy_process(&test_process, &env.vka);

    test_assert(result == SUCCESS);
    return result;
}


/* Run a client process.
 * Modification based on run_    seL4_MessageInfo_t info = seL4_MessageInfo_new(seL4_Fault_NullFault, 0, 0, 1);
test() */
int
run_test_new(char *client_name)
{
    UNUSED int error;
    sel4utils_process_t test_process;

    /* Test intro banner. */
    printf("  %s\n", client_name);

    error = sel4utils_configure_process(&test_process, &env.vka, &env.vspace,
                                        env.init->priority, TESTS_APP);
    assert(error == 0);

    /* set up caps about the process */
    /* env.init->stack_pages = CONFIG_SEL4UTILS_STACK_SIZE / PAGE_SIZE_4K;
    env.init->stack = test_process.thread.stack_top - CONFIG_SEL4UTILS_STACK_SIZE;
    env.init->page_directory = sel4utils_copy_cap_to_process(&test_process, &env.vka, test_process.pd.cptr);
    env.init->root_cnode = SEL4UTILS_CNODE_SLOT;
    env.init->tcb = sel4utils_copy_cap_to_process(&test_process, &env.vka, test_process.thread.tcb.cptr);
    env.init->domain = sel4utils_copy_cap_to_process(&test_process, &env.vka, simple_get_init_cap(&env.simple, seL4_CapDomain));
    env.init->asid_pool = sel4utils_copy_cap_to_process(&test_process, &env.vka, simple_get_init_cap(&env.simple, seL4_CapInitThreadASIDPool));
    env.init->asid_ctrl = sel4utils_copy_cap_to_process(&test_process, &env.vka, simple_get_init_cap(&env.simple, seL4_CapASIDControl));
#ifdef CONFIG_IOMMU
    env.init->io_space = sel4utils_copy_cap_to_process(&test_process, &env.vka, simple_get_init_cap(&env.simple, seL4_CapIOSpace));
#endif *//* CONFIG_IOMMU */
/*#ifdef CONFIG_ARM_SMMU
    env.init->io_space_caps = arch_copy_iospace_caps_to_process(&test_process, &env);
#endif
    env.initthread_initial->cores = simple_get_core_count(&env.simple);
    *//* setup data about untypeds */
//    env.init->untypeds = copy_untypeds_to_process(&test_process, untypeds, num_untypeds);
//    copy_timer_caps(env.init, &env, &test_process);
//    copy_serial_caps(env.init, &env, &test_process);
    /* copy the fault endpoint - we wait on the endpoint for a message
     * or a fault to see when the test finishes */
    //seL4_CPtr endpoint = sel4utils_copy_cap_to_process(&test_process, &env.vka, env.client_cptr);

    cspacepath_t ep_cap_path;
    seL4_CPtr endpoint;
    vka_cspace_make_path(&env.vka, env.endpoint.cptr, &ep_cap_path);

    endpoint = sel4utils_mint_cap_to_process(&test_process, ep_cap_path, seL4_AllRights, seL4_CapData_Badge_new(0X61));
    printf("initial: %d %d\n", endpoint, env.endpoint.cptr);
    /* WARNING: DO NOT COPY MORE CAPS TO THE PROCESS BEYOND THIS POINT,
     * AS THE SLOTS WILL BE CONSIDERED FREE AND OVERRIDDEN BY THE TEST PROCESS. */
    /* set up free slot range */
    //env.init->cspace_size_bits = CONFIG_SEL4UTILS_CSPACE_SIZE_BITS;
    //env.init->free_slots.start = endpoint + 1;
    //env.init->free_slots.end = (1u << CONFIG_SEL4UTILS_CSPACE_SIZE_BITS);
    //assert(env.init->free_slots.start < env.init->free_slots.end);
    /* copy test name */
    //strncpy(env.init->name, client_name, TEST_NAME_MAX);
    /* ensure string is null terminated */
    //env.init->name[TEST_NAME_MAX - 1] = '\0';
//#ifdef CONFIG_DEBUG_BUILD
//    seL4_DebugNameThread(test_process.thread.tcb.cptr, env.init->name);
//#endif

    /* set up args for the test process */
    char endpoint_string[WORD_STRING_SIZE];
    char sel4test_name[] = { TESTS_APP };
    char *argv[] = {sel4test_name, endpoint_string};
    snprintf(endpoint_string, WORD_STRING_SIZE, "%lu", (unsigned long)endpoint);

    /* spawn the process */
    error = sel4utils_spawn_process_v(&test_process, &env.vka, &env.vspace,
                            ARRAY_SIZE(argv), argv, 1);
    assert(error == 0);

    /* send env.init_data to the new process */
    void *remote_vaddr = send_init_data(&env, test_process.fault_endpoint.cptr, &test_process);

    /* wait on it to finish or fault, report result */


    /* unmap the env.init data frame */
    vspace_unmap_pages(&test_process.vspace, remote_vaddr, 1, PAGE_BITS_4K, NULL);

    /* reset all the untypeds for the next test */
    for (int i = 0; i < num_untypeds; i++) {
        cspacepath_t path;
        vka_cspace_make_path(&env.vka, untypeds[i].cptr, &path);
        vka_cnode_revoke(&path);
    }

    /* destroy the process */
    //sel4utils_destroy_process(&test_process, &env.vka);

    //test_assert(result == SUCCESS);
    return SUCCESS;
}



/*
    if received initial data from all clients, multicast responses to all of them.
*/
void
process_message_multicast()
{
    int i;
    seL4_MessageInfo_t reply;

    for (i = 1;i < client_num;i ++) {
        seL4_SetMR(0, i);
        seL4_SetMR(1, 0);

        reply = seL4_MessageInfo_new(INIT, 0, 0, 2);
        seL4_Send(reply_eps[i], reply);
    }

    return;
}



// sel4utils_thread_t *
// sel4_thread_creation()
// {
//     int error;
//
//     /* created with seL4_Untyped_Retype() */
//     sel4utils_thread_t *tcb = malloc(sizeof(sel4utils_thread_t));
//     if (tcb == NULL) {
//         printf("Error: Cannot malloc a tcb.\n");
//         return NULL;
//     }
//
//     /* get cspace root cnode */
//     seL4_CPtr cspace_cap;
//     cspace_cap = simple_get_cnode(&env.simple);

    /* get vspace root page directory */
    // seL4_CPtr pd_cap;
    // pd_cap = simple_get_pd(&env.simple);

    // /* create a new TCB */
    // vka_object_t tcb_object = {0};
    // error = vka_alloc_tcb(&vka, &tcb_object);
    // if (error) {
    //     printf("Error: Failed to allocate new TCB.\n");
    //     return NULL;
    // }
    //
    // /* create and map an ipc buffer */
    // vka_object_t ipc_frame_object;
    //
    // error = vka_alloc_frame(&vka, IPCBUF_FRAME_SIZE_BITS, &ipc_frame_object);
    // if (error) {
    //     printf("Error: Failed to alloc a frame for the IPC buffer.\n");
    //     return NULL;
    // }

    // err = sel4utils_configure_thread(&_vka, &_vspace, &_vspace, seL4_CapNull, 253,
    		                    //  simple_get_cnode(&_simple), seL4_NilData, &thread);
    /* configure with seL4_TCB_Configure() */
//
//     return tcb;
// }
void *test_t1(void *arg)
{
    for (int i=0; i<10; i++) {
        int *p = malloc(20);
        free(p);
    }

    printf("ttttr\n");

    thread_exit();

    return arg;
}


void *test_t0(void *arg)
{
    for (int i=0; i<10; i++) {
        int *p = malloc(20);
        free(p);
    }
    printf("ttttr\n");
    // int t_id = thread_create(&env.vspace, test_t1, NULL);
    // thread_resume(t_id);

    thread_exit();

    return arg;
}


/*
    return if_defer;
*/
#ifdef GREEN_THREAD

#ifdef CONSUMER_PRODUCER
int
process_message(seL4_MessageInfo_t info, seL4_MessageInfo_t **reply, seL4_Word *reply_ep, void *sync_prim)
{
    int label = seL4_MessageInfo_get_label(info);
    seL4_MessageInfo_t temp;
    int client_id, error;
    int if_defer = 1;

    switch(label) {
        case INIT:

        client_id = initial_client();

        error = allocman_cspace_alloc(allocman, &pool->t_running->t->slot);
        assert(error == 0);

        /* check if OK to multi-cast */
        error = vka_cnode_saveCaller(&pool->t_running->t->slot);
        if (error != seL4_NoError) {
            printf("device_timer_save_caller_as_waiter failed to save caller.");
        }

        reply_eps[client_id] = (seL4_Word) pool->t_running->t->slot.offset;

        if (client_barrier()) {
            seL4_MessageInfo_t reply;

            seL4_SetMR(0, 0);
            seL4_SetMR(1, 1);

            reply = seL4_MessageInfo_new(INIT, 0, 0, 2);
            seL4_Send(reply_eps[0], reply);

            process_message_multicast();
        }

        return -1;
        break;

        case PRODUCER:
#ifdef BENCHMARK_ENTIRE
if (! started) {
    rdtsc_start();
    started = 1;
}
#endif
            /* save reply ep */
            // printf("RECV a producer: %d %d thread %d\n", seL4_GetMR(0), seL4_GetMR(1), pool->t_running->t->t_id);

#ifdef BENCHMARK_BREAKDOWN_BEFORE
rdtsc_start();
#endif
            error = vka_cnode_saveCaller(&pool->t_running->t->slot);
            if (error != seL4_NoError) {
                printf("device_timer_save_caller_as_waiter failed to save caller.");
            }
#ifdef BENCHMARK_BREAKDOWN_BEFORE
rdtsc_end();
printf("COLLECTION - before %llu %llu %llu\n", (end - start), start, end);
#endif
            thread_lock_acquire(lock_global);

            while (buffer == buffer_limit) {
                thread_lock_release(lock_global);

                thread_sleep(producer_list, NULL);
                wait_count ++;
                thread_lock_acquire(lock_global);
            }

            assert(buffer < buffer_limit);

            buffer ++;
            // printf("get one from producer!\n");
            // printf("buffer now: %d\n", buffer);

            thread_wakeup(consumer_list, NULL);

            thread_lock_release(lock_global);

#ifdef BENCHMARK_BREAKDOWN_IPC
rdtsc_start();
#endif

            temp = seL4_MessageInfo_new(PRODUCER, 0, 0, 1);
            *reply = &temp;

            return if_defer;
        break;

        case CONSUMER:
#ifdef BENCHMARK_ENTIRE
if (! started) {
    rdtsc_start();
    started = 1;
}
#endif
            // printf("RECV a consumer: %d %d thread %d\n", seL4_GetMR(0), seL4_GetMR(1), pool->t_running->t->t_id);

            /* save reply ep */
#ifdef BENCHMARK_BREAKDOWN_BEFORE
rdtsc_start();
#endif
            error = vka_cnode_saveCaller(&pool->t_running->t->slot);
            if (error != seL4_NoError) {
                printf("device_timer_save_caller_as_waiter failed to save caller.");
            }
#ifdef BENCHMARK_BREAKDOWN_BEFORE
rdtsc_end();
#endif
            thread_lock_acquire(lock_global);

            while (buffer == 0) {

                thread_lock_release(lock_global);
                thread_sleep(consumer_list, NULL);
                wait_count ++;
                thread_lock_acquire(lock_global);
            }

            assert(buffer > 0);
            buffer --;

            // printf("take one by consumer!\n");
            // printf("buffer now: %d\n", buffer);

            thread_wakeup(producer_list, NULL);

            thread_lock_release(lock_global);

#ifdef BENCHMARK_BREAKDOWN_IPC
rdtsc_start();
#endif

            temp = seL4_MessageInfo_new(CONSUMER, 0, 0, 1);
            *reply = &temp;

            return if_defer;
        break;

        case TMNT:

        client_id = seL4_GetMR(0);
        terminate_num ++;

#ifdef BENCHMARK_ENTIRE
if (terminate_num == client_num) {
    rdtsc_end();
    printf("COLLECTION - total time: %llu start: %llu end: %llu %d\n", (end - start), start, end, wait_count);
    thread_exit();
}
#endif

            temp = seL4_MessageInfo_new(TMNT, 0, 0, 1);
            *reply = &temp;

            thread_exit();
            return 1;
        break;

        case IMMD:
        printf("IMMD instruction\n");
        break;

    }

    return -1;
}

#else
int
process_message(seL4_MessageInfo_t info, seL4_MessageInfo_t **reply, seL4_Word *reply_ep, void *sync_prim)
{
    int label = seL4_MessageInfo_get_label(info);
    seL4_MessageInfo_t temp;
    int client_id, error;
    // cspacepath_t slot;


    switch(label) {
        case INIT:
        // thread_exit();

        client_id = initial_client();

        error = allocman_cspace_alloc(allocman, &pool->t_running->t->slot);
        assert(error == 0);

        /* check if OK to multi-cast */
        error = vka_cnode_saveCaller(&pool->t_running->t->slot);
        if (error != seL4_NoError) {
            printf("device_timer_save_caller_as_waiter failed to save caller.");
        }

        reply_eps[client_id] = (seL4_Word) pool->t_running->t->slot.offset;

        if (client_barrier()) {
            seL4_MessageInfo_t reply;

            seL4_SetMR(0, 0);
            seL4_SetMR(1, 1);

            reply = seL4_MessageInfo_new(INIT, 0, 0, 2);
            seL4_Send(reply_eps[0], reply);
        }

        return -1;
        break;

        case WAIT:

        client_id = seL4_GetMR(0);

        // printf("Receive wait from client %d 1\n", client_id);

        process_message_multicast();

        error = vka_cnode_saveCaller(&pool->t_running->t->slot);
        if (error != seL4_NoError) {
            printf("device_timer_save_caller_as_waiter failed to save caller.");
        }

        /* initial other clients */

#ifdef BENCHMARK_ENTIRE
printf("Start the calculator ---- \n");
start_total = rdtsc();
#endif

        /* acquire token */
#ifdef THREAD_LOCK
thread_lock_acquire(sync_prim);
#endif

#ifdef THREAD_SEMAPHORE
thread_semaphore_P(sync_prim);
#endif

#ifdef THREAD_CV
thread_cv_wait(sync_prim, lock_universe);
#endif
        // printf("Receive wait from client %d 2\n", client_id);

#ifdef BENCHMARK_BREAKDOWN
start = rdtsc();
#endif

        temp = seL4_MessageInfo_new(INIT, 0, 0, 1);
        *reply = &temp;

        return 1;

        break;

        case SEND_WAIT:

        client_id = seL4_GetMR(0);
        // seq = seL4_GetMR(1);

        /* get root cnode */
#ifdef BENCHMARK_BREAKDOWN_BEFORE
unsigned start_cycles_high, start_cycles_low, end_cycles_high, end_cycles_low;

asm volatile("CPUID\n\t"
"RDTSC\n\t"
"mov %%edx, %0\n\t"
"mov %%eax, %1\n\t" : "=r" (start_cycles_high), "=r" (start_cycles_low)
:: "%rax", "%rbx", "%rcx", "rdx");
#endif

        error = vka_cnode_saveCaller(&pool->t_running->t->slot);
        if (error != seL4_NoError) {
            printf("device_timer_save_caller_as_waiter failed to save caller.");
        }


#ifdef BENCHMARK_BREAKDOWN_BEFORE
asm volatile("RDTSCP\n\t"
"mov %%edx, %0\n\t"
"mov %%eax, %1\n\t"
"CPUID\n\t" : "=r" (end_cycles_high), "=r" (end_cycles_low)
:: "%rax", "%rbx", "%rcx", "rdx");

start = (((uint64_t) start_cycles_high << 32) | start_cycles_low);
end = (((uint64_t) end_cycles_high << 32) | end_cycles_low);

printf("COLLECTION - before %llu\n", (end - start));
#endif

        // printf("Receive send_wait from client %d - %d 1\n", client_id, seq);


#ifdef THREAD_LOCK
#ifdef BENCHMARK_BREAKDOWN_MID

asm volatile("CPUID\n\t"
"RDTSC\n\t"
"mov %%edx, %0\n\t"
"mov %%eax, %1\n\t" : "=r" (start_cycles_high), "=r" (start_cycles_low)
:: "%rax", "%rbx", "%rcx", "rdx");
#endif
        // thread_lock_release(sync_prim);
        // thread_lock_acquire(sync_prim);
        thread_lock_release_acquire(sync_prim);

#ifdef BENCHMARK_BREAKDOWN_MID
asm volatile("RDTSCP\n\t"
"mov %%edx, %0\n\t"
"mov %%eax, %1\n\t"
"CPUID\n\t" : "=r" (end_cycles_high), "=r" (end_cycles_low)
:: "%rax", "%rbx", "%rcx", "rdx");

start = (((uint64_t) start_cycles_high << 32) | start_cycles_low);
end = (((uint64_t) end_cycles_high << 32) | end_cycles_low);
printf("COLLECTION - mid %llu %llu %llu %d\n", (end - start), start, end, pool->t_running->t->t_id);
#endif
#endif

#ifdef THREAD_SEMAPHORE
#ifdef BENCHMARK_BREAKDOWN
start = rdtsc();
#endif
            thread_semaphore_V(sync_prim);
            thread_semaphore_P(sync_prim);
#ifdef BENCHMARK_BREAKDOWN
end = rdtsc();
printf("COLLECTION - mid %llu\n", (end - start));
#endif
#endif

#ifdef THREAD_CV
#ifdef BENCHMARK_BREAKDOWN
start = rdtsc();
#endif
            thread_cv_signal(sync_prim);
            thread_cv_wait(sync_prim, lock_universe);
#ifdef BENCHMARK_BREAKDOWN
end = rdtsc();
printf("COLLECTION - mid %llu\n", (end - start));
#endif
#endif

        // printf("Receive send_wait from client %d - %d 2\n", client_id, seq);
#ifdef BENCHMARK_BREAKDOWN_IPC
start = rdtsc();
#endif

        temp = seL4_MessageInfo_new(INIT, 0, 0, 1);
        *reply = &temp;

            return 1;
        break;

        case TMNT:

        client_id = seL4_GetMR(0);
        terminate_num ++;
#ifdef BENCHMARK_ENTIRE
if (terminate_num == client_count) {
    rdtsc_end();
    printf("COLLECTION - total time: %llu start: %llu end: %llu\n", (end_total - start_total), start_total, end_total);
}
#endif
        thread_exit();
        break;

        case IMMD:
        printf("IMMD instruction\n");
        break;

    }

    return -1;
}

#endif




void *
server_loop(void *sync_prim)
{
    // thread_pool_info();

    seL4_MessageInfo_t info = seL4_Recv(env.endpoint.cptr, NULL);

    seL4_MessageInfo_t *reply = NULL;
    seL4_Word reply_ep;
    int res;

    while (1) {

        /* if_reply */
        res = process_message(info, &reply, &reply_ep, sync_prim);
        if (res == 1) {
            seL4_Send(pool->t_running->t->slot.offset, *reply);
            #ifdef BENCHMARK_BREAKDOWN_IPC
            rdtsc_end();
            printf("COLLECTION - ipc: %llu %llu %llu\n", (end - start), start, end);
            #endif
            info = seL4_Recv(env.endpoint.cptr, NULL);
        } else if (res == 0) {

            assert(reply != NULL);
            info = seL4_ReplyRecv(env.endpoint.cptr, *reply, NULL);
        } else {
            info = seL4_Recv(env.endpoint.cptr, NULL);
        }
    }

    return sync_prim;
}
#endif



#ifdef SEL4_THREAD

#ifdef CONSUMER_PRODUCER

seL4_Word
process_message(seL4_MessageInfo_t info, cspacepath_t *slot, seL4_MessageInfo_t **reply, void *sync_prim, void *lock)
{
    int label = seL4_MessageInfo_get_label(info);
    seL4_MessageInfo_t temp;
    int client_id, error;

    switch(label) {
        case INIT:
            client_id = initial_client();

            cspacepath_t slot_temp;

            error = allocman_cspace_alloc(allocman, &slot_temp);
            assert(error == 0);

            /* check if OK to multi-cast */
            error = vka_cnode_saveCaller(&slot_temp);
            if (error != seL4_NoError) {
                printf("device_timer_save_caller_as_waiter failed to save caller.");
            }

            reply_eps[client_id] = (seL4_Word) slot_temp.offset;

            if (client_barrier()) {
                seL4_MessageInfo_t reply;

                seL4_SetMR(0, 0);
                seL4_SetMR(1, 1);

                reply = seL4_MessageInfo_new(INIT, 0, 0, 2);
                seL4_Send(reply_eps[0], reply);
                process_message_multicast();
            }


            return 0;
            break;

            case PRODUCER:
#ifdef BENCHMARK_ENTIRE
if (! started) {
    printf("First producer\n");
    rdtsc_start();
    started = 1;
}
#endif
            // printf("RECV a producer: %d %d\n", seL4_GetMR(0), seL4_GetMR(1));

#ifdef SEL4_GREEN
#ifdef BENCHMARK_BREAKDOWN_BEFORE
unsigned sc_start_high, sc_start_low, sc_end_high, sc_end_low;
uint64_t sc_start, sc_end;

asm volatile("CPUID\n\t"
            "RDTSC\n\t"
            "mov %%edx, %0\n\t"
            "mov %%eax, %1\n\t" : "=r" (sc_start_high), "=r" (sc_start_low)
            :: "%rax", "%rbx", "%rcx", "rdx");
#endif

            error = vka_cnode_saveCaller(slot);
            if (error != seL4_NoError) {
                printf("device_timer_save_caller_as_waiter failed to save caller.");
            }
            // printf("Should not match\n");

#ifdef BENCHMARK_BREAKDOWN_BEFORE
asm volatile("RDTSCP\n\t"
            "mov %%edx, %0\n\t"
            "mov %%eax, %1\n\t"
            "CPUID\n\t" : "=r" (sc_end_high), "=r" (sc_end_low)
            :: "%rax", "%rbx", "%rcx", "rdx");

sc_start = (((uint64_t) sc_start_high << 32) | sc_start_low);
sc_end = (((uint64_t) sc_end_high << 32) | sc_end_low);
// printf("COLLECTION - before %llu\n", (end - start));
before[before_cur ++] = sc_end - sc_start;
#endif
#endif

            sync_mutex_lock(&lock_global);

            while (buffer == buffer_limit) {
                sync_mutex_unlock(&lock_global);
                seL4_Wait(producer_list, NULL);
                wait_count ++;
                sync_mutex_lock(&lock_global);
            }

            assert(buffer < buffer_limit);

            buffer ++;
            // printf("get one from producer!\n");
            // printf("buffer now: %d\n", buffer);

            seL4_Signal(consumer_list);

            sync_mutex_unlock(&lock_global);

#ifdef BENCHMARK_BREAKDOWN_IPC
rdtsc_start();
#endif

            temp = seL4_MessageInfo_new(PRODUCER, 0, 0, 1);
            *reply = &temp;

            return 1;
        break;

        case CONSUMER:
#ifdef BENCHMARK_ENTIRE
if (! started) {
    printf("first consumer!\n");
    rdtsc_start();
    started = 1;
}
#endif

#ifdef SEL4_GREEN
#ifdef BENCHMARK_BREAKDOWN_BEFORE
unsigned sc_start_high1, sc_start_low1, sc_end_high1, sc_end_low1;
uint64_t sc_start1, sc_end1;

asm volatile("CPUID\n\t"
            "RDTSC\n\t"
            "mov %%edx, %0\n\t"
            "mov %%eax, %1\n\t" : "=r" (sc_start_high1), "=r" (sc_start_low1)
            :: "%rax", "%rbx", "%rcx", "rdx");
#endif

            error = vka_cnode_saveCaller(slot);
            if (error != seL4_NoError) {
                printf("device_timer_save_caller_as_waiter failed to save caller.");
            }

#ifdef BENCHMARK_BREAKDOWN_BEFORE
asm volatile("RDTSCP\n\t"
            "mov %%edx, %0\n\t"
            "mov %%eax, %1\n\t"
            "CPUID\n\t" : "=r" (sc_end_high1), "=r" (sc_end_low1)
            :: "%rax", "%rbx", "%rcx", "rdx");

sc_start1 = (((uint64_t) sc_start_high1 << 32) | sc_start_low1);
sc_end1 = (((uint64_t) sc_end_high1 << 32) | sc_end_low1);
// printf("COLLECTION - before %llu\n", (end - start));
before[before_cur ++] = sc_end1 - sc_start1;
#endif
#endif

            sync_mutex_lock(&lock_global);

            while (buffer == 0) {
                sync_mutex_unlock(&lock_global);

                seL4_Wait(consumer_list, NULL);
                wait_count ++;
                sync_mutex_lock(&lock_global);
            }

            assert(buffer > 0);
            buffer --;

            // printf("take one by consumer!\n");
            // printf("buffer now: %d\n", buffer);


            seL4_Signal(producer_list);

            sync_mutex_unlock(&lock_global);

#ifdef BENCHMARK_BREAKDOWN_IPC
rdtsc_start();
#endif

            temp = seL4_MessageInfo_new(CONSUMER, 0, 0, 1);
            *reply = &temp;

            return 1;
        break;


        case TMNT:

        client_id = seL4_GetMR(0);
        // printf("Client %d terminates\n", client_id);

        terminate_num ++;

        if (terminate_num == client_num) {
#ifdef BENCHMARK_ENTIRE
            rdtsc_end();
            printf("COLLECTION - total time %llu %llu %llu %d\n", (end - start), start, end, wait_count);
#endif
            // printf("end of test\n");
        }

        break;

        case IMMD:
        printf("IMMD instruction\n");
        break;

    }

    return 0;
}

#else

seL4_Word
process_message(seL4_MessageInfo_t info, seL4_MessageInfo_t **reply, void *sync_prim, void *lock)
{
    int label = seL4_MessageInfo_get_label(info);
    seL4_MessageInfo_t temp;
    int client_id, error;
    cspacepath_t slot;

    switch(label) {
        case INIT:
        client_id = initial_client();

        /* check if OK to multi-cast */
        error = allocman_cspace_alloc(allocman, &slot);
        assert(error == 0);

        error = vka_cnode_saveCaller(&slot);
        if (error != seL4_NoError) {
            printf("device_timer_save_caller_as_waiter failed to save caller.");
        }

        reply_eps[client_id] = (seL4_Word) slot.offset;

        if (client_barrier()) {
            seL4_MessageInfo_t reply;

            seL4_SetMR(0, 0);
            seL4_SetMR(1, 1);

            reply = seL4_MessageInfo_new(INIT, 0, 0, 2);
            seL4_Send(reply_eps[0], reply);
        }

        return 0;
        break;

        case WAIT:

        client_id = seL4_GetMR(0);

#ifdef SEL4_GREEN
        process_message_multicast();

        error = allocman_cspace_alloc(allocman, &slot);
        assert(error == 0);

        error = vka_cnode_saveCaller(&slot);
        if (error != seL4_NoError) {
            printf("device_timer_save_caller_as_waiter failed to save caller.");
        }
#endif

        // printf("Receive wait from client %d 1\n", client_id);

        /* other clients */

#ifdef BENCHMARK_ENTIRE
printf("Start the calculator ---- \n");
start_total = rdtsc();
#endif
        /* acquire token */
#ifdef THREAD_LOCK
        sync_mutex_lock((sync_mutex_t *) sync_prim);
#endif

#ifdef THREAD_SEMAPHORE
        sync_sem_wait((sync_sem_t *) sync_prim);
#endif

#ifdef THREAD_CV
        sync_cv_wait((sync_bin_sem_t *) lock, (sync_cv_t *) sync_prim);
#endif

        // printf("Receive wait from client %d 2\n", client_id);
#ifdef BENCHMARK_BREAKDOWN_IPC
rdtsc_end();
#endif
        temp = seL4_MessageInfo_new(INIT, 0, 0, 1);
        *reply = &temp;

#ifdef SEL4_GREEN
        return (seL4_Word) slot.offset;
#else
        return 1;
#endif



        break;

        case SEND_WAIT:
        // exit(0);

        client_id = seL4_GetMR(0);
        // seq = seL4_GetMR(1);

#ifdef SEL4_GREEN
#ifdef BENCHMARK_BREAKDOWN
start = rdtsc();
#endif
        error = allocman_cspace_alloc(allocman, &slot);
        assert(error == 0);

        error = vka_cnode_saveCaller(&slot);
        if (error != seL4_NoError) {
            printf("device_timer_save_caller_as_waiter failed to save caller.");
        }

        global_reply_ep = (seL4_Word) slot.offset;
#ifdef BENCHMARK_BREAKDOWN
end =rdtsc();
printf("COLLECTION - save cap %llu %llu %llu\n", (end - start), start, end);
#endif
#endif

        // printf("Receive send_wait from client %d - %d 1\n", client_id, seq);

#ifdef THREAD_LOCK
#ifdef BENCHMARK_BREAKDOWN
start = rdtsc();
#endif
        sync_mutex_unlock((sync_mutex_t *) sync_prim);
        sync_mutex_lock((sync_mutex_t *) sync_prim);
#ifdef BENCHMARK_BREAKDOWN
end = rdtsc();
printf("COLLECTION - mid %llu\n", (end - start));
#endif
#endif

#ifdef THREAD_SEMAPHORE
#ifdef BENCHMARK_BREAKDOWN
start = rdtsc();
#endif

        sync_sem_post((sync_sem_t *) sync_prim);
        sync_sem_wait((sync_sem_t *) sync_prim);
#ifdef BENCHMARK_BREAKDOWN
end = rdtsc();
printf("COLLECTION - mid %llu\n", (end - start));
#endif
#endif

#ifdef THREAD_CV
#ifdef BENCHMARK_BREAKDOWN
start = rdtsc();
#endif
        sync_cv_signal((sync_cv_t *) sync_prim);
        sync_cv_wait((sync_bin_sem_t *) lock, (sync_cv_t *) sync_prim);
#ifdef BENCHMARK_BREAKDOWN
end = rdtsc();
printf("COLLECTION - mid %llu\n", (end - start));
#endif
#endif

        // printf("Receive send_wait from client %d - %d 2\n", client_id, seq);
#ifdef BENCHMARK_BREAKDOWN_IPC
rdtsc_start();
#endif

        temp = seL4_MessageInfo_new(INIT, 0, 0, 1);
        *reply = &temp;

#ifdef SEL4_GREEN
        return (seL4_Word) slot.offset;
#else
        return 1;
#endif
        break;

        case TMNT:

        client_id = seL4_GetMR(0);
        // printf("Client %d terminates\n", client_id);

        terminate_num ++;

#ifdef BENCHMARK_ENTIRE
if (terminate_num == client_count) {
    end_total = rdtsc();
    printf("COLLECTION - total time: %llu start: %llu end: %llu\n", (end_total - start_total), start_total, end_total);
}
#endif

        break;

        case IMMD:
        printf("IMMD instruction\n");
        break;

    }

    return 0;
}

#endif



void
server_loop(void *sync_prim, void *lock)
{
    assert(sync_prim != NULL);

    seL4_MessageInfo_t *reply = NULL;
    int res;

    seL4_MessageInfo_t info = seL4_Recv(env.endpoint.cptr, NULL);

    cspacepath_t slot;
    int error;

    error = allocman_cspace_alloc(allocman, &slot);
    assert(error == 0);


    while (1) {
        res = process_message(info, &slot, &reply, sync_prim, lock);

        if (res) {

#ifdef SEL4_GREEN
            seL4_Send(slot.offset, *reply);
            info = seL4_Recv(env.endpoint.cptr, NULL);
#ifdef BENCHMARK_BREAKDOWN_IPC
rdtsc_end();
ipc[ipc_cur ++] = end - start;
#endif
#endif

#ifdef SEL4_SLOW
            seL4_Reply(*reply);
            info = seL4_Recv(env.endpoint.cptr, NULL);
#ifdef BENCHMARK_BREAKDOWN_IPC
rdtsc_end();
printf("COLLECTION - slowpath: %llu %llu %llu\n", (end - start), start, end);
#endif
#endif

#ifdef SEL4_FAST
            info = seL4_ReplyRecv(env.endpoint.cptr, *reply, NULL);
#ifdef BENCHMARK_BREAKDOWN_IPC
rdtsc_end();
// printf("COLLECTION - fastpath: %llu\n", (end - start));
ipc[ipc_cur ++] = end - start;
#endif
#endif
        } else {
            info = seL4_Recv(env.endpoint.cptr, NULL);
        }

    }

    return;
}



int
sel4_threads_initial(int num)
{
    void *lock = NULL;
    sel4utils_thread_t *tcb;
    seL4_CPtr cspace_cap;
    int i, error;

    /* initial sel4 thread environment */
    sel4_thread_initial();

#ifdef THREAD_LOCK
    /* initial mutex */
    sync_mutex_t sync_prim;
    seL4_CPtr notification;
    notification = vka_alloc_notification_leaky(&env.vka);
    sync_mutex_init(&sync_prim, notification);

    sync_mutex_lock(&sync_prim);
#endif

#ifdef THREAD_SEMAPHORE
    sync_sem_t sync_prim;
    sync_sem_new(&env.vka, &sync_prim, 0);
#endif

#ifdef THREAD_CV
    sync_cv_t sync_prim;
    sync_bin_sem_t bin_sem;
    sync_bin_sem_new(&env.vka, &bin_sem, 1);
    sync_cv_new(&env.vka, &sync_prim);
    lock = &bin_sem;
#endif

#ifdef CONSUMER_PRODUCER
    notification = vka_alloc_notification_leaky(&env.vka);
    producer_list = vka_alloc_notification_leaky(&env.vka);
    consumer_list = vka_alloc_notification_leaky(&env.vka);
    sync_mutex_init(&lock_global, notification);
#endif

    cspace_cap = simple_get_cnode(&env.simple);

    for (i = 0;i < num;i ++) {

        tcb = malloc(sizeof(sel4utils_thread_t));
        if (tcb == NULL) {
            printf("Cannot allocate a new sel4 thread.\n");
            return 0;
        }

        error = sel4utils_configure_thread(&env.vka, &env.vspace, &env.vspace, seL4_CapNull,
                                       seL4_MaxPrio, cspace_cap, seL4_NilData, tcb);
        assert(! error);

        error = sel4utils_start_thread(tcb, (sel4utils_thread_entry_fn) server_loop, (void *) &sync_prim, lock, 1);
        assert(! error);

        sel4_thread_new(i, tcb);
    }

    return 1;
}
#endif



void *
test_func(void *arg1)
{
    printf("Great!\n");

    thread_exit();

    return arg1;
}



// #ifdef SEL4_THREAD
// int
// sel4_thread_start(sel4utils_thread_t *thread, void *sync_prim)
// {
//     int error;
//
//     /* Resume with seL4_TCB_Resume */
//     printf("%p\n", (void *) env.endpoint.cptr);
//     error = sel4utils_start_thread(thread, (sel4utils_thread_entry_fn) server_loop, sync_prim, NULL, 0);
//     if (error) {
//         return 0;
//     }
//
//     return 1;
// }
// #endif



/*
    Encapsulate.
*/
#ifdef GREEN_THREAD
int
thread_creation(void *sync_prim, int num)
{
    assert(num > 0);
    int i, res = 0;

    for (i = 0;i < num;i ++)
        res = thread_create(allocman, &env.vspace, server_loop, sync_prim);

    return res;
}
#endif


void *main_continued(void *arg UNUSED)
{

    /* elf region data */
    int num_elf_regions;
    sel4utils_elf_region_t elf_regions[MAX_REGIONS];

    /* Print welcome banner. */
    printf("\n");
    printf("seL4 Test\n");
    printf("=========\n");
    printf("\n");

    /* allocate lots of untyped memory for tests to use */
    num_untypeds = populate_untypeds(untypeds);

    /* create a frame that will act as the init data, we can then map that
     * in to target processes */
    env.init = (test_init_data_t *) vspace_new_pages(&env.vspace, seL4_AllRights, 1, PAGE_BITS_4K);
    assert(env.init != NULL);

    /* copy the cap to map into the remote process */
    cspacepath_t src, dest;
    vka_cspace_make_path(&env.vka, vspace_get_cap(&env.vspace, env.init), &src);


    UNUSED int error = vka_cspace_alloc(&env.vka, &env.init_frame_cap_copy);
    assert(error == 0);
    vka_cspace_make_path(&env.vka, env.init_frame_cap_copy, &dest);
    error = vka_cnode_copy(&dest, &src, seL4_AllRights);
    assert(error == 0);

    /* copy the untyped size bits list across to the init frame */
    memcpy(env.init->untyped_size_bits_list, untyped_size_bits_list, sizeof(uint8_t) * num_untypeds);

    /* parse elf region data about the test image to pass to the tests app */
    num_elf_regions = sel4utils_elf_num_regions(TESTS_APP);
    assert(num_elf_regions < MAX_REGIONS);
    sel4utils_elf_reserve(NULL, TESTS_APP, elf_regions);

    /* copy the region list for the process to clone itself */
    memcpy(env.init->elf_regions, elf_regions, sizeof(sel4utils_elf_region_t) * num_elf_regions);
    env.init->num_elf_regions = num_elf_regions;

    /* setup init data that won't change test-to-test */
    env.init->priority = seL4_MaxPrio;
    plat_init(&env);

    /* now run the tests */
    //sel4test_run_tests("sel4test", run_test);
    sel4test_run_tests_new("sel4test", run_test_new);


    client_count = 6;
printf("start\n");
#ifdef GREEN_THREAD
    thread_initial();
    initial_client_pool(client_count);



    //
    // sel4bench_init();
    //
    // ccnt_t num = sel4bench_get_cycle_count();
    // printf("cycle count: %llu.\n", num);
    // exit(0);
    // pool->thread_creation = thread_creation;


#ifdef THREAD_LOCK
    thread_lock_t *sync_prim = thread_lock_create();
    assert(sync_prim != NULL);
    sync_prim->held = 1;
#endif

#ifdef THREAD_SEMAPHORE
    thread_semaphore_t *sync_prim = thread_semaphore_create();
    assert(sync_prim != NULL);
#endif

#ifdef THREAD_CV
    int token;
    int *sync_prim = &token;
#endif

    int t_id = thread_creation((void *) sync_prim, client_count);
    thread_resume(t_id);

    printf("end of test\n");

#endif // -- GREEN_THREAD

#ifdef SEL4_THREAD


    /* initial clients pool */
    initial_client_pool(client_count);

    sel4_threads_initial(client_count);

    printf("print out result: \n");

#ifdef BENCHMARK_BREAKDOWN_BEFORE
    for (int i = 0;i < 2000;i ++)
        printf("COLLECTION - before %llu\n", before[i]);
#endif

#ifdef BENCHMARK_BREAKDOWN_IPC
    for (int i = 0;i < 2000;i ++)
        printf("COLLECTION - ipc %llu\n", ipc[i]);
#endif

    printf("end of test\n");

    // int res = seL4_TCB_Resume(thread.tcb.cptr);
    // printf("RESULT CAN BE SHOWN: %d.\n", res);

#endif // -- SEL4_THREAD

    // server_loop(NULL);
    // while (1) {
    //     printf("TESTTT\n");
    // }

    /* Qianrui Zhao thesis */
    //run_test_new("client 01");

    return NULL;
}


void *
cannot_believe(void *arg)
{
    printf("CHAN\n");
    printf("CHECK CHECK\n");

    thread_self();

    thread_exit();

    return arg;
}




int main(void)
{
    int error;
    seL4_BootInfo *info = platsupport_get_bootinfo();

#ifdef CONFIG_DEBUG_BUILD
    seL4_DebugNameThread(seL4_CapInitThreadTCB, "sel4test-driver");
#endif

    compile_time_assert(init_data_fits_in_ipc_buffer, sizeof(test_init_data_t) < PAGE_SIZE_4K);
    /* initialise libsel4simple, which abstracts away which kernel version
     * we are running on */
    simple_default_init_bootinfo(&env.simple, info);

    /* initialise the test environment - allocator, cspace manager, vspace
     * manager, timer
     */
    init_env(&env);

    /* Allocate slots for, and obtain the caps for, the hardware we will be
     * using, in the same function.
     */
    sel4platsupport_init_default_serial_caps(&env.vka, &env.vspace, &env.simple, &env.serial_objects);

    /* Construct a vka wrapper for returning the serial frame. We need to
     * create this wrapper as the actual vka implementation will only
     * allocate/return any given device frame once. As we already allocated it
     * in init_serial_caps when we the platsupport_serial_setup_simple attempts
     * to allocate it will fail. This wrapper just returns a copy of the one
     * we already allocated, whilst passing all other requests on to the
     * actual vka
     */
    vka_t serial_vka = env.vka;
    serial_vka.utspace_alloc_at = arch_get_serial_utspace_alloc_at(&env);

    /* enable serial driver */
    platsupport_serial_setup_simple(&env.vspace, &env.simple, &serial_vka);

    /* init_timer_caps calls acpi_init(), which does unconditional printfs,
     * so it can't go before platsupport_serial_setup_simple().
    */
    error = sel4platsupport_init_default_timer_caps(&env.vka, &env.vspace, &env.simple, &env.timer_objects);
    ZF_LOGF_IF(error, "Failed to init default timer caps");
    simple_print(&env.simple);

    /* switch to a bigger, safer stack with a guard page
     * before starting the tests */
    printf("Switching to a safer, bigger stack... ");
    fflush(stdout);

    /* test thread library */
    // thread_initial();
    // if (pool != NULL)
    //     printf("Create a pool.\n");
    //
    // void *arg = NULL;
    // printf("What..");
    // printf("New thread id: %d\n", thread_create(&env.vspace, test_func, arg));
    // printf("New thread id: %d\n", thread_create(&env.vspace, cannot_believe, arg));
    // printf("New thread id: %d\n", thread_create(&env.vspace, cannot_believe, arg));
    // thread_pool_info();
    // thread_info(1);
    // thread_yield();
    //
    // thread_pool_info();
    //
    // printf("end\n");
    /* test thread library end */

    /* Get execution time for kernel context-switching */
    // uint64_t save_start, save_end, restore_start, restore_end;
    // uint32_t save_elapsed, restore_elapsed;
    //
    // for (int i = 0;i < 1050;i ++) {
    //
    // save_start = rdtsc();
    // seL4_SetMR(0, 0xDEADBEEF);
    // seL4_DebugHalt();
    // save_end = seL4_GetMR(5);
    // save_end <<= 32;
    // save_end |= seL4_GetMR(6);
    //
    // save_elapsed = save_end - save_start;
    //
    // restore_start = seL4_GetMR(3);
    // restore_start <<= 32;
    // restore_start |= seL4_GetMR(4);
    // restore_end = rdtsc();
    //
    // restore_elapsed = restore_end - restore_start;
    //
    // printf("%d\n", i);
    //
    // printf("COLLECTION - Got RDTSC values: save %u, restore %u.\n"
    //         "COLLECTION - \tSave: start %u_%u, end %u_%u.\n"
    //         "COLLECTION - \tEnd: start %u_%u, end %u_%u.\n",
    //         save_elapsed, restore_elapsed,
    //         (uint32_t)((save_start >> 32) & UINT32_MAX),
    //         (uint32_t)((save_start) & UINT32_MAX),
    //         (uint32_t)((save_end >> 32) & UINT32_MAX),
    //         (uint32_t)((save_end) & UINT32_MAX),
    //         (uint32_t)((restore_start >> 32) & UINT32_MAX),
    //         (uint32_t)((restore_start) & UINT32_MAX),
    //         (uint32_t)((restore_end >> 32) & UINT32_MAX),
    //         (uint32_t)((restore_end) & UINT32_MAX));
    // }


    void *res;
    error = sel4utils_run_on_stack(&env.vspace, main_continued, NULL, &res);
    test_assert_fatal(error == 0);
    test_assert_fatal(res == 0);

    return 0;
}
