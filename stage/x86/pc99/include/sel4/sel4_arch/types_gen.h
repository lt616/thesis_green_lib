#ifndef _HOME_AXJLLT_DESKTOP_SEL4TEST_BUILD_X86_PC99_LIBSEL4_SEL4_ARCH_INCLUDE_IA32_SEL4_SEL4_ARCH_TYPES_GEN_H
#define _HOME_AXJLLT_DESKTOP_SEL4TEST_BUILD_X86_PC99_LIBSEL4_SEL4_ARCH_INCLUDE_IA32_SEL4_SEL4_ARCH_TYPES_GEN_H

#include <autoconf.h>
#include <sel4/simple_types.h>
#include <sel4/debug_assert.h>
struct seL4_Fault {
    seL4_Uint32 words[12];
};
typedef struct seL4_Fault seL4_Fault_t;

enum seL4_Fault_tag {
    seL4_Fault_NullFault = 0,
    seL4_Fault_CapFault = 1,
    seL4_Fault_UnknownSyscall = 2,
    seL4_Fault_UserException = 3,
    seL4_Fault_VMFault = 5
};
typedef enum seL4_Fault_tag seL4_Fault_tag_t;

LIBSEL4_INLINE_FUNC seL4_Uint32 CONST
seL4_Fault_get_seL4_FaultType(seL4_Fault_t seL4_Fault) {
    return (seL4_Fault.words[0] >> 0) & 0x7ul;
}

LIBSEL4_INLINE_FUNC int CONST
seL4_Fault_seL4_FaultType_equals(seL4_Fault_t seL4_Fault, seL4_Uint32 seL4_Fault_type_tag) {
    return ((seL4_Fault.words[0] >> 0) & 0x7ul) == seL4_Fault_type_tag;
}

LIBSEL4_INLINE_FUNC seL4_Uint32 PURE
seL4_Fault_ptr_get_seL4_FaultType(seL4_Fault_t *seL4_Fault_ptr) {
    return (seL4_Fault_ptr->words[0] >> 0) & 0x7ul;
}

LIBSEL4_INLINE_FUNC seL4_Fault_t CONST
seL4_Fault_NullFault_new(void) {
    seL4_Fault_t seL4_Fault;

    seL4_Fault.words[0] = 0;
    seL4_Fault.words[1] = 0;
    seL4_Fault.words[2] = 0;
    seL4_Fault.words[3] = 0;
    seL4_Fault.words[4] = 0;
    seL4_Fault.words[5] = 0;
    seL4_Fault.words[6] = 0;
    seL4_Fault.words[7] = 0;
    seL4_Fault.words[8] = 0;
    seL4_Fault.words[9] = 0;
    seL4_Fault.words[10] = 0;
    seL4_Fault.words[11] = 0;

    /* fail if user has passed bits that we will override */
    seL4_DebugAssert(((seL4_Uint32)seL4_Fault_NullFault & ~0x7ul) == ((0 && ((seL4_Uint32)seL4_Fault_NullFault & (1ul << 31))) ? 0x0 : 0));
    seL4_Fault.words[0] |= ((seL4_Uint32)seL4_Fault_NullFault & 0x7ul) << 0;

    return seL4_Fault;
}

LIBSEL4_INLINE_FUNC void
seL4_Fault_NullFault_ptr_new(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Fault_ptr->words[0] = 0;
    seL4_Fault_ptr->words[1] = 0;
    seL4_Fault_ptr->words[2] = 0;
    seL4_Fault_ptr->words[3] = 0;
    seL4_Fault_ptr->words[4] = 0;
    seL4_Fault_ptr->words[5] = 0;
    seL4_Fault_ptr->words[6] = 0;
    seL4_Fault_ptr->words[7] = 0;
    seL4_Fault_ptr->words[8] = 0;
    seL4_Fault_ptr->words[9] = 0;
    seL4_Fault_ptr->words[10] = 0;
    seL4_Fault_ptr->words[11] = 0;

    /* fail if user has passed bits that we will override */
    seL4_DebugAssert(((seL4_Uint32)seL4_Fault_NullFault & ~0x7ul) == ((0 && ((seL4_Uint32)seL4_Fault_NullFault & (1ul << 31))) ? 0x0 : 0));
    seL4_Fault_ptr->words[0] |= ((seL4_Uint32)seL4_Fault_NullFault & 0x7ul) << 0;
}

LIBSEL4_INLINE_FUNC seL4_Fault_t CONST
seL4_Fault_CapFault_new(seL4_Uint32 IP, seL4_Uint32 Addr, seL4_Uint32 InRecvPhase, seL4_Uint32 LookupFailureType, seL4_Uint32 MR4, seL4_Uint32 MR5, seL4_Uint32 MR6) {
    seL4_Fault_t seL4_Fault;

    seL4_Fault.words[0] = 0;
    seL4_Fault.words[1] = 0;
    seL4_Fault.words[2] = 0;
    seL4_Fault.words[3] = 0;
    seL4_Fault.words[4] = 0;
    seL4_Fault.words[5] = 0;
    seL4_Fault.words[6] = 0;
    seL4_Fault.words[7] = 0;
    seL4_Fault.words[8] = 0;
    seL4_Fault.words[9] = 0;
    seL4_Fault.words[10] = 0;
    seL4_Fault.words[11] = 0;

       seL4_Fault.words[7] |= IP << 0;
       seL4_Fault.words[6] |= Addr << 0;
       seL4_Fault.words[5] |= InRecvPhase << 0;
       seL4_Fault.words[4] |= LookupFailureType << 0;
       seL4_Fault.words[3] |= MR4 << 0;
       seL4_Fault.words[2] |= MR5 << 0;
       seL4_Fault.words[1] |= MR6 << 0;
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert(((seL4_Uint32)seL4_Fault_CapFault & ~0x7ul) == ((0 && ((seL4_Uint32)seL4_Fault_CapFault & (1ul << 31))) ? 0x0 : 0));
    seL4_Fault.words[0] |= ((seL4_Uint32)seL4_Fault_CapFault & 0x7ul) << 0;

    return seL4_Fault;
}

LIBSEL4_INLINE_FUNC void
seL4_Fault_CapFault_ptr_new(seL4_Fault_t *seL4_Fault_ptr, seL4_Uint32 IP, seL4_Uint32 Addr, seL4_Uint32 InRecvPhase, seL4_Uint32 LookupFailureType, seL4_Uint32 MR4, seL4_Uint32 MR5, seL4_Uint32 MR6) {
    seL4_Fault_ptr->words[0] = 0;
    seL4_Fault_ptr->words[1] = 0;
    seL4_Fault_ptr->words[2] = 0;
    seL4_Fault_ptr->words[3] = 0;
    seL4_Fault_ptr->words[4] = 0;
    seL4_Fault_ptr->words[5] = 0;
    seL4_Fault_ptr->words[6] = 0;
    seL4_Fault_ptr->words[7] = 0;
    seL4_Fault_ptr->words[8] = 0;
    seL4_Fault_ptr->words[9] = 0;
    seL4_Fault_ptr->words[10] = 0;
    seL4_Fault_ptr->words[11] = 0;

    seL4_Fault_ptr->words[7] |= IP << 0;
    seL4_Fault_ptr->words[6] |= Addr << 0;
    seL4_Fault_ptr->words[5] |= InRecvPhase << 0;
    seL4_Fault_ptr->words[4] |= LookupFailureType << 0;
    seL4_Fault_ptr->words[3] |= MR4 << 0;
    seL4_Fault_ptr->words[2] |= MR5 << 0;
    seL4_Fault_ptr->words[1] |= MR6 << 0;
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert(((seL4_Uint32)seL4_Fault_CapFault & ~0x7ul) == ((0 && ((seL4_Uint32)seL4_Fault_CapFault & (1ul << 31))) ? 0x0 : 0));
    seL4_Fault_ptr->words[0] |= ((seL4_Uint32)seL4_Fault_CapFault & 0x7ul) << 0;
}

