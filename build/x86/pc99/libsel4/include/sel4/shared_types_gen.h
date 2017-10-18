#ifndef _HOME_AXJLLT_DESKTOP_SEL4TEST_BUILD_X86_PC99_LIBSEL4_INCLUDE_SEL4_SHARED_TYPES_GEN_H
#define _HOME_AXJLLT_DESKTOP_SEL4TEST_BUILD_X86_PC99_LIBSEL4_INCLUDE_SEL4_SHARED_TYPES_GEN_H

#include <autoconf.h>
#include <sel4/simple_types.h>
#include <sel4/debug_assert.h>
struct seL4_PrioProps {
    seL4_Uint32 words[1];
};
typedef struct seL4_PrioProps seL4_PrioProps_t;

LIBSEL4_INLINE_FUNC seL4_PrioProps_t CONST
seL4_PrioProps_new(seL4_Uint32 mcp, seL4_Uint32 prio) {
    seL4_PrioProps_t seL4_PrioProps;

    seL4_PrioProps.words[0] = 0;

    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((mcp & ~0xfful) == ((0 && (mcp & (1ul << 31))) ? 0x0 : 0));
    seL4_PrioProps.words[0] |= (mcp & 0xfful) << 8;
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((prio & ~0xfful) == ((0 && (prio & (1ul << 31))) ? 0x0 : 0));
    seL4_PrioProps.words[0] |= (prio & 0xfful) << 0;

    return seL4_PrioProps;
}

LIBSEL4_INLINE_FUNC void
seL4_PrioProps_ptr_new(seL4_PrioProps_t *seL4_PrioProps_ptr, seL4_Uint32 mcp, seL4_Uint32 prio) {
    seL4_PrioProps_ptr->words[0] = 0;

    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((mcp & ~0xfful) == ((0 && (mcp & (1ul << 31))) ? 0x0 : 0));
    seL4_PrioProps_ptr->words[0] |= (mcp & 0xfful) << 8;
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((prio & ~0xfful) == ((0 && (prio & (1ul << 31))) ? 0x0 : 0));
    seL4_PrioProps_ptr->words[0] |= (prio & 0xfful) << 0;
}

LIBSEL4_INLINE_FUNC seL4_Uint32 CONST
seL4_PrioProps_get_mcp(seL4_PrioProps_t seL4_PrioProps) {
    seL4_Uint32 ret;
    ret = (seL4_PrioProps.words[0] & 0xff00ul) >> 8;
    /* Possibly sign extend */
    if (0 && (ret & (1ul << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC seL4_PrioProps_t CONST
seL4_PrioProps_set_mcp(seL4_PrioProps_t seL4_PrioProps, seL4_Uint32 v) {
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xff00 >> 8 ) | 0x0) & v) == ((0 && (v & (1ul << (31)))) ? 0x0 : 0));
    seL4_PrioProps.words[0] &= ~0xff00ul;
    seL4_PrioProps.words[0] |= (v << 8) & 0xff00ul;
    return seL4_PrioProps;
}

LIBSEL4_INLINE_FUNC seL4_Uint32 PURE
seL4_PrioProps_ptr_get_mcp(seL4_PrioProps_t *seL4_PrioProps_ptr) {
    seL4_Uint32 ret;
    ret = (seL4_PrioProps_ptr->words[0] & 0xff00ul) >> 8;
    /* Possibly sign extend */
    if (0 && (ret & (1ul << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC void
seL4_PrioProps_ptr_set_mcp(seL4_PrioProps_t *seL4_PrioProps_ptr, seL4_Uint32 v) {
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xff00 >> 8) | 0x0) & v) == ((0 && (v & (1ul << (31)))) ? 0x0 : 0));
    seL4_PrioProps_ptr->words[0] &= ~0xff00ul;
    seL4_PrioProps_ptr->words[0] |= (v << 8) & 0xff00;
}

LIBSEL4_INLINE_FUNC seL4_Uint32 CONST
seL4_PrioProps_get_prio(seL4_PrioProps_t seL4_PrioProps) {
    seL4_Uint32 ret;
    ret = (seL4_PrioProps.words[0] & 0xfful) >> 0;
    /* Possibly sign extend */
    if (0 && (ret & (1ul << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC seL4_PrioProps_t CONST
seL4_PrioProps_set_prio(seL4_PrioProps_t seL4_PrioProps, seL4_Uint32 v) {
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xff >> 0 ) | 0x0) & v) == ((0 && (v & (1ul << (31)))) ? 0x0 : 0));
    seL4_PrioProps.words[0] &= ~0xfful;
    seL4_PrioProps.words[0] |= (v << 0) & 0xfful;
    return seL4_PrioProps;
}

