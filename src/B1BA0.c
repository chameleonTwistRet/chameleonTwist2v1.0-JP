#include "common.h"

//#pragma GLOBAL_ASM("asm/nonmatchings/B1BA0/func_800D67A0.s")
s32 func_800D79E0(s32);                             /* extern */
extern s32 D_800F1F70;

void func_800D67A0(s32 arg0) {
    s32 temp_a0;

    temp_a0 = func_800D79E0(1);
    D_800F1F70 = arg0;
    func_800D79E0(temp_a0);
}