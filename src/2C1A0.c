#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/2C1A0/func_80050DA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/2C1A0/func_80050F38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/2C1A0/func_80050F54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/2C1A0/func_80050F9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/2C1A0/func_80050FE0.s")

extern s16 D_801857B0;

void func_80051014(s32 arg0) {
    D_801857B0 = arg0;
}


extern f32 D_801857B4;
extern f32 D_801857B8;

void func_80051020(f32 arg0, f32 arg1) {
    D_801857B4 = arg0;
    D_801857B8 = arg1;
}


extern s16 D_801857BC;

void func_80051034(s32 arg0) {
    D_801857BC = arg0;
}


#pragma GLOBAL_ASM("asm/nonmatchings/2C1A0/func_80051040.s")

#pragma GLOBAL_ASM("asm/nonmatchings/2C1A0/func_800510A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/2C1A0/func_80051104.s")

#pragma GLOBAL_ASM("asm/nonmatchings/2C1A0/func_80051158.s")

#pragma GLOBAL_ASM("asm/nonmatchings/2C1A0/func_80051468.s")

extern s16 D_801857E0;

void func_800514FC(s32 arg0) {
    D_801857E0 = arg0;
}

extern s16 D_801857E2;
extern s16 D_801857E4;

void func_80051508(s32 arg0, s32 arg1) {
    D_801857E2 = arg0;
    D_801857E4 = arg1;
}

extern s16 D_80185794;

void func_8005151C(s32 arg0) {
    D_80185794 = arg0;
}


extern s16 D_801857E6;

void func_80051528(s32 arg0) {
    D_801857E6 = arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/2C1A0/func_80051534.s")

#pragma GLOBAL_ASM("asm/nonmatchings/2C1A0/func_80051718.s")

#pragma GLOBAL_ASM("asm/nonmatchings/2C1A0/func_800517D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/2C1A0/func_8005188C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/2C1A0/func_80051CC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/2C1A0/func_80051D58.s")

s32 func_80051E1C(s32 arg0) {
    if (arg0 & 0x80) {
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/2C1A0/func_80051E38.s")

s32 func_80051F00(s32 arg0) {
    if (arg0 == 0xA3) {
        return 1;
    }
    return 0;
}

s32 func_80051F1C(s32 arg0) {
    if ((arg0 < 0xC1) || (arg0 >= 0xDB)) {
        return 0;
    }
    return 1;
}


s32 func_80051F40(s32 arg0) {
    if ((arg0 < 0xE1) || (arg0 >= 0xFB)) {
        return 0;
    }
    return 1;
}


s32 func_80051F64(s32 arg0) {
    if ((arg0 < 0xB0) || (arg0 >= 0xBA)) {
        return 0;
    }
    return 1;
}

s32 func_80051F88(s32 arg0) {
    if (arg0 == 0xA1) {
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/2C1A0/func_80051FA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/2C1A0/func_80052068.s")

s32 func_800520B0(s32 arg0) {
    if ((arg0 >= 0x1C) && (arg0 < 0x20)) {
        return 1;
    }
    return 0;
}


#pragma GLOBAL_ASM("asm/nonmatchings/2C1A0/func_800520D8.s")