LIBSEL4_INLINE_FUNC seL4_Uint32 PURE
seL4_PrioProps_ptr_get_prio(seL4_PrioProps_t *seL4_PrioProps_ptr) {
    seL4_Uint32 ret;
    ret = (seL4_PrioProps_ptr->words[0] & 0xfful) >> 0;
    /* Possibly sign extend */
    if (0 && (ret & (1ul << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC void
seL4_PrioProps_ptr_set_prio(seL4_PrioProps_t *seL4_PrioProps_ptr, seL4_Uint32 v) {
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xff >> 0) | 0x0) & v) == ((0 && (v & (1ul << (31)))) ? 0x0 : 0));
    seL4_PrioProps_ptr->words[0] &= ~0xfful;
    seL4_PrioProps_ptr->words[0] |= (v << 0) & 0xff;
}

struct seL4_MessageInfo {
    seL4_Uint32 words[1];
};
typedef struct seL4_MessageInfo seL4_MessageInfo_t;

LIBSEL4_INLINE_FUNC seL4_MessageInfo_t CONST
seL4_MessageInfo_new(seL4_Uint32 label, seL4_Uint32 capsUnwrapped, seL4_Uint32 extraCaps, seL4_Uint32 length) {
    seL4_MessageInfo_t seL4_MessageInfo;

    seL4_MessageInfo.words[0] = 0;

    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((label & ~0xffffful) == ((0 && (label & (1ul << 31))) ? 0x0 : 0));
    seL4_MessageInfo.words[0] |= (label & 0xffffful) << 12;
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((capsUnwrapped & ~0x7ul) == ((0 && (capsUnwrapped & (1ul << 31))) ? 0x0 : 0));
    seL4_MessageInfo.words[0] |= (capsUnwrapped & 0x7ul) << 9;
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((extraCaps & ~0x3ul) == ((0 && (extraCaps & (1ul << 31))) ? 0x0 : 0));
    seL4_MessageInfo.words[0] |= (extraCaps & 0x3ul) << 7;
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((length & ~0x7ful) == ((0 && (length & (1ul << 31))) ? 0x0 : 0));
    seL4_MessageInfo.words[0] |= (length & 0x7ful) << 0;

    return seL4_MessageInfo;
}

LIBSEL4_INLINE_FUNC void
seL4_MessageInfo_ptr_new(seL4_MessageInfo_t *seL4_MessageInfo_ptr, seL4_Uint32 label, seL4_Uint32 capsUnwrapped, seL4_Uint32 extraCaps, seL4_Uint32 length) {
    seL4_MessageInfo_ptr->words[0] = 0;

    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((label & ~0xffffful) == ((0 && (label & (1ul << 31))) ? 0x0 : 0));
    seL4_MessageInfo_ptr->words[0] |= (label & 0xffffful) << 12;
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((capsUnwrapped & ~0x7ul) == ((0 && (capsUnwrapped & (1ul << 31))) ? 0x0 : 0));
    seL4_MessageInfo_ptr->words[0] |= (capsUnwrapped & 0x7ul) << 9;
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((extraCaps & ~0x3ul) == ((0 && (extraCaps & (1ul << 31))) ? 0x0 : 0));
    seL4_MessageInfo_ptr->words[0] |= (extraCaps & 0x3ul) << 7;
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((length & ~0x7ful) == ((0 && (length & (1ul << 31))) ? 0x0 : 0));
    seL4_MessageInfo_ptr->words[0] |= (length & 0x7ful) << 0;
}

LIBSEL4_INLINE_FUNC seL4_Uint32 CONST
seL4_MessageInfo_get_label(seL4_MessageInfo_t seL4_MessageInfo) {
    seL4_Uint32 ret;
    ret = (seL4_MessageInfo.words[0] & 0xfffff000ul) >> 12;
    /* Possibly sign extend */
    if (0 && (ret & (1ul << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC seL4_MessageInfo_t CONST
seL4_MessageInfo_set_label(seL4_MessageInfo_t seL4_MessageInfo, seL4_Uint32 v) {
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xfffff000 >> 12 ) | 0x0) & v) == ((0 && (v & (1ul << (31)))) ? 0x0 : 0));
    seL4_MessageInfo.words[0] &= ~0xfffff000ul;
    seL4_MessageInfo.words[0] |= (v << 12) & 0xfffff000ul;
    return seL4_MessageInfo;
}

