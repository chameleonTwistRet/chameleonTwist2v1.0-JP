#include "common.h"

void func_8004068C(void);
void func_8004085C(s32, s32);

#pragma GLOBAL_ASM("asm/nonmatchings/1B750/func_80040350.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1B750/func_800404E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1B750/func_800405CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1B750/func_8004068C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1B750/func_80040760.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1B750/func_800407D0.s")

void func_80040840(unk_func_80040840* arg0) {
    arg0->unk50 = (arg0->unk50 | 1);
    arg0->unk10 = (void*)&func_8004068C;
}

#pragma GLOBAL_ASM("asm/nonmatchings/1B750/func_8004085C.s")

void func_80040934(s32 arg0) {
    s32 i;

    for (i = 0; i < 2; i++) {
        func_8004085C(i * 8, arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/1B750/D_800F5DA0.s")