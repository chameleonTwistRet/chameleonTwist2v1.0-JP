#ifndef _COMMON_STRUCTS_H_
#define _COMMON_STRUCTS_H_

#include "ultra64.h"

typedef struct Vec2f {
    f32 x;
    f32 y;
} Vec2f;

typedef struct Vec3f {
    f32 x;
    f32 y;
    f32 z;
} Vec3f;

typedef struct Rect3D {
/* 0x00 */ Vec3f min;
/* 0x0C */ Vec3f max;
} Rect3D;

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

typedef struct Actor {
    /* 0x000 */ char unk_000[0x4];
    /* 0x004 */ struct Actor *next;      /* unk4; list link */
    /* 0x008 */ void *work;              /* per-actor work block; BossWork* for the boss */
    /* 0x00C */ char unk_0C[4];
    /* 0x010 */ void (*func)(struct Actor*);
    /* 0x014 */ void (*func2)(struct Actor*);                 /* inferred */
    /* 0x018 */ char pad18[0x32];                   /* maybe part of unk14[0xD]? */
    /* 0x04A */ s16 unk_4A;              /* gated against D_80160808.unk_00 */
    /* 0x04C */ char unk_04C[0x8];
    /* 0x054 */ s32 unk_54;              /* 0xC351 / 0x9C40 select the update path */
    /* 0x058 */ char unk_058[0x14];
    /* 0x06C */ f32 renderX;
    /* 0x070 */ f32 renderY;
    /* 0x074 */ f32 renderZ;
    /* 0x078 */ char unk_078[0x8];
    /* 0x080 */ s16 unk_80;
    /* 0x082 */ char unk_082[0x6];
    /* 0x088 */ f32 animFrame;
    /* 0x08C */ char unk_08C[0x4];
    /* 0x090 */ f32 posX;
    /* 0x094 */ f32 posY;
    /* 0x098 */ f32 posZ;
    /* 0x09C */ f32 yaw;
    /* 0x0A0 */ f32 unk_A0;              /* both > 0 to qualify for func_800AA720 */
    /* 0x0A4 */ f32 unk_A4;
    /* 0x0A8 */ char unk_0A8[0x4];
    /* 0x0AC */ f32 unk_AC;
    /* 0x0B0 */ f32 groundY;
    /* 0x0B4 */ char padB4[0x1C];                   /* maybe part of groundY[8]? */
    /* 0x0D0 */ f32 unkD0;                          /* inferred */
    /* 0x0D4 */ char padD4[4];
    /* 0x0D8 */ f32 health;
    /* 0x0DC */ s16 unk_DC;              /* 1 or 2 qualify for func_800AA720 */
    /* 0x0DE */ s16 mode;
    /* 0x0E0 */ s16 unk_E0;
    /* 0x0E2 */ char unk_0E2[0x2];
    /* 0x0E4 */ s16 unk_E4;              /* id passed to func_8005524C */
    /* 0x0E6 */ char unk_0E6[0x4];
    /* 0x0EA */ s16 unk_EA;
    /* 0x0EC */ char unk_0EC[0x6];
    /* 0x0F2 */ u16 unk_F2;              /* bit 0 suppresses func_800AA720 */
    /* 0x0F4 */ char unk_0F4[0x10];
    /* 0x104 */ f32 facing;
    /* 0x108 */ char unk_108[0x18];
    /* 0x120 */ s16 unk_120;             /* live active flag */
    /* 0x122 */ s16 unk_122;             /* requested active flag, latched each frame */
    /* 0x124 */ char unk_124[0x50];
} Actor; /* size 0x174 (unknown size) */

typedef struct BossWork {
    /* 0x00 */ s16 homeX;
    /* 0x02 */ s16 homeY;
    /* 0x04 */ s16 homeZ;
    /* 0x06 */ s16 baseY;
    /* 0x08 */ char unk_08[2];
    /* 0x0A */ s16 state;
    /* 0x0C */ char unk_0C[2];
    /* 0x0E */ s16 hpMax;
    /* 0x10 */ f32 childSpeed;
    /* 0x14 */ s16 childSpeedBase;
    /* 0x16 */ char unk_16[2];
    /* 0x18 */ f32 moveSpeed;
    /* 0x1C */ s16 moveSpeedBase;
    /* 0x1E */ s16 hopTimer;
    /* 0x20 */ s16 spinTimer;
    /* 0x22 */ char unk_22[2];
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ f32 timer;
    /* 0x38 */ f32 stateLen;
    /* 0x3C */ char unk_3C[0x10];
    /* 0x4C */ f32 savedState;
    /* 0x50 */ Actor *children[9];
    /* 0x74 */ f32 savedX;
    /* 0x78 */ f32 savedY;
    /* 0x7C */ f32 savedZ;
    /* 0x80 */ s16 spawned;
    /* 0x82 */ char unk_82[0x26];
    /* 0xA8 */ f32 heightOfs;
    /* 0xAC */ char unk_AC[0x34];
    /* 0xE0 */ f32 spin;
    /* 0xE4 */ s16 minX;
    /* 0xE6 */ s16 minY;
    /* 0xE8 */ s16 minZ;
    /* 0xEA */ s16 maxX;
    /* 0xEC */ s16 maxY;
    /* 0xEE */ s16 maxZ;
} BossWork; /* size 0xF0 */

#endif //_COMMON_STRUCTS_H_
