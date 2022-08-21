#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/A6830/func_800CB430.s")

#pragma GLOBAL_ASM("asm/nonmatchings/A6830/func_800CB4B0.s")

void func_800D2B60(unk_8019CB40*);  
extern unk_8019CB40 D_8019CB40[]; 

void func_800CB540(s32 arg0) {
    func_800D2B60(&D_8019CB40[arg0]);
}

void func_800D30E0(unk_8019CB40*);                             /* extern */

void func_800CB57C(s32 arg0) {
    func_800D30E0(&D_8019CB40[arg0]);
}