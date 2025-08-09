#include "common.h"

typedef struct UnkHeapStruct2 {
    /* 0x00 */ char unk_00[0x04];
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ char unk_08[8];
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
} UnkHeapStruct2;
typedef struct UnkHeapStruct {
    /* 0x00 */ char pad0[8];
    /* 0x08 */ UnkHeapStruct2* unk8;                          /* inferred */
    /* 0x0C */ char padC[0x3C];                     /* maybe part of unk8[0x10]? */
    /* 0x48 */ s16 unk48;                           /* inferred */
    /* 0x4A */ char pad4A[6];                       /* maybe part of unk48[4]? */
    /* 0x50 */ s32 unk50;                           /* inferred */
    /* 0x54 */ char pad54[8];                       /* maybe part of unk50[3]? */
    /* 0x5C */ f32 unk5C;                           /* inferred */
    /* 0x60 */ f32 unk60;                           /* inferred */
    /* 0x64 */ char pad64[8];                       /* maybe part of unk60[3]? */
    /* 0x6C */ f32 unk6C;                           /* inferred */
    /* 0x70 */ char unk70[0x94];                           /* inferred */
    /* 0x104 */ f32 unk_104;                           /* inferred */
} UnkHeapStruct;

void func_80039D3C(UnkHeapStruct*);                             /* extern */

//arg0 points somewhere on the heap? currently 8030B740 (heap linked list?)
s32 func_8004F110(UnkHeapStruct* arg0);

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004AD40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004AD94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004AF3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004AF48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004AF78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004AFE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004B018.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004B088.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004B140.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004B1B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004B290.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004B334.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004B444.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004B4D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004B5CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004B684.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004B6CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004B6E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004B798.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004B854.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004B93C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004BA60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004BAF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004BB78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004BBC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004BC84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004BCAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004BF1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004BF90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004C1E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004CD4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004CE38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004CEC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004CED8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004D0D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004D1D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004D1F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004D2F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004D3B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004D410.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004D440.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004D46C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004D4C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004D4E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004D654.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004D958.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004DAD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004DBB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004DCD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004DD44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004DD98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004DF24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004E078.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004E180.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004E24C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004E394.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004E3BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004E578.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004E608.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004E654.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004E6A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004E6C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004E72C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004E750.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004E87C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004E8A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004E9C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004E9E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004EB38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004EBA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004EBC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004EC00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004ECB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004ED1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004EF18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004EFB8.s")

//draw player health
s32 func_8004F110(UnkHeapStruct* arg0) {
    UnkHeapStruct2* temp_v0;
    s32 var_s2;
    s32 i;

    temp_v0 = arg0->unk8;
    if (arg0->unk50 & 1) {
        return 0;
    }
    arg0->unk6C = 32.0f;
    arg0->unk_104 = 0.0f;
    arg0->unk5C = temp_v0->unk_10;
    arg0->unk60 = temp_v0->unk_14;
    arg0->unk48 = 3;
    var_s2 = (temp_v0->unk_04 < temp_v0->unk_06) ? temp_v0->unk_04 : temp_v0->unk_06;
    
    for (i = 0; i < var_s2; i++, arg0->unk6C += 13.0f) {
        func_80039D3C(arg0);      
    }
    return i;
}

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004F1E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004F25C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004F2BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004F3BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004F41C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004F518.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004F578.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004F638.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004F6D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004F6F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004F784.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004F82C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004F8F4.s")

void func_8004F968(s32 arg0) {

}

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004F970.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004F990.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004FA58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004FA70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004FADC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004FB00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004FCA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004FE1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004FEC0.s")

void func_8004FF34(s32 arg0) {

}

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004FF3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004FF5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004FFDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8004FFF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_80050060.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_80050084.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8005022C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_80050384.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_80050428.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_800505E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_80050694.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8005070C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_80050770.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_800507C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_800507F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_80050858.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_800508B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_8005092C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_800509B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_80050AB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_80050B34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_80050B48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_80050BCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_80050BE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_80050C00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_80050C28.s")

void func_80050CA0(s32 arg0) {

}

#pragma GLOBAL_ASM("asm/nonmatchings/26140/func_80050CA8.s")