LIBSEL4_INLINE_FUNC seL4_Uint32 CONST
seL4_Fault_CapFault_get_IP(seL4_Fault_t seL4_Fault) {
    seL4_Uint32 ret;
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0x7) ==
           seL4_Fault_CapFault);

    ret = (seL4_Fault.words[7] & 0xfffffffful) >> 0;
    /* Possibly sign extend */
    if (0 && (ret & (1ul << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC seL4_Fault_t CONST
seL4_Fault_CapFault_set_IP(seL4_Fault_t seL4_Fault, seL4_Uint32 v) {
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0x7) ==
           seL4_Fault_CapFault);
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xfffffffful >> 0 ) | 0x0) & v) == ((0 && (v & (1ul << (31)))) ? 0x0 : 0));

    seL4_Fault.words[7] &= ~0xfffffffful;
    seL4_Fault.words[7] |= (v << 0) & 0xfffffffful;
    return seL4_Fault;
}

LIBSEL4_INLINE_FUNC seL4_Uint32 PURE
seL4_Fault_CapFault_ptr_get_IP(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint32 ret;
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0x7) ==
           seL4_Fault_CapFault);

    ret = (seL4_Fault_ptr->words[7] & 0xfffffffful) >> 0;
    /* Possibly sign extend */
    if (0 && (ret & (1ul << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC void
seL4_Fault_CapFault_ptr_set_IP(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint32 v) {
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0x7) ==
           seL4_Fault_CapFault);

    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xfffffffful >> 0) | 0x0) & v) == ((0 && (v & (1ul << (31)))) ? 0x0 : 0));

    seL4_Fault_ptr->words[7] &= ~0xfffffffful;
    seL4_Fault_ptr->words[7] |= (v << 0) & 0xfffffffful;
}

LIBSEL4_INLINE_FUNC seL4_Uint32 CONST
seL4_Fault_CapFault_get_Addr(seL4_Fault_t seL4_Fault) {
    seL4_Uint32 ret;
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0x7) ==
           seL4_Fault_CapFault);

    ret = (seL4_Fault.words[6] & 0xfffffffful) >> 0;
    /* Possibly sign extend */
    if (0 && (ret & (1ul << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC seL4_Fault_t CONST
seL4_Fault_CapFault_set_Addr(seL4_Fault_t seL4_Fault, seL4_Uint32 v) {
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0x7) ==
           seL4_Fault_CapFault);
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xfffffffful >> 0 ) | 0x0) & v) == ((0 && (v & (1ul << (31)))) ? 0x0 : 0));

    seL4_Fault.words[6] &= ~0xfffffffful;
    seL4_Fault.words[6] |= (v << 0) & 0xfffffffful;
    return seL4_Fault;
}

LIBSEL4_INLINE_FUNC seL4_Uint32 PURE
seL4_Fault_CapFault_ptr_get_Addr(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint32 ret;
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0x7) ==
           seL4_Fault_CapFault);

    ret = (seL4_Fault_ptr->words[6] & 0xfffffffful) >> 0;
    /* Possibly sign extend */
    if (0 && (ret & (1ul << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC void
seL4_Fault_CapFault_ptr_set_Addr(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint32 v) {
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0x7) ==
           seL4_Fault_CapFault);

    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xfffffffful >> 0) | 0x0) & v) == ((0 && (v & (1ul << (31)))) ? 0x0 : 0));

    seL4_Fault_ptr->words[6] &= ~0xfffffffful;
    seL4_Fault_ptr->words[6] |= (v << 0) & 0xfffffffful;
}

LIBSEL4_INLINE_FUNC seL4_Uint32 CONST
seL4_Fault_CapFault_get_InRecvPhase(seL4_Fault_t seL4_Fault) {
    seL4_Uint32 ret;
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0x7) ==
           seL4_Fault_CapFault);

    ret = (seL4_Fault.words[5] & 0xfffffffful) >> 0;
    /* Possibly sign extend */
    if (0 && (ret & (1ul << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC seL4_Fault_t CONST
seL4_Fault_CapFault_set_InRecvPhase(seL4_Fault_t seL4_Fault, seL4_Uint32 v) {
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0x7) ==
           seL4_Fault_CapFault);
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xfffffffful >> 0 ) | 0x0) & v) == ((0 && (v & (1ul << (31)))) ? 0x0 : 0));

    seL4_Fault.words[5] &= ~0xfffffffful;
    seL4_Fault.words[5] |= (v << 0) & 0xfffffffful;
    return seL4_Fault;
}

LIBSEL4_INLINE_FUNC seL4_Uint32 PURE
seL4_Fault_CapFault_ptr_get_InRecvPhase(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint32 ret;
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0x7) ==
           seL4_Fault_CapFault);

    ret = (seL4_Fault_ptr->words[5] & 0xfffffffful) >> 0;
    /* Possibly sign extend */
    if (0 && (ret & (1ul << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC void
seL4_Fault_CapFault_ptr_set_InRecvPhase(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint32 v) {
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0x7) ==
           seL4_Fault_CapFault);

    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xfffffffful >> 0) | 0x0) & v) == ((0 && (v & (1ul << (31)))) ? 0x0 : 0));

    seL4_Fault_ptr->words[5] &= ~0xfffffffful;
    seL4_Fault_ptr->words[5] |= (v << 0) & 0xfffffffful;
}

LIBSEL4_INLINE_FUNC seL4_Uint32 CONST
seL4_Fault_CapFault_get_LookupFailureType(seL4_Fault_t seL4_Fault) {
    seL4_Uint32 ret;
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0x7) ==
           seL4_Fault_CapFault);

    ret = (seL4_Fault.words[4] & 0xfffffffful) >> 0;
    /* Possibly sign extend */
    if (0 && (ret & (1ul << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC seL4_Fault_t CONST
seL4_Fault_CapFault_set_LookupFailureType(seL4_Fault_t seL4_Fault, seL4_Uint32 v) {
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0x7) ==
           seL4_Fault_CapFault);
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xfffffffful >> 0 ) | 0x0) & v) == ((0 && (v & (1ul << (31)))) ? 0x0 : 0));

    seL4_Fault.words[4] &= ~0xfffffffful;
    seL4_Fault.words[4] |= (v << 0) & 0xfffffffful;
    return seL4_Fault;
}

LIBSEL4_INLINE_FUNC seL4_Uint32 PURE
seL4_Fault_CapFault_ptr_get_LookupFailureType(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint32 ret;
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0x7) ==
           seL4_Fault_CapFault);

    ret = (seL4_Fault_ptr->words[4] & 0xfffffffful) >> 0;
    /* Possibly sign extend */
    if (0 && (ret & (1ul << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC void
seL4_Fault_CapFault_ptr_set_LookupFailureType(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint32 v) {
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0x7) ==
           seL4_Fault_CapFault);

    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xfffffffful >> 0) | 0x0) & v) == ((0 && (v & (1ul << (31)))) ? 0x0 : 0));

    seL4_Fault_ptr->words[4] &= ~0xfffffffful;
    seL4_Fault_ptr->words[4] |= (v << 0) & 0xfffffffful;
}

LIBSEL4_INLINE_FUNC seL4_Uint32 CONST
seL4_Fault_CapFault_get_MR4(seL4_Fault_t seL4_Fault) {
    seL4_Uint32 ret;
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0x7) ==
           seL4_Fault_CapFault);

    ret = (seL4_Fault.words[3] & 0xfffffffful) >> 0;
    /* Possibly sign extend */
    if (0 && (ret & (1ul << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC seL4_Fault_t CONST
seL4_Fault_CapFault_set_MR4(seL4_Fault_t seL4_Fault, seL4_Uint32 v) {
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0x7) ==
           seL4_Fault_CapFault);
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xfffffffful >> 0 ) | 0x0) & v) == ((0 && (v & (1ul << (31)))) ? 0x0 : 0));

    seL4_Fault.words[3] &= ~0xfffffffful;
    seL4_Fault.words[3] |= (v << 0) & 0xfffffffful;
    return seL4_Fault;
}

LIBSEL4_INLINE_FUNC seL4_Uint32 PURE
seL4_Fault_CapFault_ptr_get_MR4(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint32 ret;
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0x7) ==
           seL4_Fault_CapFault);

    ret = (seL4_Fault_ptr->words[3] & 0xfffffffful) >> 0;
    /* Possibly sign extend */
    if (0 && (ret & (1ul << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC void
seL4_Fault_CapFault_ptr_set_MR4(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint32 v) {
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0x7) ==
           seL4_Fault_CapFault);

    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xfffffffful >> 0) | 0x0) & v) == ((0 && (v & (1ul << (31)))) ? 0x0 : 0));

    seL4_Fault_ptr->words[3] &= ~0xfffffffful;
    seL4_Fault_ptr->words[3] |= (v << 0) & 0xfffffffful;
}

