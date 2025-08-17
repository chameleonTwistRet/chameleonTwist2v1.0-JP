#include "ultra64.h"

typedef struct Vec3f {
    f32 x;
    f32 y;
    f32 z;
} Vec3f;

typedef struct unk_func_80040840 {
    s32 unk00[4];
    void* unk10;
    s32 unk14[15];
    s32 unk50;
} unk_func_80040840;

typedef struct unk_func_80040C10 {
    s16 unk0;
    s16 unk2;
} unk_func_80040C10;

typedef struct unk_80163030 {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u8 unk7;
    s8 unk8;
    s8 unk9;
    s8 unkA;
    u8 unkB;
    u8 unkC;
    u8 unkD;
    u8 unkE;
    u8 unkF;
    s8 unk10;
    s8 unk11;
    s8 unk12;
    char unk13[0x35];
    f32 unk48;
    f32 unk4C;
    f32 unk50;
    f32 unk54;
    f32 unk58;
    f32 unk5C;
} unk_80163030;

typedef struct unk_80163130 {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u8 unk7;
    u8 unk8;
    u8 unk9;
    u8 unkA;
    u8 unkB;
    u8 unkC;
    u8 unkD;
    u8 unkE;
    u8 unkF;
    s8 unk10;
    s8 unk11;
    s8 unk12;
} unk_80163130;

typedef struct unk_801630D8 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
} unk_801630D8;

typedef struct unk_func_80027E98 {  //2fe0.c
    char unk0[0xF1];
    u16 unkF2;
    char unkF3[0x10];
    f32 unk104;
} unk_func_80027E98;

typedef struct unk_func_800CD790 {
    char unk0[0x2C];
    s32 unk2C;
} unk_func_800CD790;

typedef struct unk_func_800CD5D0 {
    s32 unk0;
    s32 unk4;
    s32* unk8; //unknown type
} unk_func_800CD5D0;

typedef struct unk_800F1CB4 {
    char unk0[0x38];
    void* unk38; //probably some struct
} unk_800F1CB4;

typedef struct unk_8019CB40 {
    char unk_00[0x188];
} unk_8019CB40;

typedef struct unk_800EEFF0 {
    s8 unk0[0xA];
    s16 unkA;
} unk_800EEFF0;

typedef struct unk_func_800DA208 {
    char unk0[0xC];
    s32 unkC;
} unk_func_800DA208;

typedef struct unk_func_800E7A9C {
    char unk0[0xC];
    s32 unkC;
} unk_func_800E7A9C;

typedef struct unk_func_80037EB4 {
    u8 unk0[0x122];
    s16 unk122;
} unk_func_80037EB4;

typedef struct unk_func_800D1F70 {
    char unk0[0x32];
    s16 unk32;
} unk_func_800D1F70;

typedef struct Tongue {
    Vec3f tongue[70];
} Tongue;

typedef struct UnkPlayer {
    void* actor; //?
    s32 timer; //?
} UnkPlayer;

typedef struct Player {
    /* 0x000 */ struct Player* player;
    /* 0x004 */ Tongue tongueData;
    /* 0x34C */ char unk34C[0x2F8];
    /* 0x644 */ UnkPlayer unk644[32]; //
    /* 0x64C */ char unk64C[0x100];
    /* 0x844 */ s32 unk844;
    /* 0x848 */ char pad848[4];
    /* 0x84C */ s32 unk84C;
    /* 0x850 */ s32 unk850;
    /* 0x854 */ s32 unk854;
    /* 0x858 */ s32 unk858;
    /* 0x85C */ s32 unk85C;
    /* 0x860 */ s32 unk860;
    /* 0x864 */ char pad864[0xC];
    /* 0x870 */ Vec3f pos;
    /* 0x87C */ f32 angle1;
    /* 0x880 */ char unk_880[8];
    /* 0x888 */ f32 stickMagnitude;
    /* 0x88C */ f32 unk_88C;
    /* 0x890 */ f32 unk890;
    /* 0x894 */ f32 velocity; //speedWithDirection
    /* 0x898 */ char unk898[0xC];
    /* 0x8A4 */ f32 unk8A4;
    /* 0x8A8 */ s32 unk8A8;
    /* 0x8AC */ s32 unk8AC;
    /* 0x8B0 */ s32 unk8B0;
    /* 0x8B4 */ s32 unk8B4;
    /* 0x8B8 */ s32 unk8B8;
    /* 0x8BC */ s8 unk8BC[8];
    /* 0x8C4 */ s16 unk8C4;
    /* 0x8C6 */ char pad8C6[2];
    /* 0x8C8 */ s32 unk8C8;
    /* 0x8CC */ s8 unk8CC[4];
    /* 0x8D0 */ s32 unk8D0;
    /* 0x8D4 */ s32 unk8D4;
    /* 0x8D8 */ s8 unk8D8[0x54];
    /* 0x92C */ s16 hp;
    /* 0x92E */ char pad92E[0xE];
    /* 0x93C */ s32 unk93C;
    /* 0x940 */ s8 unk940[6];
    /* 0x946 */ s16 unk946;
    /* 0x948 */ s8 unk948[4];
    /* 0x94C */ s16 unk94C;
    /* 0x94E */ s8 unk94E[4];
    /* 0x952 */ s16 unk952;
    /* 0x954 */ char unk_954[0x28];
} Player; /* size = 0x97C */
