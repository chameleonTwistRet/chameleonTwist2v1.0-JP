#include "common.h"

extern f32 D_80160620;

#pragma GLOBAL_ASM("asm/nonmatchings/2FE0/func_80027BE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/2FE0/func_80027D94.s")

void func_80027E90(s32 arg0) {

}

void func_80027E98(unk_func_80027E98* arg0) {
    D_80160620 = arg0->unk104;
}

void func_80027EA8(unk_func_80027E98* arg0) {
    if (D_80160620 != arg0->unk104) {
        arg0->unkF2 = (arg0->unkF2 | 4);
        return;
    }
    arg0->unkF2 = (arg0->unkF2 & ~4);
}