LIBSEL4_INLINE_FUNC seL4_Uint32 CONST
seL4_Fault_CapFault_get_MR5(seL4_Fault_t seL4_Fault) {
    seL4_Uint32 ret;
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0x7) ==
           seL4_Fault_CapFault);

    ret = (seL4_Fault.words[2] & 0xfffffffful) >> 0;
    /* Possibly sign extend */
    if (0 && (ret & (1ul << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC seL4_Fault_t CONST
seL4_Fault_CapFault_set_MR5(seL4_Fault_t seL4_Fault, seL4_Uint32 v) {
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0x7) ==
           seL4_Fault_CapFault);
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xfffffffful >> 0 ) | 0x0) & v) == ((0 && (v & (1ul << (31)))) ? 0x0 : 0));

    seL4_Fault.words[2] &= ~0xfffffffful;
    seL4_Fault.words[2] |= (v << 0) & 0xfffffffful;
    return seL4_Fault;
}

LIBSEL4_INLINE_FUNC seL4_Uint32 PURE
seL4_Fault_CapFault_ptr_get_MR5(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint32 ret;
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0x7) ==
           seL4_Fault_CapFault);

    ret = (seL4_Fault_ptr->words[2] & 0xfffffffful) >> 0;
    /* Possibly sign extend */
    if (0 && (ret & (1ul << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC void
seL4_Fault_CapFault_ptr_set_MR5(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint32 v) {
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0x7) ==
           seL4_Fault_CapFault);

    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xfffffffful >> 0) | 0x0) & v) == ((0 && (v & (1ul << (31)))) ? 0x0 : 0));

    seL4_Fault_ptr->words[2] &= ~0xfffffffful;
    seL4_Fault_ptr->words[2] |= (v << 0) & 0xfffffffful;
}

LIBSEL4_INLINE_FUNC seL4_Uint32 CONST
seL4_Fault_CapFault_get_MR6(seL4_Fault_t seL4_Fault) {
    seL4_Uint32 ret;
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0x7) ==
           seL4_Fault_CapFault);

    ret = (seL4_Fault.words[1] & 0xfffffffful) >> 0;
    /* Possibly sign extend */
    if (0 && (ret & (1ul << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC seL4_Fault_t CONST
seL4_Fault_CapFault_set_MR6(seL4_Fault_t seL4_Fault, seL4_Uint32 v) {
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0x7) ==
           seL4_Fault_CapFault);
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xfffffffful >> 0 ) | 0x0) & v) == ((0 && (v & (1ul << (31)))) ? 0x0 : 0));

    seL4_Fault.words[1] &= ~0xfffffffful;
    seL4_Fault.words[1] |= (v << 0) & 0xfffffffful;
    return seL4_Fault;
}

LIBSEL4_INLINE_FUNC seL4_Uint32 PURE
seL4_Fault_CapFault_ptr_get_MR6(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint32 ret;
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0x7) ==
           seL4_Fault_CapFault);

    ret = (seL4_Fault_ptr->words[1] & 0xfffffffful) >> 0;
    /* Possibly sign extend */
    if (0 && (ret & (1ul << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC void
seL4_Fault_CapFault_ptr_set_MR6(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint32 v) {
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0x7) ==
           seL4_Fault_CapFault);

    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xfffffffful >> 0) | 0x0) & v) == ((0 && (v & (1ul << (31)))) ? 0x0 : 0));

    seL4_Fault_ptr->words[1] &= ~0xfffffffful;
    seL4_Fault_ptr->words[1] |= (v << 0) & 0xfffffffful;
}

LIBSEL4_INLINE_FUNC seL4_Fault_t CONST
seL4_Fault_UnknownSyscall_new(seL4_Uint32 EAX, seL4_Uint32 EBX, seL4_Uint32 ECX, seL4_Uint32 EDX, seL4_Uint32 ESI, seL4_Uint32 EDI, seL4_Uint32 EBP, seL4_Uint32 FaultIP, seL4_Uint32 ESP, seL4_Uint32 EFLAGS, seL4_Uint32 Syscall) {
    seL4_Fault_t seL4_Fault;

    seL4_Fault.words[0] = 0;
    seL4_Fault.words[1] = 0;
    seL4_Fault.words[2] = 0;
    seL4_Fault.words[3] = 0;
    seL4_Fault.words[4] = 0;
    seL4_Fault.words[5] = 0;
    seL4_Fault.words[6] = 0;
    seL4_Fault.words[7] = 0;
    seL4_Fault.words[8] = 0;
    seL4_Fault.words[9] = 0;
    seL4_Fault.words[10] = 0;
    seL4_Fault.words[11] = 0;

       seL4_Fault.words[11] |= EAX << 0;
       seL4_Fault.words[10] |= EBX << 0;
       seL4_Fault.words[9] |= ECX << 0;
       seL4_Fault.words[8] |= EDX << 0;
       seL4_Fault.words[7] |= ESI << 0;
       seL4_Fault.words[6] |= EDI << 0;
       seL4_Fault.words[5] |= EBP << 0;
       seL4_Fault.words[4] |= FaultIP << 0;
       seL4_Fault.words[3] |= ESP << 0;
       seL4_Fault.words[2] |= EFLAGS << 0;
       seL4_Fault.words[1] |= Syscall << 0;
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert(((seL4_Uint32)seL4_Fault_UnknownSyscall & ~0x7ul) == ((0 && ((seL4_Uint32)seL4_Fault_UnknownSyscall & (1ul << 31))) ? 0x0 : 0));
    seL4_Fault.words[0] |= ((seL4_Uint32)seL4_Fault_UnknownSyscall & 0x7ul) << 0;

    return seL4_Fault;
}

LIBSEL4_INLINE_FUNC void
seL4_Fault_UnknownSyscall_ptr_new(seL4_Fault_t *seL4_Fault_ptr, seL4_Uint32 EAX, seL4_Uint32 EBX, seL4_Uint32 ECX, seL4_Uint32 EDX, seL4_Uint32 ESI, seL4_Uint32 EDI, seL4_Uint32 EBP, seL4_Uint32 FaultIP, seL4_Uint32 ESP, seL4_Uint32 EFLAGS, seL4_Uint32 Syscall) {
    seL4_Fault_ptr->words[0] = 0;
    seL4_Fault_ptr->words[1] = 0;
    seL4_Fault_ptr->words[2] = 0;
    seL4_Fault_ptr->words[3] = 0;
    seL4_Fault_ptr->words[4] = 0;
    seL4_Fault_ptr->words[5] = 0;
    seL4_Fault_ptr->words[6] = 0;
    seL4_Fault_ptr->words[7] = 0;
    seL4_Fault_ptr->words[8] = 0;
    seL4_Fault_ptr->words[9] = 0;
    seL4_Fault_ptr->words[10] = 0;
    seL4_Fault_ptr->words[11] = 0;

    seL4_Fault_ptr->words[11] |= EAX << 0;
    seL4_Fault_ptr->words[10] |= EBX << 0;
    seL4_Fault_ptr->words[9] |= ECX << 0;
    seL4_Fault_ptr->words[8] |= EDX << 0;
    seL4_Fault_ptr->words[7] |= ESI << 0;
    seL4_Fault_ptr->words[6] |= EDI << 0;
    seL4_Fault_ptr->words[5] |= EBP << 0;
    seL4_Fault_ptr->words[4] |= FaultIP << 0;
    seL4_Fault_ptr->words[3] |= ESP << 0;
    seL4_Fault_ptr->words[2] |= EFLAGS << 0;
    seL4_Fault_ptr->words[1] |= Syscall << 0;
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert(((seL4_Uint32)seL4_Fault_UnknownSyscall & ~0x7ul) == ((0 && ((seL4_Uint32)seL4_Fault_UnknownSyscall & (1ul << 31))) ? 0x0 : 0));
    seL4_Fault_ptr->words[0] |= ((seL4_Uint32)seL4_Fault_UnknownSyscall & 0x7ul) << 0;
}