LIBSEL4_INLINE_FUNC seL4_Uint32 PURE
seL4_MessageInfo_ptr_get_label(seL4_MessageInfo_t *seL4_MessageInfo_ptr) {
    seL4_Uint32 ret;
    ret = (seL4_MessageInfo_ptr->words[0] & 0xfffff000ul) >> 12;
    /* Possibly sign extend */
    if (0 && (ret & (1ul << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC void
seL4_MessageInfo_ptr_set_label(seL4_MessageInfo_t *seL4_MessageInfo_ptr, seL4_Uint32 v) {
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xfffff000 >> 12) | 0x0) & v) == ((0 && (v & (1ul << (31)))) ? 0x0 : 0));
    seL4_MessageInfo_ptr->words[0] &= ~0xfffff000ul;
    seL4_MessageInfo_ptr->words[0] |= (v << 12) & 0xfffff000;
}

LIBSEL4_INLINE_FUNC seL4_Uint32 CONST
seL4_MessageInfo_get_capsUnwrapped(seL4_MessageInfo_t seL4_MessageInfo) {
    seL4_Uint32 ret;
    ret = (seL4_MessageInfo.words[0] & 0xe00ul) >> 9;
    /* Possibly sign extend */
    if (0 && (ret & (1ul << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC seL4_MessageInfo_t CONST
seL4_MessageInfo_set_capsUnwrapped(seL4_MessageInfo_t seL4_MessageInfo, seL4_Uint32 v) {
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xe00 >> 9 ) | 0x0) & v) == ((0 && (v & (1ul << (31)))) ? 0x0 : 0));
    seL4_MessageInfo.words[0] &= ~0xe00ul;
    seL4_MessageInfo.words[0] |= (v << 9) & 0xe00ul;
    return seL4_MessageInfo;
}

LIBSEL4_INLINE_FUNC seL4_Uint32 PURE
seL4_MessageInfo_ptr_get_capsUnwrapped(seL4_MessageInfo_t *seL4_MessageInfo_ptr) {
    seL4_Uint32 ret;
    ret = (seL4_MessageInfo_ptr->words[0] & 0xe00ul) >> 9;
    /* Possibly sign extend */
    if (0 && (ret & (1ul << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC void
seL4_MessageInfo_ptr_set_capsUnwrapped(seL4_MessageInfo_t *seL4_MessageInfo_ptr, seL4_Uint32 v) {
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xe00 >> 9) | 0x0) & v) == ((0 && (v & (1ul << (31)))) ? 0x0 : 0));
    seL4_MessageInfo_ptr->words[0] &= ~0xe00ul;
    seL4_MessageInfo_ptr->words[0] |= (v << 9) & 0xe00;
}

LIBSEL4_INLINE_FUNC seL4_Uint32 CONST
seL4_MessageInfo_get_extraCaps(seL4_MessageInfo_t seL4_MessageInfo) {
    seL4_Uint32 ret;
    ret = (seL4_MessageInfo.words[0] & 0x180ul) >> 7;
    /* Possibly sign extend */
    if (0 && (ret & (1ul << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC seL4_MessageInfo_t CONST
seL4_MessageInfo_set_extraCaps(seL4_MessageInfo_t seL4_MessageInfo, seL4_Uint32 v) {
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0x180 >> 7 ) | 0x0) & v) == ((0 && (v & (1ul << (31)))) ? 0x0 : 0));
    seL4_MessageInfo.words[0] &= ~0x180ul;
    seL4_MessageInfo.words[0] |= (v << 7) & 0x180ul;
    return seL4_MessageInfo;
}

LIBSEL4_INLINE_FUNC seL4_Uint32 PURE
seL4_MessageInfo_ptr_get_extraCaps(seL4_MessageInfo_t *seL4_MessageInfo_ptr) {
    seL4_Uint32 ret;
    ret = (seL4_MessageInfo_ptr->words[0] & 0x180ul) >> 7;
    /* Possibly sign extend */
    if (0 && (ret & (1ul << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC void
seL4_MessageInfo_ptr_set_extraCaps(seL4_MessageInfo_t *seL4_MessageInfo_ptr, seL4_Uint32 v) {
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0x180 >> 7) | 0x0) & v) == ((0 && (v & (1ul << (31)))) ? 0x0 : 0));
    seL4_MessageInfo_ptr->words[0] &= ~0x180ul;
    seL4_MessageInfo_ptr->words[0] |= (v << 7) & 0x180;
}

