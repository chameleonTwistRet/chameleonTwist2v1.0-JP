#include "common.h"
#include "zlib/zutil.h"

// Global function pointers set by func_800BDE14 before calling the inflate wrapper.
// D_8018BEE0 = underlying alloc fn (items, size), D_8018BEE4 = underlying free fn (ptr).
extern voidpf (*D_8018BEE0)(uInt, uInt);
extern void   (*D_8018BEE4)(voidpf);

#pragma GLOBAL_ASM("asm/nonmatchings/99050/D_800F9860.s")

#pragma GLOBAL_ASM("asm/nonmatchings/99050/D_800F9870.s")

#pragma GLOBAL_ASM("asm/nonmatchings/99050/D_800F987C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/99050/D_800F9880.s")

#pragma GLOBAL_ASM("asm/nonmatchings/99050/D_800F988C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/99050/D_800F989C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/99050/D_800F98A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/99050/D_800F98BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/99050/D_800F98CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/99050/D_800F98E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/99050/func_800BDC50.s")

void func_800BDC5C(s32 arg0) {

}


#pragma GLOBAL_ASM("asm/nonmatchings/99050/func_800BDC64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/99050/func_800BDCD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/99050/func_800BDDC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/99050/func_800BDE14.s")

// zcalloc: strips opaque, dispatches through D_8018BEE0(items, size)
voidpf func_800BDE58(voidpf opaque, uInt items, uInt size) {
    return D_8018BEE0(items, size);
}

// zcfree: strips opaque, dispatches through D_8018BEE4(address)
void func_800BDE88(voidpf opaque, voidpf address) {
    D_8018BEE4(address);
}
