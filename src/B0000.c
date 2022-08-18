#include "common.h"

//#pragma GLOBAL_ASM("asm/nonmatchings/B0000/func_800D4C00.s")
s32 func_800D79E0(s32);                             /* extern */
extern s32 D_801C1BEC;

void func_800D4C00() {
    s32 temp_v0;

    temp_v0 = func_800D79E0(1);
    D_801C1BEC = 1;
    func_800D79E0(temp_v0);
}

//#pragma GLOBAL_ASM("asm/nonmatchings/B0000/func_800D4C34.s")
void func_800D4C34() {
    s32 temp_v0;

    temp_v0 = func_800D79E0(1);
    D_801C1BEC = 0;
    func_800D79E0(temp_v0);
}