LIBSEL4_INLINE_FUNC seL4_Uint32 CONST
seL4_Fault_UnknownSyscall_get_EAX(seL4_Fault_t seL4_Fault) {
    seL4_Uint32 ret;
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0x7) ==
           seL4_Fault_UnknownSyscall);

    ret = (seL4_Fault.words[11] & 0xfffffffful) >> 0;
    /* Possibly sign extend */
    if (0 && (ret & (1ul << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC seL4_Fault_t CONST
seL4_Fault_UnknownSyscall_set_EAX(seL4_Fault_t seL4_Fault, seL4_Uint32 v) {
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0x7) ==
           seL4_Fault_UnknownSyscall);
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xfffffffful >> 0 ) | 0x0) & v) == ((0 && (v & (1ul << (31)))) ? 0x0 : 0));

    seL4_Fault.words[11] &= ~0xfffffffful;
    seL4_Fault.words[11] |= (v << 0) & 0xfffffffful;
    return seL4_Fault;
}

LIBSEL4_INLINE_FUNC seL4_Uint32 PURE
seL4_Fault_UnknownSyscall_ptr_get_EAX(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint32 ret;
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0x7) ==
           seL4_Fault_UnknownSyscall);

    ret = (seL4_Fault_ptr->words[11] & 0xfffffffful) >> 0;
    /* Possibly sign extend */
    if (0 && (ret & (1ul << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC void
seL4_Fault_UnknownSyscall_ptr_set_EAX(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint32 v) {
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0x7) ==
           seL4_Fault_UnknownSyscall);

    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xfffffffful >> 0) | 0x0) & v) == ((0 && (v & (1ul << (31)))) ? 0x0 : 0));

    seL4_Fault_ptr->words[11] &= ~0xfffffffful;
    seL4_Fault_ptr->words[11] |= (v << 0) & 0xfffffffful;
}

LIBSEL4_INLINE_FUNC seL4_Uint32 CONST
seL4_Fault_UnknownSyscall_get_EBX(seL4_Fault_t seL4_Fault) {
    seL4_Uint32 ret;
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0x7) ==
           seL4_Fault_UnknownSyscall);

    ret = (seL4_Fault.words[10] & 0xfffffffful) >> 0;
    /* Possibly sign extend */
    if (0 && (ret & (1ul << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC seL4_Fault_t CONST
seL4_Fault_UnknownSyscall_set_EBX(seL4_Fault_t seL4_Fault, seL4_Uint32 v) {
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0x7) ==
           seL4_Fault_UnknownSyscall);
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xfffffffful >> 0 ) | 0x0) & v) == ((0 && (v & (1ul << (31)))) ? 0x0 : 0));

    seL4_Fault.words[10] &= ~0xfffffffful;
    seL4_Fault.words[10] |= (v << 0) & 0xfffffffful;
    return seL4_Fault;
}

LIBSEL4_INLINE_FUNC seL4_Uint32 PURE
seL4_Fault_UnknownSyscall_ptr_get_EBX(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint32 ret;
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0x7) ==
           seL4_Fault_UnknownSyscall);

    ret = (seL4_Fault_ptr->words[10] & 0xfffffffful) >> 0;
    /* Possibly sign extend */
    if (0 && (ret & (1ul << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC void
seL4_Fault_UnknownSyscall_ptr_set_EBX(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint32 v) {
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0x7) ==
           seL4_Fault_UnknownSyscall);

    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xfffffffful >> 0) | 0x0) & v) == ((0 && (v & (1ul << (31)))) ? 0x0 : 0));

    seL4_Fault_ptr->words[10] &= ~0xfffffffful;
    seL4_Fault_ptr->words[10] |= (v << 0) & 0xfffffffful;
}

LIBSEL4_INLINE_FUNC seL4_Uint32 CONST
seL4_Fault_UnknownSyscall_get_ECX(seL4_Fault_t seL4_Fault) {
    seL4_Uint32 ret;
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0x7) ==
           seL4_Fault_UnknownSyscall);

    ret = (seL4_Fault.words[9] & 0xfffffffful) >> 0;
    /* Possibly sign extend */
    if (0 && (ret & (1ul << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC seL4_Fault_t CONST
seL4_Fault_UnknownSyscall_set_ECX(seL4_Fault_t seL4_Fault, seL4_Uint32 v) {
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0x7) ==
           seL4_Fault_UnknownSyscall);
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xfffffffful >> 0 ) | 0x0) & v) == ((0 && (v & (1ul << (31)))) ? 0x0 : 0));

    seL4_Fault.words[9] &= ~0xfffffffful;
    seL4_Fault.words[9] |= (v << 0) & 0xfffffffful;
    return seL4_Fault;
}

LIBSEL4_INLINE_FUNC seL4_Uint32 PURE
seL4_Fault_UnknownSyscall_ptr_get_ECX(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint32 ret;
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0x7) ==
           seL4_Fault_UnknownSyscall);

    ret = (seL4_Fault_ptr->words[9] & 0xfffffffful) >> 0;
    /* Possibly sign extend */
    if (0 && (ret & (1ul << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC void
seL4_Fault_UnknownSyscall_ptr_set_ECX(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint32 v) {
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0x7) ==
           seL4_Fault_UnknownSyscall);

    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xfffffffful >> 0) | 0x0) & v) == ((0 && (v & (1ul << (31)))) ? 0x0 : 0));

    seL4_Fault_ptr->words[9] &= ~0xfffffffful;
    seL4_Fault_ptr->words[9] |= (v << 0) & 0xfffffffful;
}

LIBSEL4_INLINE_FUNC seL4_Uint32 CONST
seL4_Fault_UnknownSyscall_get_EDX(seL4_Fault_t seL4_Fault) {
    seL4_Uint32 ret;
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0x7) ==
           seL4_Fault_UnknownSyscall);

    ret = (seL4_Fault.words[8] & 0xfffffffful) >> 0;
    /* Possibly sign extend */
    if (0 && (ret & (1ul << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC seL4_Fault_t CONST
seL4_Fault_UnknownSyscall_set_EDX(seL4_Fault_t seL4_Fault, seL4_Uint32 v) {
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0x7) ==
           seL4_Fault_UnknownSyscall);
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xfffffffful >> 0 ) | 0x0) & v) == ((0 && (v & (1ul << (31)))) ? 0x0 : 0));

    seL4_Fault.words[8] &= ~0xfffffffful;
    seL4_Fault.words[8] |= (v << 0) & 0xfffffffful;
    return seL4_Fault;
}

LIBSEL4_INLINE_FUNC seL4_Uint32 PURE
seL4_Fault_UnknownSyscall_ptr_get_EDX(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint32 ret;
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0x7) ==
           seL4_Fault_UnknownSyscall);

    ret = (seL4_Fault_ptr->words[8] & 0xfffffffful) >> 0;
    /* Possibly sign extend */
    if (0 && (ret & (1ul << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC void
seL4_Fault_UnknownSyscall_ptr_set_EDX(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint32 v) {
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0x7) ==
           seL4_Fault_UnknownSyscall);

    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xfffffffful >> 0) | 0x0) & v) == ((0 && (v & (1ul << (31)))) ? 0x0 : 0));

    seL4_Fault_ptr->words[8] &= ~0xfffffffful;
    seL4_Fault_ptr->words[8] |= (v << 0) & 0xfffffffful;
}

LIBSEL4_INLINE_FUNC seL4_Uint32 CONST
seL4_Fault_UnknownSyscall_get_ESI(seL4_Fault_t seL4_Fault) {
    seL4_Uint32 ret;
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0x7) ==
           seL4_Fault_UnknownSyscall);

    ret = (seL4_Fault.words[7] & 0xfffffffful) >> 0;
    /* Possibly sign extend */
    if (0 && (ret & (1ul << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC seL4_Fault_t CONST
seL4_Fault_UnknownSyscall_set_ESI(seL4_Fault_t seL4_Fault, seL4_Uint32 v) {
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0x7) ==
           seL4_Fault_UnknownSyscall);
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xfffffffful >> 0 ) | 0x0) & v) == ((0 && (v & (1ul << (31)))) ? 0x0 : 0));

    seL4_Fault.words[7] &= ~0xfffffffful;
    seL4_Fault.words[7] |= (v << 0) & 0xfffffffful;
    return seL4_Fault;
}

