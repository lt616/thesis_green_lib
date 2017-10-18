
/*
 * Automatically generated system call stubs.
 */

#ifndef __LIBSEL4_SEL4_CLIENT_H
#define __LIBSEL4_SEL4_CLIENT_H

#include <autoconf.h>
#include <sel4/types.h>

/*
 * The following code generates a compile-time error if the system call
 * stub generator has an incorrect understanding of how large a type is.
 *
 * If you receive a compile-time error here, you will need to adjust
 * the type information in the stub generator.
 */
#define assert_size_correct(type, expected_bytes) \
        typedef unsigned long __type_##type##_size_incorrect[ \
                (sizeof(type) == expected_bytes) ? 1 : -1]

assert_size_correct(int, 4);
assert_size_correct(long, 4);
assert_size_correct(seL4_Uint8, 1);
assert_size_correct(seL4_Uint16, 2);
assert_size_correct(seL4_Uint32, 4);
assert_size_correct(seL4_Uint64, 8);
assert_size_correct(seL4_Word, 4);
assert_size_correct(seL4_Bool, 1);
assert_size_correct(seL4_CapData_t, 4);
assert_size_correct(seL4_PrioProps_t, 4);
assert_size_correct(seL4_CapRights_t, 4);
assert_size_correct(seL4_CPtr, 4);
assert_size_correct(seL4_CNode, 4);
assert_size_correct(seL4_IRQHandler, 4);
assert_size_correct(seL4_IRQControl, 4);
assert_size_correct(seL4_TCB, 4);
assert_size_correct(seL4_Untyped, 4);
assert_size_correct(seL4_DomainSet, 4);
assert_size_correct(seL4_X86_VMAttributes, 4);
assert_size_correct(seL4_X86_IOPort, 4);
assert_size_correct(seL4_X86_ASIDControl, 4);
assert_size_correct(seL4_X86_ASIDPool, 4);
assert_size_correct(seL4_X86_IOSpace, 4);
assert_size_correct(seL4_X86_Page, 4);
assert_size_correct(seL4_X86_PageDirectory, 4);
assert_size_correct(seL4_X86_PageTable, 4);
assert_size_correct(seL4_X86_IOPageTable, 4);
assert_size_correct(seL4_X86_VCPU, 4);
assert_size_correct(seL4_X86_EPTPML4, 4);
assert_size_correct(seL4_X86_EPTPDPT, 4);
assert_size_correct(seL4_X86_EPTPD, 4);
assert_size_correct(seL4_X86_EPTPT, 4);
assert_size_correct(seL4_VCPUContext, 28);
assert_size_correct(seL4_UserContext, 52);

/*
 * Return types for generated methods.
 */
struct seL4_X86_PageDirectory_GetStatusBits {
	int error;
	seL4_Word accessed;
	seL4_Word dirty;
};
typedef struct seL4_X86_PageDirectory_GetStatusBits seL4_X86_PageDirectory_GetStatusBits_t;

struct seL4_X86_Page_GetAddress {
	int error;
	seL4_Word paddr;
};
typedef struct seL4_X86_Page_GetAddress seL4_X86_Page_GetAddress_t;

struct seL4_X86_IOPort_In8 {
	int error;
	seL4_Uint8 result;
};
typedef struct seL4_X86_IOPort_In8 seL4_X86_IOPort_In8_t;

struct seL4_X86_IOPort_In16 {
	int error;
	seL4_Uint16 result;
};
typedef struct seL4_X86_IOPort_In16 seL4_X86_IOPort_In16_t;

struct seL4_X86_IOPort_In32 {
	int error;
	seL4_Uint32 result;
};
typedef struct seL4_X86_IOPort_In32 seL4_X86_IOPort_In32_t;

struct seL4_X86_VCPU_ReadVMCS {
	int error;
	seL4_Word value;
};
typedef struct seL4_X86_VCPU_ReadVMCS seL4_X86_VCPU_ReadVMCS_t;

struct seL4_X86_VCPU_WriteVMCS {
	int error;
	seL4_Word written;
};
typedef struct seL4_X86_VCPU_WriteVMCS seL4_X86_VCPU_WriteVMCS_t;

struct seL4_TCB_GetBreakpoint {
	int error;
	seL4_Word vaddr;
	seL4_Word type;
	seL4_Word size;
	seL4_Word rw;
	seL4_Bool is_enabled;
};
typedef struct seL4_TCB_GetBreakpoint seL4_TCB_GetBreakpoint_t;

struct seL4_TCB_ConfigureSingleStepping {
	int error;
	seL4_Bool bp_was_consumed;
};
typedef struct seL4_TCB_ConfigureSingleStepping seL4_TCB_ConfigureSingleStepping_t;

/*
 * Generated stubs.
 */
/**
 * @xmlonly <manual name="Page Directory - Map" label="x86_page_directory_map"/> @endxmlonly
 * @param[in] _service Capability to the page directory being operated on
 * @param[in] vroot  
 * @param[in] vaddr  
 * @param[in] attr  
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 */
LIBSEL4_INLINE long
seL4_X86_PageDirectory_Map(seL4_X86_PageDirectory _service, seL4_CPtr vroot, seL4_Word vaddr, seL4_X86_VMAttributes attr)
{
	long result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(X86PageDirectoryMap, 0, 1, 2);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;

	/* Setup input capabilities. */
	seL4_SetCap(0, vroot);

	/* Marshal and initialise parameters. */
	mr0 = vaddr;
	mr1 = attr;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1);
	result = seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
	}

	return result;
}

/**
 * @xmlonly <manual name="Page Directory - Unmap" label="x86_page_directory_unmap"/> @endxmlonly
 * @param[in] _service Capability to the page directory being operated on
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 */
LIBSEL4_INLINE long
seL4_X86_PageDirectory_Unmap(seL4_X86_PageDirectory _service)
{
	long result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(X86PageDirectoryUnmap, 0, 0, 0);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;

	/* Marshal and initialise parameters. */
	mr0 = 0;
	mr1 = 0;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1);
	result = seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
	}

	return result;
}

/**
 * @xmlonly <manual name="Page Directory - Get Status Bits" label="x86_page_directory_get_status_bits"/> @endxmlonly
 * @param[in] _service Capability to the page directory being operated on
 * @param[in] vaddr  
 * @return @xmlonly @endxmlonly
 */
LIBSEL4_INLINE seL4_X86_PageDirectory_GetStatusBits_t
seL4_X86_PageDirectory_GetStatusBits(seL4_X86_PageDirectory _service, seL4_Word vaddr)
{
	seL4_X86_PageDirectory_GetStatusBits_t result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(X86PageDirectoryGetStatusBits, 0, 0, 1);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;

	/* Marshal and initialise parameters. */
	mr0 = vaddr;
	mr1 = 0;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1);
	result.error = seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result.error != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
		return result;
	}

	/* Unmarshal result. */
	result.accessed = mr0;
	result.dirty = mr1;
	return result;
}

/**
 * @xmlonly <manual name="Page Table - Map" label="x86_pagetable_map"/> @endxmlonly
 * @param[in] _service 
 * @param[in] vroot  
 * @param[in] vaddr  
 * @param[in] attr  
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 */
LIBSEL4_INLINE long
seL4_X86_PageTable_Map(seL4_X86_PageTable _service, seL4_CPtr vroot, seL4_Word vaddr, seL4_X86_VMAttributes attr)
{
	long result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(X86PageTableMap, 0, 1, 2);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;

	/* Setup input capabilities. */
	seL4_SetCap(0, vroot);

	/* Marshal and initialise parameters. */
	mr0 = vaddr;
	mr1 = attr;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1);
	result = seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
	}

	return result;
}

/**
 * @xmlonly <manual name="Page Table - Unmap" label="x86_pagetable_unmap"/> @endxmlonly
 * @param[in] _service 
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 */
LIBSEL4_INLINE long
seL4_X86_PageTable_Unmap(seL4_X86_PageTable _service)
{
	long result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(X86PageTableUnmap, 0, 0, 0);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;

	/* Marshal and initialise parameters. */
	mr0 = 0;
	mr1 = 0;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1);
	result = seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
	}

	return result;
}

/**
 * @xmlonly <manual name="I/O Page Table - Map" label="x86_io_page_table_map"/> @endxmlonly
 * @param[in] _service 
 * @param[in] iospace  
 * @param[in] ioaddr  
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 */
LIBSEL4_INLINE long
seL4_X86_IOPageTable_Map(seL4_X86_IOPageTable _service, seL4_X86_IOSpace iospace, seL4_Word ioaddr)
{
	long result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(X86IOPageTableMap, 0, 1, 1);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;

	/* Setup input capabilities. */
	seL4_SetCap(0, iospace);

	/* Marshal and initialise parameters. */
	mr0 = ioaddr;
	mr1 = 0;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1);
	result = seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
	}

	return result;
}

/**
 * @xmlonly <manual name="I/O Page Table - Unmap" label="x86_io_page_table_unmap"/> @endxmlonly
 * @param[in] _service 
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 */
LIBSEL4_INLINE long
seL4_X86_IOPageTable_Unmap(seL4_X86_IOPageTable _service)
{
	long result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(X86IOPageTableUnmap, 0, 0, 0);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;

	/* Marshal and initialise parameters. */
	mr0 = 0;
	mr1 = 0;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1);
	result = seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
	}

	return result;
}

