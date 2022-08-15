#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/1B750/func_80040350.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1B750/func_800404E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1B750/func_800405CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1B750/func_8004068C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1B750/func_80040760.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1B750/func_800407D0.s")

//#pragma GLOBAL_ASM("asm/nonmatchings/1B750/func_80040840.s")
extern s32 func_8004068C;

void func_80040840(unk_func_80040840* arg0) {
    arg0->unk50 = (arg0->unk50 | 1);
    arg0->unk10 = &func_8004068C;
}

#pragma GLOBAL_ASM("asm/nonmatchings/1B750/func_8004085C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1B750/func_80040934.s")