LIBSEL4_INLINE_FUNC seL4_Uint32 PURE
seL4_Fault_UnknownSyscall_ptr_get_ESI(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint32 ret;
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0x7) ==
           seL4_Fault_UnknownSyscall);

    ret = (seL4_Fault_ptr->words[7] & 0xfffffffful) >> 0;
    /* Possibly sign extend */
    if (0 && (ret & (1ul << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC void
seL4_Fault_UnknownSyscall_ptr_set_ESI(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint32 v) {
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0x7) ==
           seL4_Fault_UnknownSyscall);

    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xfffffffful >> 0) | 0x0) & v) == ((0 && (v & (1ul << (31)))) ? 0x0 : 0));

    seL4_Fault_ptr->words[7] &= ~0xfffffffful;
    seL4_Fault_ptr->words[7] |= (v << 0) & 0xfffffffful;
}

LIBSEL4_INLINE_FUNC seL4_Uint32 CONST
seL4_Fault_UnknownSyscall_get_EDI(seL4_Fault_t seL4_Fault) {
    seL4_Uint32 ret;
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0x7) ==
           seL4_Fault_UnknownSyscall);

    ret = (seL4_Fault.words[6] & 0xfffffffful) >> 0;
    /* Possibly sign extend */
    if (0 && (ret & (1ul << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC seL4_Fault_t CONST
seL4_Fault_UnknownSyscall_set_EDI(seL4_Fault_t seL4_Fault, seL4_Uint32 v) {
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0x7) ==
           seL4_Fault_UnknownSyscall);
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xfffffffful >> 0 ) | 0x0) & v) == ((0 && (v & (1ul << (31)))) ? 0x0 : 0));

    seL4_Fault.words[6] &= ~0xfffffffful;
    seL4_Fault.words[6] |= (v << 0) & 0xfffffffful;
    return seL4_Fault;
}

LIBSEL4_INLINE_FUNC seL4_Uint32 PURE
seL4_Fault_UnknownSyscall_ptr_get_EDI(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint32 ret;
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0x7) ==
           seL4_Fault_UnknownSyscall);

    ret = (seL4_Fault_ptr->words[6] & 0xfffffffful) >> 0;
    /* Possibly sign extend */
    if (0 && (ret & (1ul << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC void
seL4_Fault_UnknownSyscall_ptr_set_EDI(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint32 v) {
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0x7) ==
           seL4_Fault_UnknownSyscall);

    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xfffffffful >> 0) | 0x0) & v) == ((0 && (v & (1ul << (31)))) ? 0x0 : 0));

    seL4_Fault_ptr->words[6] &= ~0xfffffffful;
    seL4_Fault_ptr->words[6] |= (v << 0) & 0xfffffffful;
}

LIBSEL4_INLINE_FUNC seL4_Uint32 CONST
seL4_Fault_UnknownSyscall_get_EBP(seL4_Fault_t seL4_Fault) {
    seL4_Uint32 ret;
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0x7) ==
           seL4_Fault_UnknownSyscall);

    ret = (seL4_Fault.words[5] & 0xfffffffful) >> 0;
    /* Possibly sign extend */
    if (0 && (ret & (1ul << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC seL4_Fault_t CONST
seL4_Fault_UnknownSyscall_set_EBP(seL4_Fault_t seL4_Fault, seL4_Uint32 v) {
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0x7) ==
           seL4_Fault_UnknownSyscall);
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xfffffffful >> 0 ) | 0x0) & v) == ((0 && (v & (1ul << (31)))) ? 0x0 : 0));

    seL4_Fault.words[5] &= ~0xfffffffful;
    seL4_Fault.words[5] |= (v << 0) & 0xfffffffful;
    return seL4_Fault;
}

LIBSEL4_INLINE_FUNC seL4_Uint32 PURE
seL4_Fault_UnknownSyscall_ptr_get_EBP(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint32 ret;
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0x7) ==
           seL4_Fault_UnknownSyscall);

    ret = (seL4_Fault_ptr->words[5] & 0xfffffffful) >> 0;
    /* Possibly sign extend */
    if (0 && (ret & (1ul << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC void
seL4_Fault_UnknownSyscall_ptr_set_EBP(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint32 v) {
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0x7) ==
           seL4_Fault_UnknownSyscall);

    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xfffffffful >> 0) | 0x0) & v) == ((0 && (v & (1ul << (31)))) ? 0x0 : 0));

    seL4_Fault_ptr->words[5] &= ~0xfffffffful;
    seL4_Fault_ptr->words[5] |= (v << 0) & 0xfffffffful;
}

LIBSEL4_INLINE_FUNC seL4_Uint32 CONST
seL4_Fault_UnknownSyscall_get_FaultIP(seL4_Fault_t seL4_Fault) {
    seL4_Uint32 ret;
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0x7) ==
           seL4_Fault_UnknownSyscall);

    ret = (seL4_Fault.words[4] & 0xfffffffful) >> 0;
    /* Possibly sign extend */
    if (0 && (ret & (1ul << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC seL4_Fault_t CONST
seL4_Fault_UnknownSyscall_set_FaultIP(seL4_Fault_t seL4_Fault, seL4_Uint32 v) {
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0x7) ==
           seL4_Fault_UnknownSyscall);
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xfffffffful >> 0 ) | 0x0) & v) == ((0 && (v & (1ul << (31)))) ? 0x0 : 0));

    seL4_Fault.words[4] &= ~0xfffffffful;
    seL4_Fault.words[4] |= (v << 0) & 0xfffffffful;
    return seL4_Fault;
}

LIBSEL4_INLINE_FUNC seL4_Uint32 PURE
seL4_Fault_UnknownSyscall_ptr_get_FaultIP(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint32 ret;
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0x7) ==
           seL4_Fault_UnknownSyscall);

    ret = (seL4_Fault_ptr->words[4] & 0xfffffffful) >> 0;
    /* Possibly sign extend */
    if (0 && (ret & (1ul << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC void
seL4_Fault_UnknownSyscall_ptr_set_FaultIP(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint32 v) {
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0x7) ==
           seL4_Fault_UnknownSyscall);

    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xfffffffful >> 0) | 0x0) & v) == ((0 && (v & (1ul << (31)))) ? 0x0 : 0));

    seL4_Fault_ptr->words[4] &= ~0xfffffffful;
    seL4_Fault_ptr->words[4] |= (v << 0) & 0xfffffffful;
}

LIBSEL4_INLINE_FUNC seL4_Uint32 CONST
seL4_Fault_UnknownSyscall_get_ESP(seL4_Fault_t seL4_Fault) {
    seL4_Uint32 ret;
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0x7) ==
           seL4_Fault_UnknownSyscall);

    ret = (seL4_Fault.words[3] & 0xfffffffful) >> 0;
    /* Possibly sign extend */
    if (0 && (ret & (1ul << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC seL4_Fault_t CONST
seL4_Fault_UnknownSyscall_set_ESP(seL4_Fault_t seL4_Fault, seL4_Uint32 v) {
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0x7) ==
           seL4_Fault_UnknownSyscall);
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xfffffffful >> 0 ) | 0x0) & v) == ((0 && (v & (1ul << (31)))) ? 0x0 : 0));

    seL4_Fault.words[3] &= ~0xfffffffful;
    seL4_Fault.words[3] |= (v << 0) & 0xfffffffful;
    return seL4_Fault;
}

LIBSEL4_INLINE_FUNC seL4_Uint32 PURE
seL4_Fault_UnknownSyscall_ptr_get_ESP(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint32 ret;
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0x7) ==
           seL4_Fault_UnknownSyscall);

    ret = (seL4_Fault_ptr->words[3] & 0xfffffffful) >> 0;
    /* Possibly sign extend */
    if (0 && (ret & (1ul << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC void
seL4_Fault_UnknownSyscall_ptr_set_ESP(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint32 v) {
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0x7) ==
           seL4_Fault_UnknownSyscall);

    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xfffffffful >> 0) | 0x0) & v) == ((0 && (v & (1ul << (31)))) ? 0x0 : 0));

    seL4_Fault_ptr->words[3] &= ~0xfffffffful;
    seL4_Fault_ptr->words[3] |= (v << 0) & 0xfffffffful;
}

LIBSEL4_INLINE_FUNC seL4_Uint32 CONST
seL4_Fault_UnknownSyscall_get_EFLAGS(seL4_Fault_t seL4_Fault) {
    seL4_Uint32 ret;
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0x7) ==
           seL4_Fault_UnknownSyscall);

    ret = (seL4_Fault.words[2] & 0xfffffffful) >> 0;
    /* Possibly sign extend */
    if (0 && (ret & (1ul << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC seL4_Fault_t CONST
seL4_Fault_UnknownSyscall_set_EFLAGS(seL4_Fault_t seL4_Fault, seL4_Uint32 v) {
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0x7) ==
           seL4_Fault_UnknownSyscall);
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xfffffffful >> 0 ) | 0x0) & v) == ((0 && (v & (1ul << (31)))) ? 0x0 : 0));

    seL4_Fault.words[2] &= ~0xfffffffful;
    seL4_Fault.words[2] |= (v << 0) & 0xfffffffful;
    return seL4_Fault;
}