/**
 * @xmlonly <manual name="Page - Map" label="x86_page_map"/> @endxmlonly
 * @param[in] _service 
 * @param[in] vroot  
 * @param[in] vaddr  
 * @param[in] rights  
 * @param[in] attr  
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 */
LIBSEL4_INLINE long
seL4_X86_Page_Map(seL4_X86_Page _service, seL4_CPtr vroot, seL4_Word vaddr, seL4_CapRights_t rights, seL4_X86_VMAttributes attr)
{
	long result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(X86PageMap, 0, 1, 3);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;

	/* Setup input capabilities. */
	seL4_SetCap(0, vroot);

	/* Marshal and initialise parameters. */
	mr0 = vaddr;
	mr1 = rights.words[0];
	seL4_SetMR(2, attr);

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1);
	result = seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
	}

	return result;
}

/**
 * @xmlonly <manual name="Page - Remap" label="x86_page_remap"/> @endxmlonly
 * @param[in] _service 
 * @param[in] vroot  
 * @param[in] rights  
 * @param[in] attr  
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 */
LIBSEL4_INLINE long
seL4_X86_Page_Remap(seL4_X86_Page _service, seL4_CPtr vroot, seL4_CapRights_t rights, seL4_X86_VMAttributes attr)
{
	long result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(X86PageRemap, 0, 1, 2);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;

	/* Setup input capabilities. */
	seL4_SetCap(0, vroot);

	/* Marshal and initialise parameters. */
	mr0 = rights.words[0];
	mr1 = attr;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1);
	result = seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
	}

	return result;
}

/**
 * @xmlonly <manual name="Page - Unmap" label="x86_page_unmap"/> @endxmlonly
 * @param[in] _service 
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 */
LIBSEL4_INLINE long
seL4_X86_Page_Unmap(seL4_X86_Page _service)
{
	long result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(X86PageUnmap, 0, 0, 0);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;

	/* Marshal and initialise parameters. */
	mr0 = 0;
	mr1 = 0;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1);
	result = seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
	}

	return result;
}

/**
 * @xmlonly <manual name="Page - Map I/O" label="x86_page_map_io"/> @endxmlonly
 * @param[in] _service 
 * @param[in] iospace  
 * @param[in] rights  
 * @param[in] ioaddr  
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 */
LIBSEL4_INLINE long
seL4_X86_Page_MapIO(seL4_X86_Page _service, seL4_X86_IOSpace iospace, seL4_CapRights_t rights, seL4_Word ioaddr)
{
	long result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(X86PageMapIO, 0, 1, 2);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;

	/* Setup input capabilities. */
	seL4_SetCap(0, iospace);

	/* Marshal and initialise parameters. */
	mr0 = rights.words[0];
	mr1 = ioaddr;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1);
	result = seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
	}

	return result;
}

/**
 * @xmlonly <manual name="Page - Get Address" label="x86_page_get_address"/> @endxmlonly
 * @param[in] _service 
 * @return @xmlonly @endxmlonly
 */
LIBSEL4_INLINE seL4_X86_Page_GetAddress_t
seL4_X86_Page_GetAddress(seL4_X86_Page _service)
{
	seL4_X86_Page_GetAddress_t result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(X86PageGetAddress, 0, 0, 0);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;

	/* Marshal and initialise parameters. */
	mr0 = 0;
	mr1 = 0;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1);
	result.error = seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result.error != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
		return result;
	}

	/* Unmarshal result. */
	result.paddr = mr0;
	return result;
}

#if defined(CONFIG_VTX)
/**
 * @xmlonly <manual name="Page - Map EPT" label="x86_page_map_ept"/> @endxmlonly
 * @param[in] _service 
 * @param[in] vroot  
 * @param[in] vaddr  
 * @param[in] rights  
 * @param[in] attr  
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 */
LIBSEL4_INLINE long
seL4_X86_Page_MapEPT(seL4_X86_Page _service, seL4_X86_EPTPML4 vroot, seL4_Word vaddr, seL4_CapRights_t rights, seL4_X86_VMAttributes attr)
{
	long result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(X86PageMapEPT, 0, 1, 3);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;

	/* Setup input capabilities. */
	seL4_SetCap(0, vroot);

	/* Marshal and initialise parameters. */
	mr0 = vaddr;
	mr1 = rights.words[0];
	seL4_SetMR(2, attr);

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1);
	result = seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
	}

	return result;
}

#endif
/**
 * @xmlonly <manual name="ASID Control - Make Pool" label="x86_asid_control_make_pool"/> @endxmlonly
 * @param[in] _service 
 * @param[in] untyped  
 * @param[in] root  
 * @param[in] index  
 * @param[in] depth  
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 */
LIBSEL4_INLINE long
seL4_X86_ASIDControl_MakePool(seL4_X86_ASIDControl _service, seL4_Untyped untyped, seL4_CNode root, seL4_Word index, seL4_Uint8 depth)
{
	long result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(X86ASIDControlMakePool, 0, 2, 2);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;

	/* Setup input capabilities. */
	seL4_SetCap(0, untyped);
	seL4_SetCap(1, root);

	/* Marshal and initialise parameters. */
	mr0 = index;
	mr1 = (depth & 0xfful);

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1);
	result = seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
	}

	return result;
}

/**
 * @xmlonly <manual name="ASID Pool - Assign" label="x86_asidpool_assign"/> @endxmlonly
 * @param[in] _service 
 * @param[in] vroot  
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 */
LIBSEL4_INLINE long
seL4_X86_ASIDPool_Assign(seL4_X86_ASIDPool _service, seL4_CPtr vroot)
{
	long result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(X86ASIDPoolAssign, 0, 1, 0);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;

	/* Setup input capabilities. */
	seL4_SetCap(0, vroot);

	/* Marshal and initialise parameters. */
	mr0 = 0;
	mr1 = 0;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1);
	result = seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
	}

	return result;
}

/**
 * @xmlonly <manual name="I/O Port - In8" label="x86_io_port_in8"/> @endxmlonly
 * @param[in] _service 
 * @param[in] port  
 * @return @xmlonly @endxmlonly
 */
LIBSEL4_INLINE seL4_X86_IOPort_In8_t
seL4_X86_IOPort_In8(seL4_X86_IOPort _service, seL4_Uint16 port)
{
	seL4_X86_IOPort_In8_t result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(X86IOPortIn8, 0, 0, 1);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;

	/* Marshal and initialise parameters. */
	mr0 = (port & 0xfffful);
	mr1 = 0;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1);
	result.error = seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result.error != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
		return result;
	}

	/* Unmarshal result. */
	result.result = (mr0 & 0xff);
	return result;
}

/**
 * @xmlonly <manual name="I/O Port - In16" label="x86_io_port_in16"/> @endxmlonly
 * @param[in] _service 
 * @param[in] port  
 * @return @xmlonly @endxmlonly
 */
LIBSEL4_INLINE seL4_X86_IOPort_In16_t
seL4_X86_IOPort_In16(seL4_X86_IOPort _service, seL4_Uint16 port)
{
	seL4_X86_IOPort_In16_t result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(X86IOPortIn16, 0, 0, 1);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;

	/* Marshal and initialise parameters. */
	mr0 = (port & 0xfffful);
	mr1 = 0;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1);
	result.error = seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result.error != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
		return result;
	}

	/* Unmarshal result. */
	result.result = (mr0 & 0xffff);
	return result;
}

/**
 * @xmlonly <manual name="I/O Port - In32" label="x86_io_port_in32"/> @endxmlonly
 * @param[in] _service 
 * @param[in] port  
 * @return @xmlonly @endxmlonly
 */
LIBSEL4_INLINE seL4_X86_IOPort_In32_t
seL4_X86_IOPort_In32(seL4_X86_IOPort _service, seL4_Uint16 port)
{
	seL4_X86_IOPort_In32_t result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(X86IOPortIn32, 0, 0, 1);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;

	/* Marshal and initialise parameters. */
	mr0 = (port & 0xfffful);
	mr1 = 0;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1);
	result.error = seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result.error != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
		return result;
	}

	/* Unmarshal result. */
	result.result = mr0;
	return result;
}

/**
 * @xmlonly <manual name="I/O Port - Out8" label="x86_io_port_out8"/> @endxmlonly
 * @param[in] _service 
 * @param[in] port  
 * @param[in] data  
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 */
LIBSEL4_INLINE long
seL4_X86_IOPort_Out8(seL4_X86_IOPort _service, seL4_Word port, seL4_Word data)
{
	long result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(X86IOPortOut8, 0, 0, 2);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;

	/* Marshal and initialise parameters. */
	mr0 = port;
	mr1 = data;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1);
	result = seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
	}

	return result;
}

/**
 * @xmlonly <manual name="I/O Port - Out16" label="x86_io_port_out16"/> @endxmlonly
 * @param[in] _service 
 * @param[in] port  
 * @param[in] data  
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 */
LIBSEL4_INLINE long
seL4_X86_IOPort_Out16(seL4_X86_IOPort _service, seL4_Word port, seL4_Word data)
{
	long result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(X86IOPortOut16, 0, 0, 2);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;

	/* Marshal and initialise parameters. */
	mr0 = port;
	mr1 = data;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1);
	result = seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
	}

	return result;
}

/**
 * @xmlonly <manual name="I/O Port - Out32" label="x86_io_port_out32"/> @endxmlonly
 * @param[in] _service 
 * @param[in] port  
 * @param[in] data  
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 */
LIBSEL4_INLINE long
seL4_X86_IOPort_Out32(seL4_X86_IOPort _service, seL4_Word port, seL4_Word data)
{
	long result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(X86IOPortOut32, 0, 0, 2);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;

	/* Marshal and initialise parameters. */
	mr0 = port;
	mr1 = data;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1);
	result = seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
	}

	return result;
}

