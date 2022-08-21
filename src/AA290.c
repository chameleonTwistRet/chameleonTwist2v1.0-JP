#include "common.h"

void func_800CEE90(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/AA290/func_800CEE98.s")

void func_800D7CE0(void);                                  /* extern */
void func_800D7D10(s32, s32);                          /* extern */
extern unk_800F1CB4* D_800F1CB4;

void func_800CEEF0(s32 arg0) {
    func_800D7CE0();
    func_800D7D10(arg0, D_800F1CB4->unk0 + 0x20);
}


#pragma GLOBAL_ASM("asm/nonmatchings/AA290/func_800CEF24.s")

extern unk_800F1CB4* D_800F1CB4;

void func_800CEF88(s32* arg0) {
    *arg0 = D_800F1CB4->unk38;
    D_800F1CB4->unk38 = arg0;
}


#pragma GLOBAL_ASM("asm/nonmatchings/AA290/func_800CEFA8.s")

void func_800CEFD8(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/AA290/func_800CEFE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/AA290/func_800CF2F4.s")