LIBSEL4_INLINE_FUNC seL4_Uint32 PURE
seL4_Fault_UnknownSyscall_ptr_get_EFLAGS(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint32 ret;
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0x7) ==
           seL4_Fault_UnknownSyscall);

    ret = (seL4_Fault_ptr->words[2] & 0xfffffffful) >> 0;
    /* Possibly sign extend */
    if (0 && (ret & (1ul << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC void
seL4_Fault_UnknownSyscall_ptr_set_EFLAGS(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint32 v) {
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0x7) ==
           seL4_Fault_UnknownSyscall);

    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xfffffffful >> 0) | 0x0) & v) == ((0 && (v & (1ul << (31)))) ? 0x0 : 0));

    seL4_Fault_ptr->words[2] &= ~0xfffffffful;
    seL4_Fault_ptr->words[2] |= (v << 0) & 0xfffffffful;
}

LIBSEL4_INLINE_FUNC seL4_Uint32 CONST
seL4_Fault_UnknownSyscall_get_Syscall(seL4_Fault_t seL4_Fault) {
    seL4_Uint32 ret;
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0x7) ==
           seL4_Fault_UnknownSyscall);

    ret = (seL4_Fault.words[1] & 0xfffffffful) >> 0;
    /* Possibly sign extend */
    if (0 && (ret & (1ul << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC seL4_Fault_t CONST
seL4_Fault_UnknownSyscall_set_Syscall(seL4_Fault_t seL4_Fault, seL4_Uint32 v) {
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0x7) ==
           seL4_Fault_UnknownSyscall);
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xfffffffful >> 0 ) | 0x0) & v) == ((0 && (v & (1ul << (31)))) ? 0x0 : 0));

    seL4_Fault.words[1] &= ~0xfffffffful;
    seL4_Fault.words[1] |= (v << 0) & 0xfffffffful;
    return seL4_Fault;
}

LIBSEL4_INLINE_FUNC seL4_Uint32 PURE
seL4_Fault_UnknownSyscall_ptr_get_Syscall(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint32 ret;
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0x7) ==
           seL4_Fault_UnknownSyscall);

    ret = (seL4_Fault_ptr->words[1] & 0xfffffffful) >> 0;
    /* Possibly sign extend */
    if (0 && (ret & (1ul << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC void
seL4_Fault_UnknownSyscall_ptr_set_Syscall(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint32 v) {
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0x7) ==
           seL4_Fault_UnknownSyscall);

    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xfffffffful >> 0) | 0x0) & v) == ((0 && (v & (1ul << (31)))) ? 0x0 : 0));

    seL4_Fault_ptr->words[1] &= ~0xfffffffful;
    seL4_Fault_ptr->words[1] |= (v << 0) & 0xfffffffful;
}

LIBSEL4_INLINE_FUNC seL4_Fault_t CONST
seL4_Fault_UserException_new(seL4_Uint32 FaultIP, seL4_Uint32 Stack, seL4_Uint32 EFLAGS, seL4_Uint32 Number, seL4_Uint32 Code) {
    seL4_Fault_t seL4_Fault;

    seL4_Fault.words[0] = 0;
    seL4_Fault.words[1] = 0;
    seL4_Fault.words[2] = 0;
    seL4_Fault.words[3] = 0;
    seL4_Fault.words[4] = 0;
    seL4_Fault.words[5] = 0;
    seL4_Fault.words[6] = 0;
    seL4_Fault.words[7] = 0;
    seL4_Fault.words[8] = 0;
    seL4_Fault.words[9] = 0;
    seL4_Fault.words[10] = 0;
    seL4_Fault.words[11] = 0;

       seL4_Fault.words[5] |= FaultIP << 0;
       seL4_Fault.words[4] |= Stack << 0;
       seL4_Fault.words[3] |= EFLAGS << 0;
       seL4_Fault.words[2] |= Number << 0;
       seL4_Fault.words[1] |= Code << 0;
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert(((seL4_Uint32)seL4_Fault_UserException & ~0x7ul) == ((0 && ((seL4_Uint32)seL4_Fault_UserException & (1ul << 31))) ? 0x0 : 0));
    seL4_Fault.words[0] |= ((seL4_Uint32)seL4_Fault_UserException & 0x7ul) << 0;

    return seL4_Fault;
}

LIBSEL4_INLINE_FUNC void
seL4_Fault_UserException_ptr_new(seL4_Fault_t *seL4_Fault_ptr, seL4_Uint32 FaultIP, seL4_Uint32 Stack, seL4_Uint32 EFLAGS, seL4_Uint32 Number, seL4_Uint32 Code) {
    seL4_Fault_ptr->words[0] = 0;
    seL4_Fault_ptr->words[1] = 0;
    seL4_Fault_ptr->words[2] = 0;
    seL4_Fault_ptr->words[3] = 0;
    seL4_Fault_ptr->words[4] = 0;
    seL4_Fault_ptr->words[5] = 0;
    seL4_Fault_ptr->words[6] = 0;
    seL4_Fault_ptr->words[7] = 0;
    seL4_Fault_ptr->words[8] = 0;
    seL4_Fault_ptr->words[9] = 0;
    seL4_Fault_ptr->words[10] = 0;
    seL4_Fault_ptr->words[11] = 0;

    seL4_Fault_ptr->words[5] |= FaultIP << 0;
    seL4_Fault_ptr->words[4] |= Stack << 0;
    seL4_Fault_ptr->words[3] |= EFLAGS << 0;
    seL4_Fault_ptr->words[2] |= Number << 0;
    seL4_Fault_ptr->words[1] |= Code << 0;
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert(((seL4_Uint32)seL4_Fault_UserException & ~0x7ul) == ((0 && ((seL4_Uint32)seL4_Fault_UserException & (1ul << 31))) ? 0x0 : 0));
    seL4_Fault_ptr->words[0] |= ((seL4_Uint32)seL4_Fault_UserException & 0x7ul) << 0;
}

LIBSEL4_INLINE_FUNC seL4_Uint32 CONST
seL4_Fault_UserException_get_FaultIP(seL4_Fault_t seL4_Fault) {
    seL4_Uint32 ret;
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0x7) ==
           seL4_Fault_UserException);

    ret = (seL4_Fault.words[5] & 0xfffffffful) >> 0;
    /* Possibly sign extend */
    if (0 && (ret & (1ul << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC seL4_Fault_t CONST
seL4_Fault_UserException_set_FaultIP(seL4_Fault_t seL4_Fault, seL4_Uint32 v) {
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0x7) ==
           seL4_Fault_UserException);
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xfffffffful >> 0 ) | 0x0) & v) == ((0 && (v & (1ul << (31)))) ? 0x0 : 0));

    seL4_Fault.words[5] &= ~0xfffffffful;
    seL4_Fault.words[5] |= (v << 0) & 0xfffffffful;
    return seL4_Fault;
}

LIBSEL4_INLINE_FUNC seL4_Uint32 PURE
seL4_Fault_UserException_ptr_get_FaultIP(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint32 ret;
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0x7) ==
           seL4_Fault_UserException);

    ret = (seL4_Fault_ptr->words[5] & 0xfffffffful) >> 0;
    /* Possibly sign extend */
    if (0 && (ret & (1ul << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC void
seL4_Fault_UserException_ptr_set_FaultIP(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint32 v) {
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0x7) ==
           seL4_Fault_UserException);

    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xfffffffful >> 0) | 0x0) & v) == ((0 && (v & (1ul << (31)))) ? 0x0 : 0));

    seL4_Fault_ptr->words[5] &= ~0xfffffffful;
    seL4_Fault_ptr->words[5] |= (v << 0) & 0xfffffffful;
}