/**
 * @xmlonly <manual name="IRQ Control - Get I/O APIC" label="x86_irq_control_get_io_apic"/> @endxmlonly
 * @param[in] _service 
 * @param[in] root  
 * @param[in] index  
 * @param[in] depth  
 * @param[in] ioapic  
 * @param[in] pin  
 * @param[in] level  
 * @param[in] polarity  
 * @param[in] vector  
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 */
LIBSEL4_INLINE long
seL4_IRQControl_GetIOAPIC(seL4_IRQControl _service, seL4_CNode root, seL4_Word index, seL4_Word depth, seL4_Word ioapic, seL4_Word pin, seL4_Word level, seL4_Word polarity, seL4_Word vector)
{
	long result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(X86IRQIssueIRQHandlerIOAPIC, 0, 1, 7);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;

	/* Setup input capabilities. */
	seL4_SetCap(0, root);

	/* Marshal and initialise parameters. */
	mr0 = index;
	mr1 = depth;
	seL4_SetMR(2, ioapic);
	seL4_SetMR(3, pin);
	seL4_SetMR(4, level);
	seL4_SetMR(5, polarity);
	seL4_SetMR(6, vector);

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1);
	result = seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
	}

	return result;
}

/**
 * @xmlonly <manual name="IRQ Control - Get MSI" label="x86_irq_control_get_msi"/> @endxmlonly
 * @param[in] _service 
 * @param[in] root  
 * @param[in] index  
 * @param[in] depth  
 * @param[in] pci_bus  
 * @param[in] pci_dev  
 * @param[in] pci_func  
 * @param[in] handle  
 * @param[in] vector  
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 */
LIBSEL4_INLINE long
seL4_IRQControl_GetMSI(seL4_IRQControl _service, seL4_CNode root, seL4_Word index, seL4_Word depth, seL4_Word pci_bus, seL4_Word pci_dev, seL4_Word pci_func, seL4_Word handle, seL4_Word vector)
{
	long result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(X86IRQIssueIRQHandlerMSI, 0, 1, 7);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;

	/* Setup input capabilities. */
	seL4_SetCap(0, root);

	/* Marshal and initialise parameters. */
	mr0 = index;
	mr1 = depth;
	seL4_SetMR(2, pci_bus);
	seL4_SetMR(3, pci_dev);
	seL4_SetMR(4, pci_func);
	seL4_SetMR(5, handle);
	seL4_SetMR(6, vector);

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1);
	result = seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
	}

	return result;
}

#if defined(CONFIG_VTX)
/**
 * @xmlonly <manual name="TCB - Set EPT Root" label="x86_tcb_set_ept_root"/> @endxmlonly
 * @param[in] _service 
 * @param[in] vcpu  
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 */
LIBSEL4_INLINE long
seL4_TCB_SetEPTRoot(seL4_TCB _service, seL4_CPtr vcpu)
{
	long result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(TCBSetEPTRoot, 0, 1, 0);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;

	/* Setup input capabilities. */
	seL4_SetCap(0, vcpu);

	/* Marshal and initialise parameters. */
	mr0 = 0;
	mr1 = 0;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1);
	result = seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
	}

	return result;
}

#endif
#if defined(CONFIG_VTX)
/**
 * @xmlonly <manual name="VCPU - Set TCB" label="x86_vcpu_set_tcb"/> @endxmlonly
 * @param[in] _service 
 * @param[in] tcb  
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 */
LIBSEL4_INLINE long
seL4_X86_VCPU_SetTCB(seL4_X86_VCPU _service, seL4_CNode tcb)
{
	long result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(X86VCPUSetTCB, 0, 1, 0);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;

	/* Setup input capabilities. */
	seL4_SetCap(0, tcb);

	/* Marshal and initialise parameters. */
	mr0 = 0;
	mr1 = 0;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1);
	result = seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
	}

	return result;
}

#endif
#if defined(CONFIG_VTX)
/**
 * @xmlonly <manual name="VCPU - Read VMCS" label="x86_vcpu_read_vmcs"/> @endxmlonly
 * @param[in] _service 
 * @param[in] field  
 * @return @xmlonly @endxmlonly
 */
LIBSEL4_INLINE seL4_X86_VCPU_ReadVMCS_t
seL4_X86_VCPU_ReadVMCS(seL4_X86_VCPU _service, seL4_Word field)
{
	seL4_X86_VCPU_ReadVMCS_t result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(X86VCPUReadVMCS, 0, 0, 1);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;

	/* Marshal and initialise parameters. */
	mr0 = field;
	mr1 = 0;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1);
	result.error = seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result.error != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
		return result;
	}

	/* Unmarshal result. */
	result.value = mr0;
	return result;
}

#endif
#if defined(CONFIG_VTX)
/**
 * @xmlonly <manual name="VCPU - Write VMCS" label="x86_vcpu_write_vmcs"/> @endxmlonly
 * @param[in] _service 
 * @param[in] field  
 * @param[in] value  
 * @return @xmlonly @endxmlonly
 */
LIBSEL4_INLINE seL4_X86_VCPU_WriteVMCS_t
seL4_X86_VCPU_WriteVMCS(seL4_X86_VCPU _service, seL4_Word field, seL4_Word value)
{
	seL4_X86_VCPU_WriteVMCS_t result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(X86VCPUWriteVMCS, 0, 0, 2);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;

	/* Marshal and initialise parameters. */
	mr0 = field;
	mr1 = value;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1);
	result.error = seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result.error != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
		return result;
	}

	/* Unmarshal result. */
	result.written = mr0;
	return result;
}

#endif
#if defined(CONFIG_VTX)
/**
 * @xmlonly <manual name="VCPU - Enable IO Port" label="x86_vcpu_enable_io_port"/> @endxmlonly
 * @param[in] _service 
 * @param[in] ioPort  
 * @param[in] low  
 * @param[in] high  
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 */
LIBSEL4_INLINE long
seL4_X86_VCPU_EnableIOPort(seL4_X86_VCPU _service, seL4_CNode ioPort, seL4_Word low, seL4_Word high)
{
	long result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(X86VCPUEnableIOPort, 0, 1, 2);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;

	/* Setup input capabilities. */
	seL4_SetCap(0, ioPort);

	/* Marshal and initialise parameters. */
	mr0 = low;
	mr1 = high;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1);
	result = seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
	}

	return result;
}

#endif
#if defined(CONFIG_VTX)
/**
 * @xmlonly <manual name="VCPU - Disable IO Port" label="x86_vcpu_disable_io_port"/> @endxmlonly
 * @param[in] _service 
 * @param[in] low  
 * @param[in] high  
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 */
LIBSEL4_INLINE long
seL4_X86_VCPU_DisableIOPort(seL4_X86_VCPU _service, seL4_Word low, seL4_Word high)
{
	long result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(X86VCPUDisableIOPort, 0, 0, 2);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;

	/* Marshal and initialise parameters. */
	mr0 = low;
	mr1 = high;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1);
	result = seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
	}

	return result;
}

#endif
#if defined(CONFIG_VTX)
/**
 * @xmlonly <manual name="VCPU - Write Registers" label="x86_vcpu_write_registers"/> @endxmlonly
 * @param[in] _service 
 * @param[in] regs  
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 */
LIBSEL4_INLINE long
seL4_X86_VCPU_WriteRegisters(seL4_X86_VCPU _service, seL4_VCPUContext *regs)
{
	long result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(X86VCPUWriteRegisters, 0, 0, 7);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;

	/* Marshal and initialise parameters. */
	mr0 = regs->eax;
	mr1 = regs->ebx;
	seL4_SetMR(2, regs->ecx);
	seL4_SetMR(3, regs->edx);
	seL4_SetMR(4, regs->esi);
	seL4_SetMR(5, regs->edi);
	seL4_SetMR(6, regs->ebp);

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1);
	result = seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
	}

	return result;
}

#endif
#if defined(CONFIG_VTX)
/**
 * @xmlonly <manual name="Extended Page Table Page Directory Page Table - Map" label="x86_extended_page_table_page_directory_page_table_map"/> @endxmlonly
 * @param[in] _service 
 * @param[in] pml4  
 * @param[in] gpa  
 * @param[in] attr  
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 */
LIBSEL4_INLINE long
seL4_X86_EPTPDPT_Map(seL4_X86_EPTPDPT _service, seL4_X86_EPTPML4 pml4, seL4_Word gpa, seL4_X86_VMAttributes attr)
{
	long result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(X86EPTPDPTMap, 0, 1, 2);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;

	/* Setup input capabilities. */
	seL4_SetCap(0, pml4);

	/* Marshal and initialise parameters. */
	mr0 = gpa;
	mr1 = attr;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1);
	result = seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
	}

	return result;
}

#endif
#if defined(CONFIG_VTX)
/**
 * @xmlonly <manual name="Extended Page Table Page Directory Page Table - Unmap" label="x86_extended_page_table_page_directory_page_table_unmap"/> @endxmlonly
 * @param[in] _service 
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 */
LIBSEL4_INLINE long
seL4_X86_EPTPDPT_Unmap(seL4_X86_EPTPDPT _service)
{
	long result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(X86EPTPDPTUnmap, 0, 0, 0);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;

	/* Marshal and initialise parameters. */
	mr0 = 0;
	mr1 = 0;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1);
	result = seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
	}

	return result;
}

