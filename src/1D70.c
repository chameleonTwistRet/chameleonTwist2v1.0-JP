#include "common.h"

extern s16 D_800EADF8;
extern s16 D_800EADFC;
extern s8 D_80160504;
extern u8 D_80160505;
extern u8 D_80160506;
extern u8 D_80160507;

#pragma GLOBAL_ASM("asm/nonmatchings/1D70/func_80026970.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1D70/func_80026A00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1D70/func_80026C00.s")

void func_80026EB0(void) {
    D_800EADF8 = 0x3B6;
    D_800EADFC = 0x3E8;
    D_80160504 = 0;
    D_80160505 = 0;
    D_80160506 = 0xFF;
    D_80160507 = 0xFF;
}

#pragma GLOBAL_ASM("asm/nonmatchings/1D70/func_80026EF0.s")
