#include "common.h"

extern u8 D_80163158;
extern u8 D_80163159;
extern u8 D_8016315A;
extern u8 D_8016315B;
extern u8 D_8016315C;
extern u8 D_8016315D;
extern s8 D_8016315E;
extern s8 D_8016315F;
extern s8 D_80163160;

void func_80033390(void) {
    D_80163158 = 0xB4;
    D_80163159 = 0xB4;
    D_8016315A = 0x96;
    D_8016315B = 0xFF;
    D_8016315C = 0xFF;
    D_8016315D = 0xFF;
    D_8016315E = 0x45;
    D_8016315F = 0x45;
    D_80163160 = 0x45;
}

extern unk_80163130 D_80163130;

void func_800333EC(void) {
    u8 temp_a0;
    u8 temp_a1;
    u8 temp_a2;
    u8 temp_a3;
    u8 temp_v0;
    u8 temp_v1;

    temp_v0 = D_80163158;
    D_80163130.unk0 = temp_v0;
    temp_v1 = D_80163159;
    D_80163130.unk1 = temp_v1;
    temp_a0 = D_8016315A;
    D_80163130.unk4 = temp_v0;
    D_80163130.unk5 = temp_v1;
    D_80163130.unk2 = temp_a0;
    D_80163130.unk6 = temp_a0;
    temp_a1 = D_8016315B;
    D_80163130.unk8 = temp_a1;
    temp_a2 = D_8016315C;
    D_80163130.unk9 = temp_a2;
    temp_a3 = D_8016315D;
    D_80163130.unkC = temp_a1;
    D_80163130.unkD = temp_a2;
    D_80163130.unkA = temp_a3;
    D_80163130.unkE = temp_a3;
    D_80163130.unk10 = D_8016315E;
    D_80163130.unk11 = D_8016315F;
    D_80163130.unk12 = D_80163160;
}

extern f32 D_80163164;
extern f32 D_80163168;
extern f32 D_8016316C;
extern f32 D_80163170;
extern f32 D_80163174;
extern f32 D_8016317C;
extern f32 D_80163180;
extern s16 D_80163184;

void func_8003347C(void) {
    D_80163164 = 0.0f;
    D_80163168 = 0.0f;
    D_80163170 = 0.0f;
    D_80163174 = 0.0f;
    D_8016316C = 0.0f;
    D_8016317C = 0.0f;
    D_80163180 = 0.0f;
    D_80163184 = 0;
}

extern unk_801630D8 D_801630D8;
extern f32 D_80163164;
extern f32 D_80163168;
extern f32 D_8016316C;
extern f32 D_80163170;
extern f32 D_8016317C;
extern f32 D_80163180;

void func_800334C4(void) {
    f32 temp_f0;
    f32 temp_f2;

    D_801630D8.unk0 = (f32) D_80163164;
    temp_f0 = D_80163168;
    D_801630D8.unk4 = D_80163168;
    temp_f2 = D_8016316C;
    D_801630D8.unk8 = temp_f2;
    D_801630D8.unkC = (f32) D_80163170;
    D_801630D8.unk10 = temp_f0;
    D_801630D8.unk14 = temp_f2;
    D_801630D8.unk18 = (f32) D_8016317C;
    D_801630D8.unk1C = (f32) D_80163180;
}

#pragma GLOBAL_ASM("asm/nonmatchings/E790/func_80033520.s")
//void func_80033520(unk_80163030* arg0, unk_80163030* arg1) {
//    arg0->unk8 = (u8) arg1->unk0;
//    arg0->unk9 = (u8) arg1->unk1;
//    arg0->unkA = (u8) arg1->unk2;
//    arg0->unkC = (u8) arg1->unk4;
//    arg0->unkD = (u8) arg1->unk5;
//    arg0->unkE = (u8) arg1->unk6;
//    arg0->unk10 = (s8) arg1->unk8;
//    arg0->unk11 = (s8) arg1->unk9;
//    arg0->unk12 = (s8) arg1->unkA;
//}

#pragma GLOBAL_ASM("asm/nonmatchings/E790/func_8003356C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/E790/func_80034188.s")

#pragma GLOBAL_ASM("asm/nonmatchings/E790/func_80034688.s")

#pragma GLOBAL_ASM("asm/nonmatchings/E790/func_80034784.s")

#pragma GLOBAL_ASM("asm/nonmatchings/E790/func_80035324.s")

#pragma GLOBAL_ASM("asm/nonmatchings/E790/func_800353B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/E790/func_800354BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/E790/func_80035668.s")

#pragma GLOBAL_ASM("asm/nonmatchings/E790/func_8003573C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/E790/func_80035BD8.s")
//extern s32 D_800EB30C;
//extern s32 D_801630C0;
//extern s32 D_80163110;
//extern s32 D_80163128;
//
//void func_80035BD8(void) {
//    D_80163110 = 0;
//    D_801630C0 = 0;
//    D_80163128 = 0xFFFF;
//    D_800EB30C = 0;
//}