#endif
#if defined(CONFIG_VTX)
/**
 * @xmlonly <manual name="Extended Page Table Page Directory - Map" label="x86_extended_page_table_page_directory_map"/> @endxmlonly
 * @param[in] _service 
 * @param[in] pml4  
 * @param[in] gpa  
 * @param[in] attr  
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 */
LIBSEL4_INLINE long
seL4_X86_EPTPD_Map(seL4_X86_EPTPD _service, seL4_X86_EPTPML4 pml4, seL4_Word gpa, seL4_X86_VMAttributes attr)
{
	long result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(X86EPTPDMap, 0, 1, 2);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;

	/* Setup input capabilities. */
	seL4_SetCap(0, pml4);

	/* Marshal and initialise parameters. */
	mr0 = gpa;
	mr1 = attr;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1);
	result = seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
	}

	return result;
}

#endif
#if defined(CONFIG_VTX)
/**
 * @xmlonly <manual name="Extended Page Table Page Directory - Unmap" label="x86_extended_page_table_page_directory_unmap"/> @endxmlonly
 * @param[in] _service 
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 */
LIBSEL4_INLINE long
seL4_X86_EPTPD_Unmap(seL4_X86_EPTPD _service)
{
	long result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(X86EPTPDUnmap, 0, 0, 0);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;

	/* Marshal and initialise parameters. */
	mr0 = 0;
	mr1 = 0;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1);
	result = seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
	}

	return result;
}

#endif
#if defined(CONFIG_VTX)
/**
 * @xmlonly <manual name="Extended Page Table Page Table - Map" label="x86_extended_page_table_page_table_map"/> @endxmlonly
 * @param[in] _service 
 * @param[in] pml4  
 * @param[in] gpa  
 * @param[in] attr  
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 */
LIBSEL4_INLINE long
seL4_X86_EPTPT_Map(seL4_X86_EPTPT _service, seL4_X86_EPTPML4 pml4, seL4_Word gpa, seL4_X86_VMAttributes attr)
{
	long result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(X86EPTPTMap, 0, 1, 2);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;

	/* Setup input capabilities. */
	seL4_SetCap(0, pml4);

	/* Marshal and initialise parameters. */
	mr0 = gpa;
	mr1 = attr;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1);
	result = seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
	}

	return result;
}

#endif
#if defined(CONFIG_VTX)
/**
 * @xmlonly <manual name="Extended Page Table Page Table - Unmap" label="x86_extended_page_table_page_table_unmap"/> @endxmlonly
 * @param[in] _service 
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 */
LIBSEL4_INLINE long
seL4_X86_EPTPT_Unmap(seL4_X86_EPTPT _service)
{
	long result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(X86EPTPTUnmap, 0, 0, 0);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;

	/* Marshal and initialise parameters. */
	mr0 = 0;
	mr1 = 0;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1);
	result = seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
	}

	return result;
}

#endif
/**
 * @xmlonly <manual name="Untyped - Retype" label="untyped_retype"/> @endxmlonly
 * @brief @xmlonly Retype an untyped object @endxmlonly
 * 
 * @xmlonly
 * Given a capability, <texttt text="_service"/>, to an untyped object,
 * creates <texttt text="num_objects"/> of the requested type. Creates
 * <texttt text="num_objects"/> capabilities to the new objects starting
 * at <texttt text="node_offset"/> in the CNode specified by
 * <texttt text="root"/>, <texttt text="node_index"/>, and
 * <texttt text="node_depth"/>.
 * 
 * For variable-sized
 * kernel objects, the <texttt text="size_bits"/> argument is used to
 * determine the size of objects to create. The relationship between
 * <texttt text="size_bits"/> and object size depends on the type of object
 * being created. See <autoref sec="object_sizes"/> for more information
 * about object sizes.
 * 
 * See <autoref sec="kernmemalloc"/> for more information about how untyped
 * memory is retyped.
 * 
 * See <autoref sec="caps_to_new_objects"/> for more information about the
 * placement of capabilities to created objects.
 * @endxmlonly
 * 
 * @param[in] _service CPTR to an untyped object.
 * @param[in] type The seL4 object type that we are retyping to. 
 * @param[in] size_bits Used to determine the size of variable-sized objects. 
 * @param[in] root CPTR to the CNode at the root of the destination CSpace. 
 * @param[in] node_index CPTR to the destination CNode. Resolved relative to the root parameter. 
 * @param[in] node_depth Number of bits of node_index to translate when addressing the destination CNode. 
 * @param[in] node_offset Number of slots into the node at which capabilities start being placed. 
 * @param[in] num_objects Number of capabilities to create. 
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 */
LIBSEL4_INLINE long
seL4_Untyped_Retype(seL4_Untyped _service, seL4_Word type, seL4_Word size_bits, seL4_CNode root, seL4_Word node_index, seL4_Word node_depth, seL4_Word node_offset, seL4_Word num_objects)
{
	long result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(UntypedRetype, 0, 1, 6);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;

	/* Setup input capabilities. */
	seL4_SetCap(0, root);

	/* Marshal and initialise parameters. */
	mr0 = type;
	mr1 = size_bits;
	seL4_SetMR(2, node_index);
	seL4_SetMR(3, node_depth);
	seL4_SetMR(4, node_offset);
	seL4_SetMR(5, num_objects);

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1);
	result = seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
	}

	return result;
}

/**
 * @xmlonly <manual name="TCB - Read Registers" label="tcb_readregisters"/> @endxmlonly
 * @brief @xmlonly Read a thread's registers into the first <texttt text="count"/> fields of a given
 * seL4_UserContext @endxmlonly
 * 
 * @xmlonly
 * See <autoref sec="read_write_registers"/>
 * @endxmlonly
 * 
 * @param[in] _service Capability to the TCB which is being operated on.
 * @param[in] suspend_source The invocation should also suspend the source thread. 
 * @param[in] arch_flags Architecture dependent flags. These have no mearing on either x86 or ARM. 
 * @param[in] count The number of registers to read. 
 * @param[out] regs The structure to read the registers into. 
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 */
LIBSEL4_INLINE long
seL4_TCB_ReadRegisters(seL4_TCB _service, seL4_Bool suspend_source, seL4_Uint8 arch_flags, seL4_Word count, seL4_UserContext *regs)
{
	long result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(TCBReadRegisters, 0, 0, 2);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;

	/* Marshal and initialise parameters. */
	mr0 = (suspend_source & 0x1ul) | ((arch_flags & 0xfful) << 8);
	mr1 = count;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1);
	result = seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
	}

	/* Unmarshal result. */
	regs->eip = mr0;
	regs->esp = mr1;
	regs->eflags = seL4_GetMR(2);
	regs->eax = seL4_GetMR(3);
	regs->ebx = seL4_GetMR(4);
	regs->ecx = seL4_GetMR(5);
	regs->edx = seL4_GetMR(6);
	regs->esi = seL4_GetMR(7);
	regs->edi = seL4_GetMR(8);
	regs->ebp = seL4_GetMR(9);
	regs->tls_base = seL4_GetMR(10);
	regs->fs = seL4_GetMR(11);
	regs->gs = seL4_GetMR(12);
	return result;
}

/**
 * @xmlonly <manual name="TCB - Write Registers" label="tcb_writeregisters"/> @endxmlonly
 * @brief @xmlonly Set a thread's registers to the first <texttt text="count"/> fields of a given seL4_UserContext @endxmlonly
 * 
 * @xmlonly
 * See <autoref sec="read_write_registers"/>
 * @endxmlonly
 * 
 * @param[in] _service Capability to the TCB which is being operated on.
 * @param[in] resume_target The invocation should also resume the destination thread. 
 * @param[in] arch_flags Architecture dependent flags. These have no mearing on either x86 or ARM. 
 * @param[in] count The number of registers to be set. 
 * @param[in] regs Data structure containing the new register values. 
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 */
LIBSEL4_INLINE long
seL4_TCB_WriteRegisters(seL4_TCB _service, seL4_Bool resume_target, seL4_Uint8 arch_flags, seL4_Word count, seL4_UserContext *regs)
{
	long result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(TCBWriteRegisters, 0, 0, 15);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;

	/* Marshal and initialise parameters. */
	mr0 = (resume_target & 0x1ul) | ((arch_flags & 0xfful) << 8);
	mr1 = count;
	seL4_SetMR(2, regs->eip);
	seL4_SetMR(3, regs->esp);
	seL4_SetMR(4, regs->eflags);
	seL4_SetMR(5, regs->eax);
	seL4_SetMR(6, regs->ebx);
	seL4_SetMR(7, regs->ecx);
	seL4_SetMR(8, regs->edx);
	seL4_SetMR(9, regs->esi);
	seL4_SetMR(10, regs->edi);
	seL4_SetMR(11, regs->ebp);
	seL4_SetMR(12, regs->tls_base);
	seL4_SetMR(13, regs->fs);
	seL4_SetMR(14, regs->gs);

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1);
	result = seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
	}

	return result;
}