LIBSEL4_INLINE_FUNC seL4_Uint32 CONST
seL4_MessageInfo_get_length(seL4_MessageInfo_t seL4_MessageInfo) {
    seL4_Uint32 ret;
    ret = (seL4_MessageInfo.words[0] & 0x7ful) >> 0;
    /* Possibly sign extend */
    if (0 && (ret & (1ul << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC seL4_MessageInfo_t CONST
seL4_MessageInfo_set_length(seL4_MessageInfo_t seL4_MessageInfo, seL4_Uint32 v) {
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0x7f >> 0 ) | 0x0) & v) == ((0 && (v & (1ul << (31)))) ? 0x0 : 0));
    seL4_MessageInfo.words[0] &= ~0x7ful;
    seL4_MessageInfo.words[0] |= (v << 0) & 0x7ful;
    return seL4_MessageInfo;
}

LIBSEL4_INLINE_FUNC seL4_Uint32 PURE
seL4_MessageInfo_ptr_get_length(seL4_MessageInfo_t *seL4_MessageInfo_ptr) {
    seL4_Uint32 ret;
    ret = (seL4_MessageInfo_ptr->words[0] & 0x7ful) >> 0;
    /* Possibly sign extend */
    if (0 && (ret & (1ul << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC void
seL4_MessageInfo_ptr_set_length(seL4_MessageInfo_t *seL4_MessageInfo_ptr, seL4_Uint32 v) {
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0x7f >> 0) | 0x0) & v) == ((0 && (v & (1ul << (31)))) ? 0x0 : 0));
    seL4_MessageInfo_ptr->words[0] &= ~0x7ful;
    seL4_MessageInfo_ptr->words[0] |= (v << 0) & 0x7f;
}

struct seL4_CapRights {
    seL4_Uint32 words[1];
};
typedef struct seL4_CapRights seL4_CapRights_t;

LIBSEL4_INLINE_FUNC seL4_CapRights_t CONST
seL4_CapRights_new(seL4_Uint32 capAllowGrant, seL4_Uint32 capAllowRead, seL4_Uint32 capAllowWrite) {
    seL4_CapRights_t seL4_CapRights;

    seL4_CapRights.words[0] = 0;

    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((capAllowGrant & ~0x1ul) == ((0 && (capAllowGrant & (1ul << 31))) ? 0x0 : 0));
    seL4_CapRights.words[0] |= (capAllowGrant & 0x1ul) << 2;
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((capAllowRead & ~0x1ul) == ((0 && (capAllowRead & (1ul << 31))) ? 0x0 : 0));
    seL4_CapRights.words[0] |= (capAllowRead & 0x1ul) << 1;
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((capAllowWrite & ~0x1ul) == ((0 && (capAllowWrite & (1ul << 31))) ? 0x0 : 0));
    seL4_CapRights.words[0] |= (capAllowWrite & 0x1ul) << 0;

    return seL4_CapRights;
}

LIBSEL4_INLINE_FUNC void
seL4_CapRights_ptr_new(seL4_CapRights_t *seL4_CapRights_ptr, seL4_Uint32 capAllowGrant, seL4_Uint32 capAllowRead, seL4_Uint32 capAllowWrite) {
    seL4_CapRights_ptr->words[0] = 0;

    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((capAllowGrant & ~0x1ul) == ((0 && (capAllowGrant & (1ul << 31))) ? 0x0 : 0));
    seL4_CapRights_ptr->words[0] |= (capAllowGrant & 0x1ul) << 2;
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((capAllowRead & ~0x1ul) == ((0 && (capAllowRead & (1ul << 31))) ? 0x0 : 0));
    seL4_CapRights_ptr->words[0] |= (capAllowRead & 0x1ul) << 1;
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((capAllowWrite & ~0x1ul) == ((0 && (capAllowWrite & (1ul << 31))) ? 0x0 : 0));
    seL4_CapRights_ptr->words[0] |= (capAllowWrite & 0x1ul) << 0;
}

LIBSEL4_INLINE_FUNC seL4_Uint32 CONST
seL4_CapRights_get_capAllowGrant(seL4_CapRights_t seL4_CapRights) {
    seL4_Uint32 ret;
    ret = (seL4_CapRights.words[0] & 0x4ul) >> 2;
    /* Possibly sign extend */
    if (0 && (ret & (1ul << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC seL4_CapRights_t CONST
seL4_CapRights_set_capAllowGrant(seL4_CapRights_t seL4_CapRights, seL4_Uint32 v) {
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0x4 >> 2 ) | 0x0) & v) == ((0 && (v & (1ul << (31)))) ? 0x0 : 0));
    seL4_CapRights.words[0] &= ~0x4ul;
    seL4_CapRights.words[0] |= (v << 2) & 0x4ul;
    return seL4_CapRights;
}

