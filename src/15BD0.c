#include "common.h"

#define ALIGN_64(x) (((x) + 0x3F) & ~0x3F)
typedef struct unk3 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
} unk3;

void func_8003A7D0(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/15BD0/func_8003A7D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/15BD0/func_8003A864.s")

void* func_8003A91C(u32 arg0, s32 arg1) {
    unk3* temp_v0;
    s32 temp;

    temp_v0 = (unk3*)ALIGN_64(arg0);
    temp_v0->unk0 = ALIGN_64((u32)arg1 - (u32)temp_v0 + arg0) | 1; //what is this doing?
    temp_v0->unk4 = 0;
    temp_v0->unk8 = 0;
    return temp_v0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/15BD0/func_8003A94C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/15BD0/func_8003A97C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/15BD0/func_8003A998.s")

#pragma GLOBAL_ASM("asm/nonmatchings/15BD0/func_8003AA94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/15BD0/func_8003AAC8.s")