/**
 * @xmlonly <manual name="TCB - Copy Registers" label="tcb_copyregisters"/> @endxmlonly
 * @brief @xmlonly Copy the registers from one thread to another @endxmlonly
 * 
 * @xmlonly
 * In the context of this function, frame registers are those that are read, modified or preserved by a
 * system call and integer registers are those that are not. Refer to the seL4 userland library source for specifics.
 * <autoref sec="thread_deactivation"/>
 * @endxmlonly
 * 
 * @param[in] _service Capability to the TCB which is being operated on. This is the destination TCB.
 * @param[in] source Cap to the source TCB. 
 * @param[in] suspend_source The invocation should also suspend the source thread. 
 * @param[in] resume_target The invocation should also resume the destination thread. 
 * @param[in] transfer_frame Frame registers should be transferred. 
 * @param[in] transfer_integer Integer registers should be transferred. 
 * @param[in] arch_flags Architecture dependent flags. These have no mearing on either x86 or ARM. 
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 */
LIBSEL4_INLINE long
seL4_TCB_CopyRegisters(seL4_TCB _service, seL4_TCB source, seL4_Bool suspend_source, seL4_Bool resume_target, seL4_Bool transfer_frame, seL4_Bool transfer_integer, seL4_Uint8 arch_flags)
{
	long result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(TCBCopyRegisters, 0, 1, 1);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;

	/* Setup input capabilities. */
	seL4_SetCap(0, source);

	/* Marshal and initialise parameters. */
	mr0 = (suspend_source & 0x1ul) | ((resume_target & 0x1ul) << 1) | ((transfer_frame & 0x1ul) << 2) | ((transfer_integer & 0x1ul) << 3) | ((arch_flags & 0xfful) << 8);
	mr1 = 0;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1);
	result = seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
	}

	return result;
}

/**
 * @xmlonly <manual name="TCB - Configure" label="tcb_configure"/> @endxmlonly
 * @brief @xmlonly Set the parameters of a TCB @endxmlonly
 * 
 * @xmlonly
 * See <autoref sec="threads"/>
 * @endxmlonly
 * 
 * @param[in] _service Capability to the TCB which is being operated on.
 * @param[in] fault_ep CPTR to the endpoint which receives IPCs when this thread faults. This capability is in the CSpace of the thread being configured. 
 * @param[in] priority The thread's new priority properties: the maximum control priority and priority. 
 * @param[in] cspace_root The new CSpace root. 
 * @param[in] cspace_root_data Optionally set the guard and guard size of the new root CNode. If set to zero, this parameter has no effect. 
 * @param[in] vspace_root The new VSpace root. 
 * @param[in] vspace_root_data Has no effect on x86 or ARM processors. 
 * @param[in] buffer Location of the thread's IPC buffer. Must be 512-byte aligned. The IPC buffer may not cross a page boundary. 
 * @param[in] bufferFrame Capability to a page containing the thread's IPC buffer. 
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 */
LIBSEL4_INLINE long
seL4_TCB_Configure(seL4_TCB _service, seL4_Word fault_ep, seL4_PrioProps_t priority, seL4_CNode cspace_root, seL4_CapData_t cspace_root_data, seL4_CNode vspace_root, seL4_CapData_t vspace_root_data, seL4_Word buffer, seL4_CPtr bufferFrame)
{
	long result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(TCBConfigure, 0, 3, 5);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;

	/* Setup input capabilities. */
	seL4_SetCap(0, cspace_root);
	seL4_SetCap(1, vspace_root);
	seL4_SetCap(2, bufferFrame);

	/* Marshal and initialise parameters. */
	mr0 = fault_ep;
	mr1 = priority.words[0];
	seL4_SetMR(2, cspace_root_data.words[0]);
	seL4_SetMR(3, vspace_root_data.words[0]);
	seL4_SetMR(4, buffer);

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1);
	result = seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
	}

	return result;
}

/**
 * @xmlonly <manual name="TCB - Set Priority" label="tcb_setpriority"/> @endxmlonly
 * @brief @xmlonly Change a thread's priority @endxmlonly
 * 
 * @xmlonly
 * See <autoref sec="sched"/>
 * @endxmlonly
 * 
 * @param[in] _service Capability to the TCB which is being operated on.
 * @param[in] priority The thread's new priority. 
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 */
LIBSEL4_INLINE long
seL4_TCB_SetPriority(seL4_TCB _service, seL4_Uint8 priority)
{
	long result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(TCBSetPriority, 0, 0, 1);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;

	/* Marshal and initialise parameters. */
	mr0 = (priority & 0xfful);
	mr1 = 0;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1);
	result = seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
	}

	return result;
}

/**
 * @xmlonly <manual name="TCB - Set Maximum Controlled Priority" label="tcb_setmcpriority"/> @endxmlonly
 * @brief @xmlonly Change a thread's maximum controlled priority @endxmlonly
 * 
 * @xmlonly
 * See <autoref sec="sched"/>
 * @endxmlonly
 * 
 * @param[in] _service Capability to the TCB which is being operated on.
 * @param[in] mcp The thread's new maximum controlled priority. 
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 */
LIBSEL4_INLINE long
seL4_TCB_SetMCPriority(seL4_TCB _service, seL4_Uint8 mcp)
{
	long result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(TCBSetMCPriority, 0, 0, 1);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;

	/* Marshal and initialise parameters. */
	mr0 = (mcp & 0xfful);
	mr1 = 0;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1);
	result = seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
	}

	return result;
}

/**
 * @xmlonly <manual name="TCB - Set IPC Buffer" label="tcb_setipcbuffer"/> @endxmlonly
 * @brief @xmlonly Set a thread's IPC buffer @endxmlonly
 * 
 * @xmlonly
 * See Sections <shortref sec="threads"/> and <shortref sec="messageinfo"/>
 * @endxmlonly
 * 
 * @param[in] _service Capability to the TCB which is being operated on.
 * @param[in] buffer Location of the thread's IPC buffer. Must be 512-byte aligned. The IPC buffer may not cross a page boundary. 
 * @param[in] bufferFrame Capability to a page containing the thread's IPC buffer. 
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 */
LIBSEL4_INLINE long
seL4_TCB_SetIPCBuffer(seL4_TCB _service, seL4_Word buffer, seL4_CPtr bufferFrame)
{
	long result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(TCBSetIPCBuffer, 0, 1, 1);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;

	/* Setup input capabilities. */
	seL4_SetCap(0, bufferFrame);

	/* Marshal and initialise parameters. */
	mr0 = buffer;
	mr1 = 0;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1);
	result = seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
	}

	return result;
}

/**
 * @xmlonly <manual name="TCB - Set Space" label="tcb_setspace"/> @endxmlonly
 * @brief @xmlonly Set the fault endpoint, CSpace and VSpace of a thread @endxmlonly
 * 
 * @xmlonly
 * See <autoref sec="threads"/>
 * @endxmlonly
 * 
 * @param[in] _service Capability to the TCB which is being operated on.
 * @param[in] fault_ep CPTR to the endpoint which receives IPCs when this thread faults. This capability is in the CSpace of the thread being configured. 
 * @param[in] cspace_root The new CSpace root. 
 * @param[in] cspace_root_data Optionally set the guard and guard size of the new root CNode. If set to zero, this parameter has no effect. 
 * @param[in] vspace_root The new VSpace root. 
 * @param[in] vspace_root_data Has no effect on x86 or ARM processors. 
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 */
LIBSEL4_INLINE long
seL4_TCB_SetSpace(seL4_TCB _service, seL4_Word fault_ep, seL4_CNode cspace_root, seL4_CapData_t cspace_root_data, seL4_CNode vspace_root, seL4_CapData_t vspace_root_data)
{
	long result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(TCBSetSpace, 0, 2, 3);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;

	/* Setup input capabilities. */
	seL4_SetCap(0, cspace_root);
	seL4_SetCap(1, vspace_root);

	/* Marshal and initialise parameters. */
	mr0 = fault_ep;
	mr1 = cspace_root_data.words[0];
	seL4_SetMR(2, vspace_root_data.words[0]);

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1);
	result = seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
	}

	return result;
}

/**
 * @xmlonly <manual name="TCB - Suspend" label="tcb_suspend"/> @endxmlonly
 * @brief @xmlonly Suspend a thread @endxmlonly
 * 
 * @xmlonly
 * See <autoref sec="thread_deactivation"/>
 * @endxmlonly
 * 
 * @param[in] _service Capability to the TCB which is being operated on.
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 */
LIBSEL4_INLINE long
seL4_TCB_Suspend(seL4_TCB _service)
{
	long result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(TCBSuspend, 0, 0, 0);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;

	/* Marshal and initialise parameters. */
	mr0 = 0;
	mr1 = 0;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1);
	result = seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
	}

	return result;
}

/**
 * @xmlonly <manual name="TCB - Resume" label="tcb_resume"/> @endxmlonly
 * @brief @xmlonly Resume a thread @endxmlonly
 * 
 * @xmlonly
 * See <autoref sec="thread_deactivation"/>
 * @endxmlonly
 * 
 * @param[in] _service Capability to the TCB which is being operated on.
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 */
LIBSEL4_INLINE long
seL4_TCB_Resume(seL4_TCB _service)
{
	long result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(TCBResume, 0, 0, 0);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;

	/* Marshal and initialise parameters. */
	mr0 = 0;
	mr1 = 0;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1);
	result = seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
	}

	return result;
}

/**
 * @xmlonly <manual name="TCB - Bind Notification" label="tcb_bindnotification"/> @endxmlonly
 * @brief @xmlonly Binds a notification object to a <obj name="TCB"/> @endxmlonly
 * 
 * @xmlonly
 * See <autoref sec="notification-binding"/>
 * @endxmlonly
 * 
 * @param[in] _service Capability to the TCB which is being operated on.
 * @param[in] notification Notification to bind. 
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 */
LIBSEL4_INLINE long
seL4_TCB_BindNotification(seL4_TCB _service, seL4_CPtr notification)
{
	long result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(TCBBindNotification, 0, 1, 0);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;

	/* Setup input capabilities. */
	seL4_SetCap(0, notification);

	/* Marshal and initialise parameters. */
	mr0 = 0;
	mr1 = 0;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1);
	result = seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
	}

	return result;
}