LIBSEL4_INLINE_FUNC seL4_Uint32 PURE
seL4_CapRights_ptr_get_capAllowGrant(seL4_CapRights_t *seL4_CapRights_ptr) {
    seL4_Uint32 ret;
    ret = (seL4_CapRights_ptr->words[0] & 0x4ul) >> 2;
    /* Possibly sign extend */
    if (0 && (ret & (1ul << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC void
seL4_CapRights_ptr_set_capAllowGrant(seL4_CapRights_t *seL4_CapRights_ptr, seL4_Uint32 v) {
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0x4 >> 2) | 0x0) & v) == ((0 && (v & (1ul << (31)))) ? 0x0 : 0));
    seL4_CapRights_ptr->words[0] &= ~0x4ul;
    seL4_CapRights_ptr->words[0] |= (v << 2) & 0x4;
}

LIBSEL4_INLINE_FUNC seL4_Uint32 CONST
seL4_CapRights_get_capAllowRead(seL4_CapRights_t seL4_CapRights) {
    seL4_Uint32 ret;
    ret = (seL4_CapRights.words[0] & 0x2ul) >> 1;
    /* Possibly sign extend */
    if (0 && (ret & (1ul << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC seL4_CapRights_t CONST
seL4_CapRights_set_capAllowRead(seL4_CapRights_t seL4_CapRights, seL4_Uint32 v) {
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0x2 >> 1 ) | 0x0) & v) == ((0 && (v & (1ul << (31)))) ? 0x0 : 0));
    seL4_CapRights.words[0] &= ~0x2ul;
    seL4_CapRights.words[0] |= (v << 1) & 0x2ul;
    return seL4_CapRights;
}

LIBSEL4_INLINE_FUNC seL4_Uint32 PURE
seL4_CapRights_ptr_get_capAllowRead(seL4_CapRights_t *seL4_CapRights_ptr) {
    seL4_Uint32 ret;
    ret = (seL4_CapRights_ptr->words[0] & 0x2ul) >> 1;
    /* Possibly sign extend */
    if (0 && (ret & (1ul << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC void
seL4_CapRights_ptr_set_capAllowRead(seL4_CapRights_t *seL4_CapRights_ptr, seL4_Uint32 v) {
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0x2 >> 1) | 0x0) & v) == ((0 && (v & (1ul << (31)))) ? 0x0 : 0));
    seL4_CapRights_ptr->words[0] &= ~0x2ul;
    seL4_CapRights_ptr->words[0] |= (v << 1) & 0x2;
}

LIBSEL4_INLINE_FUNC seL4_Uint32 CONST
seL4_CapRights_get_capAllowWrite(seL4_CapRights_t seL4_CapRights) {
    seL4_Uint32 ret;
    ret = (seL4_CapRights.words[0] & 0x1ul) >> 0;
    /* Possibly sign extend */
    if (0 && (ret & (1ul << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC seL4_CapRights_t CONST
seL4_CapRights_set_capAllowWrite(seL4_CapRights_t seL4_CapRights, seL4_Uint32 v) {
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0x1 >> 0 ) | 0x0) & v) == ((0 && (v & (1ul << (31)))) ? 0x0 : 0));
    seL4_CapRights.words[0] &= ~0x1ul;
    seL4_CapRights.words[0] |= (v << 0) & 0x1ul;
    return seL4_CapRights;
}

LIBSEL4_INLINE_FUNC seL4_Uint32 PURE
seL4_CapRights_ptr_get_capAllowWrite(seL4_CapRights_t *seL4_CapRights_ptr) {
    seL4_Uint32 ret;
    ret = (seL4_CapRights_ptr->words[0] & 0x1ul) >> 0;
    /* Possibly sign extend */
    if (0 && (ret & (1ul << (31)))) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC void
seL4_CapRights_ptr_set_capAllowWrite(seL4_CapRights_t *seL4_CapRights_ptr, seL4_Uint32 v) {
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0x1 >> 0) | 0x0) & v) == ((0 && (v & (1ul << (31)))) ? 0x0 : 0));
    seL4_CapRights_ptr->words[0] &= ~0x1ul;
    seL4_CapRights_ptr->words[0] |= (v << 0) & 0x1;
}

#endif
