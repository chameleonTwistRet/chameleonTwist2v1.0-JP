#include "common.h"

extern s32 gzip_data_0000;
extern s32 gzip_data_0000;
extern s32 D_800EB050;
extern f32 D_800EB054;
extern f32 D_800EB058;
extern f32 D_800EB05C;
extern f32 D_800EB060;
extern s32 D_800EB070;
extern f32 D_800EB064;
extern f32 D_800EB068;
extern f32 D_800EB06C;
extern unk_80163030 D_80163030;

#pragma GLOBAL_ASM("asm/nonmatchings/8440/func_8002D040.s")

#pragma GLOBAL_ASM("asm/nonmatchings/8440/func_8002D0CC.s")

void func_8002D580(void) {
    gzip_data_0000 = 0;
}

void func_8002D58C(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    D_800EB050 = 0x1E;
    D_800EB070 = 1;
    D_800EB054 = arg0;
    D_800EB058 = arg1;
    D_800EB05C = arg2;
    D_800EB060 = arg3;
}

void func_8002D5D8(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5) {
    D_800EB050 = 0x1E;
    D_800EB070 = 0;
    D_800EB054 = arg0;
    D_800EB058 = arg1;
    D_800EB05C = arg2;
    D_800EB064 = arg3;
    D_800EB068 = arg4;
    D_800EB06C = arg5;
}

void func_8002D638(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5) {
    D_800EB050 = 0x1E;
    D_800EB070 = 0;
    D_80163030.unk54 = arg0;
    D_80163030.unk58 = arg1;
    D_80163030.unk48 = arg3;
    D_80163030.unk4C = arg4;
    D_80163030.unk50 = arg5;
    D_80163030.unk5C = arg2;
}