/**
 * @xmlonly <manual name="TCB - Unbind Notification" label="tcb_unbindnotification"/> @endxmlonly
 * @brief @xmlonly Unbinds any notification object from a <obj name="TCB"/> @endxmlonly
 * 
 * @xmlonly
 * See <autoref sec="notification-binding"/>
 * @endxmlonly
 * 
 * @param[in] _service Capability to the TCB which is being operated on.
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 */
LIBSEL4_INLINE long
seL4_TCB_UnbindNotification(seL4_TCB _service)
{
	long result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(TCBUnbindNotification, 0, 0, 0);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;

	/* Marshal and initialise parameters. */
	mr0 = 0;
	mr1 = 0;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1);
	result = seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
	}

	return result;
}

#if CONFIG_MAX_NUM_NODES > 1
/**
 * @xmlonly <manual name="TCB - Set CPU Affinity" label="tcb_setaffinity"/> @endxmlonly
 * @brief @xmlonly Change a thread's current CPU in multicore machine @endxmlonly
 * 
 * @xmlonly
 * See <autoref sec="thread_creation"/>
 * @endxmlonly
 * 
 * @param[in] _service Capability to the TCB which is being operated on.
 * @param[in] affinity The thread's new CPU to run. 
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 */
LIBSEL4_INLINE long
seL4_TCB_SetAffinity(seL4_TCB _service, seL4_Word affinity)
{
	long result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(TCBSetAffinity, 0, 0, 1);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;

	/* Marshal and initialise parameters. */
	mr0 = affinity;
	mr1 = 0;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1);
	result = seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
	}

	return result;
}

#endif
#if defined(CONFIG_HARDWARE_DEBUG_API)
/**
 * @xmlonly <manual name="TCB - Set Breakpoint" label="tcb_setbreakpoint"/> @endxmlonly
 * @brief @xmlonly Set or modify a thread's breakpoints or watchpoints. Calls to this function
 * overwrite previous configurations for the target breakpoint. Do not use this
 * with seL4_SingleStep: the API will reject the call and return an error.
 * Instead, use seL4_TCB_ConfigureSingleStepping to configure single-stepping. @endxmlonly
 * 
 * @xmlonly
 * See <autoref sec="debug_exceptions"/>
 * @endxmlonly
 * 
 * @param[in] _service Capability to the TCB which is being operated on.
 * @param[in] bp_num The API-ID of a target breakpoint. This ID will be a positive integer, with values ranging from 0 to seL4_NumHWBreakpoints - 1. 
 * @param[in] vaddr A virtual address which forms part of the match conditions for the triggering of the breakpoint. 
 * @param[in] type One of: seL4_InstructionBreakpoint, which specifies that the breakpoint should occur on instruction execution at the specified vaddr or seL4_DataBreakpoint, which states that the breakpoint should occur on data access at the specified vaddr. 
 * @param[in] size A positive integer indicating the trigger-span of the watchpoint. Must be zero when 'type' is seL4_InstructionBreakpoint. 
 * @param[in] rw One of seL4_BreakOnRead, meaning the breakpoint will only be triggered on read-access; seL4_BreakOnWrite meaning the breakpoint will only be triggered on write-access, and seL4_BreakOnReadWrite meaning the breakpoint will be triggered on any access. 
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 */
LIBSEL4_INLINE long
seL4_TCB_SetBreakpoint(seL4_TCB _service, seL4_Uint16 bp_num, seL4_Word vaddr, seL4_Word type, seL4_Word size, seL4_Word rw)
{
	long result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(TCBSetBreakpoint, 0, 0, 5);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;

	/* Marshal and initialise parameters. */
	mr0 = (bp_num & 0xfffful);
	mr1 = vaddr;
	seL4_SetMR(2, type);
	seL4_SetMR(3, size);
	seL4_SetMR(4, rw);

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1);
	result = seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
	}

	return result;
}

#endif
#if defined(CONFIG_HARDWARE_DEBUG_API)
/**
 * @xmlonly <manual name="TCB - Get Breakpoint" label="tcb_getbreakpoint"/> @endxmlonly
 * @brief @xmlonly Read a breakpoint or watchpoint's current configuration. @endxmlonly
 * 
 * @xmlonly
 * See <autoref sec="debug_exceptions"/>
 * @endxmlonly
 * 
 * @param[in] _service Capability to the TCB which is being operated on.
 * @param[in] bp_num The API-ID of a target breakpoint. This ID will be a positive integer, with values ranging from 0 to seL4_NumHWBreakpoints - 1. 
 * @return @xmlonly 
 *                 A <texttt text="seL4_TCB_GetBreakpoint_t"/>: Struct that contains
 *                 `<texttt text="seL4_Error error"/>', an seL4 API error value,
 *                 `<texttt text="seL4_Word vaddr"/>', the virtual address at which the breakpoint will currently
 *                 be triggered;
 *                 `<texttt text="seL4_Word type"/>', the type of operation which will currently trigger the
 *                 breakpoint, whether instruction execution, or data access;
 *                 `<texttt text="seL4_Word size"/>', integer value for the span-size of the breakpoint.
 *                 Usually a power of two (1, 2, 4, etc.);
 *                 `<texttt text="seL4_Word rw"/>', the access direction that will currently trigger the breakpoint,
 *                 whether read, write, or both and
 *                 `<texttt text="seL4_Bool is_enabled"/>', which indicates whether or not the breakpoint
 *                 will currently be triggered if the match conditions are met.
 *              @endxmlonly
 */
LIBSEL4_INLINE seL4_TCB_GetBreakpoint_t
seL4_TCB_GetBreakpoint(seL4_TCB _service, seL4_Uint16 bp_num)
{
	seL4_TCB_GetBreakpoint_t result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(TCBGetBreakpoint, 0, 0, 1);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;

	/* Marshal and initialise parameters. */
	mr0 = (bp_num & 0xfffful);
	mr1 = 0;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1);
	result.error = seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result.error != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
		return result;
	}

	/* Unmarshal result. */
	result.vaddr = mr0;
	result.type = mr1;
	result.size = seL4_GetMR(2);
	result.rw = seL4_GetMR(3);
	result.is_enabled = (seL4_GetMR(4) & 0x1);
	return result;
}

#endif
#if defined(CONFIG_HARDWARE_DEBUG_API)
/**
 * @xmlonly <manual name="TCB - Unset Breakpoint" label="tcb_unsetbreakpoint"/> @endxmlonly
 * @brief @xmlonly Disables a hardware breakpoint or watchpoint. The caller should assume that
 * the underlying configuration of the hardware registers has also been cleared.
 * Do not use this to clear single-stepping: the API will reject the call and
 * return an error. Instead, use seL4_TCB_ConfigureSingleStepping to disable
 * single-stepping. @endxmlonly
 * 
 * @xmlonly
 * See <autoref sec="debug_exceptions"/>
 * @endxmlonly
 * 
 * @param[in] _service Capability to the TCB which is being operated on.
 * @param[in] bp_num The API-ID of a target breakpoint. This ID will be a positive integer, with values ranging from 0 to seL4_NumHWBreakpoints - 1. 
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 */
LIBSEL4_INLINE long
seL4_TCB_UnsetBreakpoint(seL4_TCB _service, seL4_Uint16 bp_num)
{
	long result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(TCBUnsetBreakpoint, 0, 0, 1);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;

	/* Marshal and initialise parameters. */
	mr0 = (bp_num & 0xfffful);
	mr1 = 0;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1);
	result = seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
	}

	return result;
}

#endif
#if defined(CONFIG_HARDWARE_DEBUG_API)
/**
 * @xmlonly <manual name="TCB - Configure Single Stepping" label="tcb_configuresinglestepping"/> @endxmlonly
 * @brief @xmlonly Set or modify single stepping options for the target TCB. Subsequent calls to this
 * function overwrite previous configuration. Depending on your processor architecture,
 * this may or may not require the consumption of a hardware register. @endxmlonly
 * 
 * @xmlonly
 * See Sections <shortref sec="single_stepping_debug_exception"/> and <shortref sec="debug_exceptions"/>
 * @endxmlonly
 * 
 * @param[in] _service Capability to the TCB which is being operated on.
 * @param[in] bp_num The API-ID of a target breakpoint. This ID will be a positive integer, with values ranging from 0 to seL4_NumHWBreakpoints - 1. 
 * @param[in] num_instructions Number of instructions to step over before delivering a fault to the target thread's fault endpoint. Setting this to 0 disables single-stepping. 
 * @return @xmlonly 
 *                 A <texttt text="seL4_TCB_ConfigureSingleStepping_t"/>: Struct that contains
 *                 `<texttt text="seL4_Error error"/>', an seL4 API error value,
 *                 `<texttt text="seL4_Bool bp_was_consumed"/>', a boolean which indicates whether or not the <texttt text="bp_num"/>
 *                 breakpoint ID that was passed to the function, was consumed in the setup of the single-stepping
 *                 functionality: if this is <texttt text="true"/>, the caller should not attempt to re-use <texttt text="bp_num"/>
 *                 until it has disabled the single-stepping functionality via a subsequent call to
 *                 seL4_TCB_ConfigureSingleStepping with an <texttt text="num_instructions"/> argument of 0.
 *              @endxmlonly
 */