LIBSEL4_INLINE_FUNC seL4_Uint32 CONST
seL4_Fault_UserException_get_Stack(seL4_Fault_t seL4_Fault) {
    seL4_Uint32 ret;
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0x7) ==
           seL4_Fault_UserException);

    ret = (seL4_Fault.words[4] & 0xfffffffful) >> 0;
    /* Possibly sign extend */
    if (0 && (ret & (1ul << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC seL4_Fault_t CONST
seL4_Fault_UserException_set_Stack(seL4_Fault_t seL4_Fault, seL4_Uint32 v) {
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0x7) ==
           seL4_Fault_UserException);
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xfffffffful >> 0 ) | 0x0) & v) == ((0 && (v & (1ul << (31)))) ? 0x0 : 0));

    seL4_Fault.words[4] &= ~0xfffffffful;
    seL4_Fault.words[4] |= (v << 0) & 0xfffffffful;
    return seL4_Fault;
}

LIBSEL4_INLINE_FUNC seL4_Uint32 PURE
seL4_Fault_UserException_ptr_get_Stack(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint32 ret;
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0x7) ==
           seL4_Fault_UserException);

    ret = (seL4_Fault_ptr->words[4] & 0xfffffffful) >> 0;
    /* Possibly sign extend */
    if (0 && (ret & (1ul << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC void
seL4_Fault_UserException_ptr_set_Stack(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint32 v) {
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0x7) ==
           seL4_Fault_UserException);

    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xfffffffful >> 0) | 0x0) & v) == ((0 && (v & (1ul << (31)))) ? 0x0 : 0));

    seL4_Fault_ptr->words[4] &= ~0xfffffffful;
    seL4_Fault_ptr->words[4] |= (v << 0) & 0xfffffffful;
}

LIBSEL4_INLINE_FUNC seL4_Uint32 CONST
seL4_Fault_UserException_get_EFLAGS(seL4_Fault_t seL4_Fault) {
    seL4_Uint32 ret;
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0x7) ==
           seL4_Fault_UserException);

    ret = (seL4_Fault.words[3] & 0xfffffffful) >> 0;
    /* Possibly sign extend */
    if (0 && (ret & (1ul << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC seL4_Fault_t CONST
seL4_Fault_UserException_set_EFLAGS(seL4_Fault_t seL4_Fault, seL4_Uint32 v) {
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0x7) ==
           seL4_Fault_UserException);
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xfffffffful >> 0 ) | 0x0) & v) == ((0 && (v & (1ul << (31)))) ? 0x0 : 0));

    seL4_Fault.words[3] &= ~0xfffffffful;
    seL4_Fault.words[3] |= (v << 0) & 0xfffffffful;
    return seL4_Fault;
}

LIBSEL4_INLINE_FUNC seL4_Uint32 PURE
seL4_Fault_UserException_ptr_get_EFLAGS(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint32 ret;
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0x7) ==
           seL4_Fault_UserException);

    ret = (seL4_Fault_ptr->words[3] & 0xfffffffful) >> 0;
    /* Possibly sign extend */
    if (0 && (ret & (1ul << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC void
seL4_Fault_UserException_ptr_set_EFLAGS(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint32 v) {
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0x7) ==
           seL4_Fault_UserException);

    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xfffffffful >> 0) | 0x0) & v) == ((0 && (v & (1ul << (31)))) ? 0x0 : 0));

    seL4_Fault_ptr->words[3] &= ~0xfffffffful;
    seL4_Fault_ptr->words[3] |= (v << 0) & 0xfffffffful;
}

LIBSEL4_INLINE_FUNC seL4_Uint32 CONST
seL4_Fault_UserException_get_Number(seL4_Fault_t seL4_Fault) {
    seL4_Uint32 ret;
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0x7) ==
           seL4_Fault_UserException);

    ret = (seL4_Fault.words[2] & 0xfffffffful) >> 0;
    /* Possibly sign extend */
    if (0 && (ret & (1ul << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC seL4_Fault_t CONST
seL4_Fault_UserException_set_Number(seL4_Fault_t seL4_Fault, seL4_Uint32 v) {
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0x7) ==
           seL4_Fault_UserException);
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xfffffffful >> 0 ) | 0x0) & v) == ((0 && (v & (1ul << (31)))) ? 0x0 : 0));

    seL4_Fault.words[2] &= ~0xfffffffful;
    seL4_Fault.words[2] |= (v << 0) & 0xfffffffful;
    return seL4_Fault;
}

LIBSEL4_INLINE_FUNC seL4_Uint32 PURE
seL4_Fault_UserException_ptr_get_Number(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint32 ret;
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0x7) ==
           seL4_Fault_UserException);

    ret = (seL4_Fault_ptr->words[2] & 0xfffffffful) >> 0;
    /* Possibly sign extend */
    if (0 && (ret & (1ul << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC void
seL4_Fault_UserException_ptr_set_Number(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint32 v) {
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0x7) ==
           seL4_Fault_UserException);

    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xfffffffful >> 0) | 0x0) & v) == ((0 && (v & (1ul << (31)))) ? 0x0 : 0));

    seL4_Fault_ptr->words[2] &= ~0xfffffffful;
    seL4_Fault_ptr->words[2] |= (v << 0) & 0xfffffffful;
}

LIBSEL4_INLINE_FUNC seL4_Uint32 CONST
seL4_Fault_UserException_get_Code(seL4_Fault_t seL4_Fault) {
    seL4_Uint32 ret;
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0x7) ==
           seL4_Fault_UserException);

    ret = (seL4_Fault.words[1] & 0xfffffffful) >> 0;
    /* Possibly sign extend */
    if (0 && (ret & (1ul << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC seL4_Fault_t CONST
seL4_Fault_UserException_set_Code(seL4_Fault_t seL4_Fault, seL4_Uint32 v) {
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0x7) ==
           seL4_Fault_UserException);
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xfffffffful >> 0 ) | 0x0) & v) == ((0 && (v & (1ul << (31)))) ? 0x0 : 0));

    seL4_Fault.words[1] &= ~0xfffffffful;
    seL4_Fault.words[1] |= (v << 0) & 0xfffffffful;
    return seL4_Fault;
}

LIBSEL4_INLINE_FUNC seL4_Uint32 PURE
seL4_Fault_UserException_ptr_get_Code(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint32 ret;
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0x7) ==
           seL4_Fault_UserException);

    ret = (seL4_Fault_ptr->words[1] & 0xfffffffful) >> 0;
    /* Possibly sign extend */
    if (0 && (ret & (1ul << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC void
seL4_Fault_UserException_ptr_set_Code(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint32 v) {
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0x7) ==
           seL4_Fault_UserException);

    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xfffffffful >> 0) | 0x0) & v) == ((0 && (v & (1ul << (31)))) ? 0x0 : 0));

    seL4_Fault_ptr->words[1] &= ~0xfffffffful;
    seL4_Fault_ptr->words[1] |= (v << 0) & 0xfffffffful;
}

LIBSEL4_INLINE_FUNC seL4_Fault_t CONST
seL4_Fault_VMFault_new(seL4_Uint32 IP, seL4_Uint32 Addr, seL4_Uint32 PrefetchFault, seL4_Uint32 FSR) {
    seL4_Fault_t seL4_Fault;

    seL4_Fault.words[0] = 0;
    seL4_Fault.words[1] = 0;
    seL4_Fault.words[2] = 0;
    seL4_Fault.words[3] = 0;
    seL4_Fault.words[4] = 0;
    seL4_Fault.words[5] = 0;
    seL4_Fault.words[6] = 0;
    seL4_Fault.words[7] = 0;
    seL4_Fault.words[8] = 0;
    seL4_Fault.words[9] = 0;
    seL4_Fault.words[10] = 0;
    seL4_Fault.words[11] = 0;

       seL4_Fault.words[4] |= IP << 0;
       seL4_Fault.words[3] |= Addr << 0;
       seL4_Fault.words[2] |= PrefetchFault << 0;
       seL4_Fault.words[1] |= FSR << 0;
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert(((seL4_Uint32)seL4_Fault_VMFault & ~0x7ul) == ((0 && ((seL4_Uint32)seL4_Fault_VMFault & (1ul << 31))) ? 0x0 : 0));
    seL4_Fault.words[0] |= ((seL4_Uint32)seL4_Fault_VMFault & 0x7ul) << 0;

    return seL4_Fault;
}

