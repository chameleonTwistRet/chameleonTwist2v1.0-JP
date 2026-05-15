#include "common.h"

typedef struct Unk3 {
    char unk0[8];
    s32* unk8;
    s32 unkC;
    char unk10[5];
    u8 unk15;
} Unk3;

void func_8002A240(char*, s32);                           /* extern */
extern Unk3 D_80160820[];

#pragma GLOBAL_ASM("asm/nonmatchings/5640/func_8002A240.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5640/func_8002A25C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5640/func_8002A640.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5640/func_8002A6A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5640/func_8002A824.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5640/func_8002A8EC.s")

s32 func_8002AA70(s32 arg0) {
    Unk3* temp_v0;
    s32* temp_v1;

    if (arg0 < 0) {
        func_8002A240("ID 未使用 \n", arg0);
        return -1;
    }
    
    temp_v0 = &D_80160820[arg0];
    if (temp_v0->unk15 == 0) {
        func_8002A240("ID 未使用 \n", arg0);
        return 1;
    }
    
    if (temp_v0->unkC == 0) {
        temp_v1 = temp_v0->unk8;
        temp_v0->unk15 = 0;
        if (temp_v1 != NULL) {
            *temp_v1 = -*temp_v1;
        }
        return 1;
    }
    return 0;
}

const char debugStr0[] = "MtxAnimOpen In\n";
const char debugStr1[] = "MtxAnimOpen Err !!  Ram Address NULL but Counter is Plus\n";
const char debugStr2[] = "Start Add %X\n";
const char debugStr3[] = "Start Add %X\n";
const char debugStr4[] = "Size  %u\n";
const char debugStr5[] = "body  %d\n";
const char debugStr6[] = "frame  %d\n";

#pragma GLOBAL_ASM("asm/nonmatchings/5640/func_8002AB10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5640/func_8002ADA8.s")