LIBSEL4_INLINE seL4_TCB_ConfigureSingleStepping_t
seL4_TCB_ConfigureSingleStepping(seL4_TCB _service, seL4_Uint16 bp_num, seL4_Word num_instructions)
{
	seL4_TCB_ConfigureSingleStepping_t result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(TCBConfigureSingleStepping, 0, 0, 2);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;

	/* Marshal and initialise parameters. */
	mr0 = (bp_num & 0xfffful);
	mr1 = num_instructions;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1);
	result.error = seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result.error != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
		return result;
	}

	/* Unmarshal result. */
	result.bp_was_consumed = (mr0 & 0x1);
	return result;
}

#endif
/**
 * @xmlonly <manual name="CNode - Revoke" label="cnode_revoke"/> @endxmlonly
 * @brief @xmlonly Delete all child capabilities of a capability @endxmlonly
 * 
 * @xmlonly
 * See <autoref sec="cnode-ops"/>.
 * @endxmlonly
 * 
 * @param[in] _service CPTR to the CNode at the root of the CSpace where the capability will be found. Must be at a depth of 32.
 * @param[in] index CPTR to the capability. Resolved from the root of the _service parameter. 
 * @param[in] depth Number of bits of index to resolve to find the capability being operated on. 
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 */
LIBSEL4_INLINE long
seL4_CNode_Revoke(seL4_CNode _service, seL4_Word index, seL4_Uint8 depth)
{
	long result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(CNodeRevoke, 0, 0, 2);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;

	/* Marshal and initialise parameters. */
	mr0 = index;
	mr1 = (depth & 0xfful);

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1);
	result = seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
	}

	return result;
}

/**
 * @xmlonly <manual name="CNode - Delete" label="cnode_delete"/> @endxmlonly
 * @brief @xmlonly Delete a capability @endxmlonly
 * 
 * @xmlonly
 * See <autoref sec="cnode-ops"/>.
 * @endxmlonly
 * 
 * @param[in] _service CPTR to the CNode at the root of the CSpace where the capability will be found. Must be at a depth of 32.
 * @param[in] index CPTR to the capability. Resolved from the root of the _service parameter. 
 * @param[in] depth Number of bits of index to resolve to find the capability being operated on. 
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 */
LIBSEL4_INLINE long
seL4_CNode_Delete(seL4_CNode _service, seL4_Word index, seL4_Uint8 depth)
{
	long result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(CNodeDelete, 0, 0, 2);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;

	/* Marshal and initialise parameters. */
	mr0 = index;
	mr1 = (depth & 0xfful);

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1);
	result = seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
	}

	return result;
}

/**
 * @xmlonly <manual name="CNode - Cancel Badged Sends" label="cnode_cancelbadgedsends"/> @endxmlonly
 * @brief @xmlonly The cancel badged sends method is intend to allow for the reuse of badges by an
 * authority. When used with a badged endpoint capability it
 * will cancel any outstanding send operations for that endpoint and badge.
 * This operation has no effect on un-badged or other objects. @endxmlonly
 * 
 * @xmlonly
 * See <autoref sec="cnode-ops"/>.
 * @endxmlonly
 * 
 * @param[in] _service CPTR to the CNode at the root of the CSpace where the capability will be found. Must be at a depth of 32.
 * @param[in] index CPTR to the capability. Resolved from the root of the _service parameter. 
 * @param[in] depth Number of bits of index to resolve to find the capability being operated on. 
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 */
LIBSEL4_INLINE long
seL4_CNode_CancelBadgedSends(seL4_CNode _service, seL4_Word index, seL4_Uint8 depth)
{
	long result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(CNodeCancelBadgedSends, 0, 0, 2);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;

	/* Marshal and initialise parameters. */
	mr0 = index;
	mr1 = (depth & 0xfful);

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1);
	result = seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
	}

	return result;
}

/**
 * @xmlonly <manual name="CNode - Copy" label="cnode_copy"/> @endxmlonly
 * @brief @xmlonly Copy a capability, setting its access rights whilst doing so @endxmlonly
 * 
 * @xmlonly
 * See <autoref sec="cnode-ops"/>.
 * @endxmlonly
 * 
 * @param[in] _service CPTR to the CNode that forms the root of the destination CSpace. Must be at a depth of 32.
 * @param[in] dest_index CPTR to the destination slot. Resolved from the root of the destination CSpace. 
 * @param[in] dest_depth Number of bits of dest_index to resolve to find the destination slot. 
 * @param[in] src_root CPTR to the CNode that forms the root of the source CSpace. Must be at a depth of 32. 
 * @param[in] src_index CPTR to the source slot. Resolved from the root of the source CSpace. 
 * @param[in] src_depth Number of bits of src_index to resolve to find the source slot. 
 * @param[in] rights The rights inherited by the new capability. Possible values for this type are given in  @xmlonly <autoref sec="cap_rights"/> @endxmlonly . 
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 */
LIBSEL4_INLINE long
seL4_CNode_Copy(seL4_CNode _service, seL4_Word dest_index, seL4_Uint8 dest_depth, seL4_CNode src_root, seL4_Word src_index, seL4_Uint8 src_depth, seL4_CapRights_t rights)
{
	long result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(CNodeCopy, 0, 1, 5);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;

	/* Setup input capabilities. */
	seL4_SetCap(0, src_root);

	/* Marshal and initialise parameters. */
	mr0 = dest_index;
	mr1 = (dest_depth & 0xfful);
	seL4_SetMR(2, src_index);
	seL4_SetMR(3, (src_depth & 0xfful));
	seL4_SetMR(4, rights.words[0]);

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1);
	result = seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
	}

	return result;
}

/**
 * @xmlonly <manual name="CNode - Mint" label="cnode_mint"/> @endxmlonly
 * @brief @xmlonly Copy a capability, setting its access rights and badge whilst doing so @endxmlonly
 * 
 * @xmlonly
 * See <autoref sec="cnode-ops"/>.
 * @endxmlonly
 * 
 * @param[in] _service CPTR to the CNode that forms the root of the destination CSpace. Must be at a depth of 32.
 * @param[in] dest_index CPTR to the destination slot. Resolved from the root of the destination CSpace. 
 * @param[in] dest_depth Number of bits of dest_index to resolve to find the destination slot. 
 * @param[in] src_root CPTR to the CNode that forms the root of the source CSpace. Must be at a depth of 32. 
 * @param[in] src_index CPTR to the source slot. Resolved from the root of the source CSpace. 
 * @param[in] src_depth Number of bits of src_index to resolve to find the source slot. 
 * @param[in] rights The rights inherited by the new capability. Possible values for this type are given in  @xmlonly <autoref sec="cap_rights"/> @endxmlonly . 
 * @param[in] badge Badge or guard to be applied to the new capability. For badges the high 4 bits are ignored. 
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 */
LIBSEL4_INLINE long
seL4_CNode_Mint(seL4_CNode _service, seL4_Word dest_index, seL4_Uint8 dest_depth, seL4_CNode src_root, seL4_Word src_index, seL4_Uint8 src_depth, seL4_CapRights_t rights, seL4_CapData_t badge)
{
	long result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(CNodeMint, 0, 1, 6);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;

	/* Setup input capabilities. */
	seL4_SetCap(0, src_root);

	/* Marshal and initialise parameters. */
	mr0 = dest_index;
	mr1 = (dest_depth & 0xfful);
	seL4_SetMR(2, src_index);
	seL4_SetMR(3, (src_depth & 0xfful));
	seL4_SetMR(4, rights.words[0]);
	seL4_SetMR(5, badge.words[0]);

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1);
	result = seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
	}

	return result;
}

/**
 * @xmlonly <manual name="CNode - Move" label="cnode_move"/> @endxmlonly
 * @brief @xmlonly Move a capability @endxmlonly
 * 
 * @xmlonly
 * See <autoref sec="cnode-ops"/>.
 * @endxmlonly
 * 
 * @param[in] _service CPTR to the CNode that forms the root of the destination CSpace. Must be at a depth of 32.
 * @param[in] dest_index CPTR to the destination slot. Resolved from the root of the destination CSpace. 
 * @param[in] dest_depth Number of bits of dest_index to resolve to find the destination slot. 
 * @param[in] src_root CPTR to the CNode that forms the root of the source CSpace. Must be at a depth of 32. 
 * @param[in] src_index CPTR to the source slot. Resolved from the root of the source CSpace. 
 * @param[in] src_depth Number of bits of src_index to resolve to find the source slot. 
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 */
LIBSEL4_INLINE long
seL4_CNode_Move(seL4_CNode _service, seL4_Word dest_index, seL4_Uint8 dest_depth, seL4_CNode src_root, seL4_Word src_index, seL4_Uint8 src_depth)
{
	long result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(CNodeMove, 0, 1, 4);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;

	/* Setup input capabilities. */
	seL4_SetCap(0, src_root);

	/* Marshal and initialise parameters. */
	mr0 = dest_index;
	mr1 = (dest_depth & 0xfful);
	seL4_SetMR(2, src_index);
	seL4_SetMR(3, (src_depth & 0xfful));

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1);
	result = seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
	}

	return result;
}