LIBSEL4_INLINE_FUNC void
seL4_Fault_VMFault_ptr_new(seL4_Fault_t *seL4_Fault_ptr, seL4_Uint32 IP, seL4_Uint32 Addr, seL4_Uint32 PrefetchFault, seL4_Uint32 FSR) {
    seL4_Fault_ptr->words[0] = 0;
    seL4_Fault_ptr->words[1] = 0;
    seL4_Fault_ptr->words[2] = 0;
    seL4_Fault_ptr->words[3] = 0;
    seL4_Fault_ptr->words[4] = 0;
    seL4_Fault_ptr->words[5] = 0;
    seL4_Fault_ptr->words[6] = 0;
    seL4_Fault_ptr->words[7] = 0;
    seL4_Fault_ptr->words[8] = 0;
    seL4_Fault_ptr->words[9] = 0;
    seL4_Fault_ptr->words[10] = 0;
    seL4_Fault_ptr->words[11] = 0;

    seL4_Fault_ptr->words[4] |= IP << 0;
    seL4_Fault_ptr->words[3] |= Addr << 0;
    seL4_Fault_ptr->words[2] |= PrefetchFault << 0;
    seL4_Fault_ptr->words[1] |= FSR << 0;
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert(((seL4_Uint32)seL4_Fault_VMFault & ~0x7ul) == ((0 && ((seL4_Uint32)seL4_Fault_VMFault & (1ul << 31))) ? 0x0 : 0));
    seL4_Fault_ptr->words[0] |= ((seL4_Uint32)seL4_Fault_VMFault & 0x7ul) << 0;
}

LIBSEL4_INLINE_FUNC seL4_Uint32 CONST
seL4_Fault_VMFault_get_IP(seL4_Fault_t seL4_Fault) {
    seL4_Uint32 ret;
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0x7) ==
           seL4_Fault_VMFault);

    ret = (seL4_Fault.words[4] & 0xfffffffful) >> 0;
    /* Possibly sign extend */
    if (0 && (ret & (1ul << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC seL4_Fault_t CONST
seL4_Fault_VMFault_set_IP(seL4_Fault_t seL4_Fault, seL4_Uint32 v) {
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0x7) ==
           seL4_Fault_VMFault);
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xfffffffful >> 0 ) | 0x0) & v) == ((0 && (v & (1ul << (31)))) ? 0x0 : 0));

    seL4_Fault.words[4] &= ~0xfffffffful;
    seL4_Fault.words[4] |= (v << 0) & 0xfffffffful;
    return seL4_Fault;
}

LIBSEL4_INLINE_FUNC seL4_Uint32 PURE
seL4_Fault_VMFault_ptr_get_IP(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint32 ret;
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0x7) ==
           seL4_Fault_VMFault);

    ret = (seL4_Fault_ptr->words[4] & 0xfffffffful) >> 0;
    /* Possibly sign extend */
    if (0 && (ret & (1ul << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC void
seL4_Fault_VMFault_ptr_set_IP(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint32 v) {
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0x7) ==
           seL4_Fault_VMFault);

    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xfffffffful >> 0) | 0x0) & v) == ((0 && (v & (1ul << (31)))) ? 0x0 : 0));

    seL4_Fault_ptr->words[4] &= ~0xfffffffful;
    seL4_Fault_ptr->words[4] |= (v << 0) & 0xfffffffful;
}

LIBSEL4_INLINE_FUNC seL4_Uint32 CONST
seL4_Fault_VMFault_get_Addr(seL4_Fault_t seL4_Fault) {
    seL4_Uint32 ret;
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0x7) ==
           seL4_Fault_VMFault);

    ret = (seL4_Fault.words[3] & 0xfffffffful) >> 0;
    /* Possibly sign extend */
    if (0 && (ret & (1ul << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC seL4_Fault_t CONST
seL4_Fault_VMFault_set_Addr(seL4_Fault_t seL4_Fault, seL4_Uint32 v) {
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0x7) ==
           seL4_Fault_VMFault);
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xfffffffful >> 0 ) | 0x0) & v) == ((0 && (v & (1ul << (31)))) ? 0x0 : 0));

    seL4_Fault.words[3] &= ~0xfffffffful;
    seL4_Fault.words[3] |= (v << 0) & 0xfffffffful;
    return seL4_Fault;
}

LIBSEL4_INLINE_FUNC seL4_Uint32 PURE
seL4_Fault_VMFault_ptr_get_Addr(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint32 ret;
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0x7) ==
           seL4_Fault_VMFault);

    ret = (seL4_Fault_ptr->words[3] & 0xfffffffful) >> 0;
    /* Possibly sign extend */
    if (0 && (ret & (1ul << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC void
seL4_Fault_VMFault_ptr_set_Addr(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint32 v) {
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0x7) ==
           seL4_Fault_VMFault);

    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xfffffffful >> 0) | 0x0) & v) == ((0 && (v & (1ul << (31)))) ? 0x0 : 0));

    seL4_Fault_ptr->words[3] &= ~0xfffffffful;
    seL4_Fault_ptr->words[3] |= (v << 0) & 0xfffffffful;
}

LIBSEL4_INLINE_FUNC seL4_Uint32 CONST
seL4_Fault_VMFault_get_PrefetchFault(seL4_Fault_t seL4_Fault) {
    seL4_Uint32 ret;
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0x7) ==
           seL4_Fault_VMFault);

    ret = (seL4_Fault.words[2] & 0xfffffffful) >> 0;
    /* Possibly sign extend */
    if (0 && (ret & (1ul << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC seL4_Fault_t CONST
seL4_Fault_VMFault_set_PrefetchFault(seL4_Fault_t seL4_Fault, seL4_Uint32 v) {
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0x7) ==
           seL4_Fault_VMFault);
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xfffffffful >> 0 ) | 0x0) & v) == ((0 && (v & (1ul << (31)))) ? 0x0 : 0));

    seL4_Fault.words[2] &= ~0xfffffffful;
    seL4_Fault.words[2] |= (v << 0) & 0xfffffffful;
    return seL4_Fault;
}

LIBSEL4_INLINE_FUNC seL4_Uint32 PURE
seL4_Fault_VMFault_ptr_get_PrefetchFault(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint32 ret;
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0x7) ==
           seL4_Fault_VMFault);

    ret = (seL4_Fault_ptr->words[2] & 0xfffffffful) >> 0;
    /* Possibly sign extend */
    if (0 && (ret & (1ul << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC void
seL4_Fault_VMFault_ptr_set_PrefetchFault(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint32 v) {
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0x7) ==
           seL4_Fault_VMFault);

    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xfffffffful >> 0) | 0x0) & v) == ((0 && (v & (1ul << (31)))) ? 0x0 : 0));

    seL4_Fault_ptr->words[2] &= ~0xfffffffful;
    seL4_Fault_ptr->words[2] |= (v << 0) & 0xfffffffful;
}

LIBSEL4_INLINE_FUNC seL4_Uint32 CONST
seL4_Fault_VMFault_get_FSR(seL4_Fault_t seL4_Fault) {
    seL4_Uint32 ret;
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0x7) ==
           seL4_Fault_VMFault);

    ret = (seL4_Fault.words[1] & 0xfffffffful) >> 0;
    /* Possibly sign extend */
    if (0 && (ret & (1ul << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC seL4_Fault_t CONST
seL4_Fault_VMFault_set_FSR(seL4_Fault_t seL4_Fault, seL4_Uint32 v) {
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0x7) ==
           seL4_Fault_VMFault);
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xfffffffful >> 0 ) | 0x0) & v) == ((0 && (v & (1ul << (31)))) ? 0x0 : 0));

    seL4_Fault.words[1] &= ~0xfffffffful;
    seL4_Fault.words[1] |= (v << 0) & 0xfffffffful;
    return seL4_Fault;
}

LIBSEL4_INLINE_FUNC seL4_Uint32 PURE
seL4_Fault_VMFault_ptr_get_FSR(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint32 ret;
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0x7) ==
           seL4_Fault_VMFault);

    ret = (seL4_Fault_ptr->words[1] & 0xfffffffful) >> 0;
    /* Possibly sign extend */
    if (0 && (ret & (1ul << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC void
seL4_Fault_VMFault_ptr_set_FSR(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint32 v) {
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0x7) ==
           seL4_Fault_VMFault);

    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xfffffffful >> 0) | 0x0) & v) == ((0 && (v & (1ul << (31)))) ? 0x0 : 0));

    seL4_Fault_ptr->words[1] &= ~0xfffffffful;
    seL4_Fault_ptr->words[1] |= (v << 0) & 0xfffffffful;
}

#endif