/**
 * @xmlonly <manual name="CNode - Mutate" label="cnode_mutate"/> @endxmlonly
 * @brief @xmlonly Move a capability, setting its badge in the process @endxmlonly
 * 
 * @xmlonly
 * See <autoref sec="cnode-ops"/>.
 * @endxmlonly
 * 
 * @param[in] _service CPTR to the CNode that forms the root of the destination CSpace. Must be at a depth of 32.
 * @param[in] dest_index CPTR to the destination slot. Resolved from the root of the destination CSpace. 
 * @param[in] dest_depth Number of bits of dest_index to resolve to find the destination slot. 
 * @param[in] src_root CPTR to the CNode that forms the root of the source CSpace. Must be at a depth of 32. 
 * @param[in] src_index CPTR to the source slot. Resolved from the root of the source CSpace. 
 * @param[in] src_depth Number of bits of src_index to resolve to find the source slot. 
 * @param[in] badge Badge or guard to be applied to the new capability. For badges the high 4 bits are ignored. 
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 */
LIBSEL4_INLINE long
seL4_CNode_Mutate(seL4_CNode _service, seL4_Word dest_index, seL4_Uint8 dest_depth, seL4_CNode src_root, seL4_Word src_index, seL4_Uint8 src_depth, seL4_CapData_t badge)
{
	long result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(CNodeMutate, 0, 1, 5);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;

	/* Setup input capabilities. */
	seL4_SetCap(0, src_root);

	/* Marshal and initialise parameters. */
	mr0 = dest_index;
	mr1 = (dest_depth & 0xfful);
	seL4_SetMR(2, src_index);
	seL4_SetMR(3, (src_depth & 0xfful));
	seL4_SetMR(4, badge.words[0]);

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1);
	result = seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
	}

	return result;
}

/**
 * @xmlonly <manual name="CNode - Rotate" label="cnode_rotate"/> @endxmlonly
 * @brief @xmlonly Given 3 capability slots - a destination, pivot and source - move the capability in the
 * pivot slot to the destination slot and the capability in the source slot to the pivot slot @endxmlonly
 * 
 * @xmlonly
 * See <autoref sec="cnode-ops"/>.
 * @endxmlonly
 * 
 * @param[in] _service CPTR to the CNode at the root of the CSpace where the destination slot will be found. Must be at a depth of 32.
 * @param[in] dest_index CPTR to the destination slot. Resolved relative to _service. Must be empty unless it refers to the same slot as the source slot. 
 * @param[in] dest_depth Depth to resolve dest_index to. 
 * @param[in] dest_badge The new capdata for the capability that ends up in the destination slot. 
 * @param[in] pivot_root CPTR to the CNode at the root of the CSpace where the pivot slot will be found. Must be at a depth of 32. 
 * @param[in] pivot_index CPTR to the pivot slot. Resolved relative to pivot_root. The resolved slot must not refer to the source or destination slots. 
 * @param[in] pivot_depth Depth to resolve pivot_index to. 
 * @param[in] pivot_badge The new capdata for the capability that ends up in the pivot slot. 
 * @param[in] src_root CPTR to the CNode at the root of the CSpace where the source slot will be found. Must be at a depth of 32. 
 * @param[in] src_index CPTR to the source slot. Resolved relative to src_root. 
 * @param[in] src_depth Depth to resolve src_index to. 
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 */
LIBSEL4_INLINE long
seL4_CNode_Rotate(seL4_CNode _service, seL4_Word dest_index, seL4_Uint8 dest_depth, seL4_CapData_t dest_badge, seL4_CNode pivot_root, seL4_Word pivot_index, seL4_Uint8 pivot_depth, seL4_CapData_t pivot_badge, seL4_CNode src_root, seL4_Word src_index, seL4_Uint8 src_depth)
{
	long result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(CNodeRotate, 0, 2, 8);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;

	/* Setup input capabilities. */
	seL4_SetCap(0, pivot_root);
	seL4_SetCap(1, src_root);

	/* Marshal and initialise parameters. */
	mr0 = dest_index;
	mr1 = (dest_depth & 0xfful);
	seL4_SetMR(2, dest_badge.words[0]);
	seL4_SetMR(3, pivot_index);
	seL4_SetMR(4, (pivot_depth & 0xfful));
	seL4_SetMR(5, pivot_badge.words[0]);
	seL4_SetMR(6, src_index);
	seL4_SetMR(7, (src_depth & 0xfful));

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1);
	result = seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
	}

	return result;
}

/**
 * @xmlonly <manual name="CNode - Save Caller" label="cnode_savecaller"/> @endxmlonly
 * @brief @xmlonly Save the reply capability from the last time the thread was called in the given CSpace so that it can be invoked later @endxmlonly
 * 
 * @xmlonly
 * See <autoref sec="cnode-ops"/>.
 * @endxmlonly
 * 
 * @param[in] _service CPTR to the CNode at the root of the CSpace where the capability is to be saved. Must be at a depth of 32.
 * @param[in] index CPTR to the slot in which to save the capability. Resolved from the root of the _service parameter. 
 * @param[in] depth Number of bits of index to resolve to find the slot being targeted. 
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 */
LIBSEL4_INLINE long
seL4_CNode_SaveCaller(seL4_CNode _service, seL4_Word index, seL4_Uint8 depth)
{
	long result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(CNodeSaveCaller, 0, 0, 2);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;

	/* Marshal and initialise parameters. */
	mr0 = index;
	mr1 = (depth & 0xfful);

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1);
	result = seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
	}

	return result;
}

/**
 * @xmlonly <manual name="IRQ Control - Get" label="irq_controlget"/> @endxmlonly
 * @brief @xmlonly Create an IRQ handler capability @endxmlonly
 * 
 * @xmlonly
 * See <autoref sec="interrupts"/>.
 * @endxmlonly
 * 
 * @param[in] _service An IRQControl capability. This gives you the authority to make this call.
 * @param[in] irq The IRQ that you want this capability to handle. 
 * @param[in] root CPTR to the CNode that forms the root of the destination CSpace. Must be at a depth of 32. 
 * @param[in] index CPTR to the destination slot. Resolved from the root of the destination CSpace. 
 * @param[in] depth Number of bits of dest_index to resolve to find the destination slot. 
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 */
LIBSEL4_INLINE long
seL4_IRQControl_Get(seL4_IRQControl _service, int irq, seL4_CNode root, seL4_Word index, seL4_Uint8 depth)
{
	long result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(IRQIssueIRQHandler, 0, 1, 3);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;

	/* Setup input capabilities. */
	seL4_SetCap(0, root);

	/* Marshal and initialise parameters. */
	mr0 = irq;
	mr1 = index;
	seL4_SetMR(2, (depth & 0xfful));

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1);
	result = seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
	}

	return result;
}

/**
 * @xmlonly <manual name="IRQ Handler - Acknowledge" label="irq_handleracknowledge"/> @endxmlonly
 * @brief @xmlonly Acknowledge the receipt of an interrupt and re-enable it @endxmlonly
 * 
 * @xmlonly
 * See <autoref sec="interrupts"/>.
 * @endxmlonly
 * 
 * @param[in] _service The IRQ handler capability.
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 */
LIBSEL4_INLINE long
seL4_IRQHandler_Ack(seL4_IRQHandler _service)
{
	long result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(IRQAckIRQ, 0, 0, 0);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;

	/* Marshal and initialise parameters. */
	mr0 = 0;
	mr1 = 0;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1);
	result = seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
	}

	return result;
}

/**
 * @xmlonly <manual name="IRQ Handler - Set Notification" label="irq_handlersetnotification"/> @endxmlonly
 * @brief @xmlonly Set the notification which the kernel will signal on interrupts
 * controlled by the supplied IRQ handler capability @endxmlonly
 * 
 * @xmlonly
 * See <autoref sec="interrupts"/>.
 * @endxmlonly
 * 
 * @param[in] _service The IRQ handler capability.
 * @param[in] notification The notification which the IRQs will signal. 
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 */
LIBSEL4_INLINE long
seL4_IRQHandler_SetNotification(seL4_IRQHandler _service, seL4_CPtr notification)
{
	long result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(IRQSetIRQHandler, 0, 1, 0);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;

	/* Setup input capabilities. */
	seL4_SetCap(0, notification);

	/* Marshal and initialise parameters. */
	mr0 = 0;
	mr1 = 0;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1);
	result = seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
	}

	return result;
}

/**
 * @xmlonly <manual name="IRQ Handler - Clear" label="irq_handlerclear"/> @endxmlonly
 * @brief @xmlonly Clear the handler capability from the IRQ slot @endxmlonly
 * 
 * @xmlonly
 * See <autoref sec="interrupts"/>.
 * @endxmlonly
 * 
 * @param[in] _service The IRQ handler capability.
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 */
LIBSEL4_INLINE long
seL4_IRQHandler_Clear(seL4_IRQHandler _service)
{
	long result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(IRQClearIRQHandler, 0, 0, 0);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;

	/* Marshal and initialise parameters. */
	mr0 = 0;
	mr1 = 0;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1);
	result = seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
	}

	return result;
}

/**
 * @xmlonly <manual name="Domain Set - Set" label="domainset_set"/> @endxmlonly
 * @brief @xmlonly Change the domain of a thread. @endxmlonly
 * 
 * @xmlonly
 * See <autoref sec="domains"/>.
 * @endxmlonly
 * 
 * @param[in] _service Capability allowing domain configuration.
 * @param[in] domain The thread's new domain. 
 * @param[in] thread Capability to the TCB which is being operated on. 
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 */
LIBSEL4_INLINE long
seL4_DomainSet_Set(seL4_DomainSet _service, seL4_Uint8 domain, seL4_TCB thread)
{
	long result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(DomainSetSet, 0, 1, 1);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;

	/* Setup input capabilities. */
	seL4_SetCap(0, thread);

	/* Marshal and initialise parameters. */
	mr0 = (domain & 0xfful);
	mr1 = 0;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1);
	result = seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
	}

	return result;
}

#endif /* __LIBSEL4_SEL4_CLIENT_H */
