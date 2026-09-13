#include "common.h"

void func_80050DA0(void*);
void func_80050F38(s32, s32, s32);
void func_80050F54(s32);
void func_80050FE0(s32, s32, s32, s32);
void func_80051014(s32);
void func_80051020(f32, f32);
void func_800514FC(s32);

/* externs */
void DummiedPrintf3(const char*);
void Stage_Open(s32);
void func_80027F98(s32);
void func_8002989C(void);
void func_80029A90(void);
void func_80029BD0(void);
void func_80029C44(void);
void func_8002C258(s32);
void func_80033390(void);
void func_80037460(void);
void func_80038D1C(void);
void func_8003A94C(void);
s32  func_800BE88C(s32);
void func_800BE9FC(void);
void func_800BEB10(void);
void func_800BEB48(void);
void func_800BEC18(void);
void func_800BECF8(void);
void func_800BEEC0(void);
void func_800BEFC0(void);
void func_800BF008(void);
void func_800BF090(void);
void func_800BF128(void);
void func_800BF1AC(void);
s32  func_800BF3F8(s32, s32, void*, f32, f32, f32, s32);
void func_800C01B0(void);
void func_800C0810(void);
void func_800C0AE0(void);
void func_800C1C60(void);
void func_800C4E70(void);
void func_800C5CA0(void);
void func_800C8440(void);
void func_800C8A50(void);
void func_800C98D0(void);
void func_800CA9F0(void);
void func_800CAE70(void);
void func_800D3E40(s32, s32);
void func_800D4D70(s32);

extern void func_800C52B0(void);

extern s8  D_800EAD68;
extern s8  D_800EAD6C;
extern s8  D_800EAD70;
extern s16 D_800EAF60;
extern s16 D_800EAF64;
extern u32 D_800F0934;
extern s16 D_800FF20A;
extern s32 D_8018BF0C;
extern s32 D_801FAAE8;

/* fields at 0x48..0x5C are two Vec3f's */
typedef struct Unk80162E20 {
    /* 0x00 */ char unk00[0x48];
    /* 0x48 */ Vec3f unk48;
    /* 0x54 */ Vec3f unk54;
} Unk80162E20;

extern Unk80162E20 D_80162E20;

#define NULL 0

void func_800BE480(void) {
    s32 i;

    switch (D_800EAF64) {
    case 0:
        D_800EAD68 = 0;
        D_800EAD6C = 0;
        D_800EAD70 = 0;
        func_80038D1C();
        D_800FF20A = 0;
        func_8003A94C();
        func_80037460();
        func_80029A90();
        func_80033390();
        func_8002989C();
        Stage_Open(0x13);
        func_80027F98(D_801FAAE8);

        switch (D_800F0934) {
        case 0:
            func_800BE9FC();
            func_800C01B0();
            break;
        case 1:
            func_800BEB10();
            func_800C0810();
            break;
        case 2:
            func_800BEB48();
            D_8018BF0C = func_800BF3F8(1, func_800BE88C(1), NULL, 0.0f, 0.0f, 5.0f, 0);
            func_800C0AE0();
            break;
        case 3:
            func_800BEC18();
            D_8018BF0C = func_800BF3F8(1, 0x67, NULL, 0.0f, 0.0f, 0.0f, 0);
            func_800C1C60();
            break;
        case 5:
            func_800BEEC0();
            D_8018BF0C = func_800BF3F8(1, 0x4E, NULL, 0.0f, 0.0f, 0.0f, 0);
            func_800C8440();
            break;
        case 4:
            func_800BECF8();
            func_800C5CA0();
            break;
        case 6:
            func_800BF008();
            func_800C8A50();
            break;
        case 7:
            func_800BEFC0();
            D_8018BF0C = func_800BF3F8(1, 0x69, func_800C52B0, 0.0f, 0.0f, 0.0f, 0);
            func_800C4E70();
            break;
        case 8:
            func_800BF090();
            D_8018BF0C = func_800BF3F8(1, 0x68, NULL, 0.0f, 0.0f, 0.0f, 0);
            func_800C98D0();
            break;
        case 9:
            func_800BF128();
            D_8018BF0C = func_800BF3F8(1, 0x4E, NULL, 0.0f, 0.0f, 0.0f, 0);
            func_800CA9F0();
            break;
        case 10:
            func_800CAE70();
            break;
        case 11:
            func_800BF1AC();
            break;
        default:
            func_800BEB48();
            D_8018BF0C = func_800BF3F8(1, 0xA9, NULL, 0, 0.0f, 5.0f, 0);
            func_800C0AE0();
            break;
        }

        for (i = 0; i < 1; i++) {
            func_800D4D70(i);
        }
        func_800D3E40(0, 1);

        D_80162E20.unk54.x = 0.0f;
        D_80162E20.unk54.y = 0.0f;
        D_80162E20.unk54.z = 0.0f;
        D_80162E20.unk48.x = 0.0f;
        D_80162E20.unk48.y = 0.0f;
        D_80162E20.unk48.z = 209.0f;

        func_8002C258(1);
        D_800EAF64++;
        //DummiedPrintf3("初期化終了\n");
        DummiedPrintf3("\x92\xbd\xe9\x92\xb4\xfc\x92\xb2\xbd\x92\xbd\xaa\x92\xce\xbb\n");
        break;

    case 1:
        func_80029C44();
        break;

    case 2:
        func_80029BD0();
        func_80029C44();
        func_80029C44();
        D_800EAF64++;
        break;

    case 3:
        //DummiedPrintf3("メニュー終了\n");
        DummiedPrintf3("\x92\xa5\xe1\x92\xa5\xcb\x92\xa5\xe5\x92\xa1\xbc\x92\xbd\xaa\x92\xce\xbb\n");
        D_800EAF60 = 0xC;
        D_800EAF64 = 0;
        break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/99880/func_800BE88C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/99880/func_800BE9FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/99880/func_800BEA44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/99880/func_800BEB10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/99880/func_800BEB48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/99880/func_800BEC18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/99880/func_800BECF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/99880/func_800BEEC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/99880/func_800BEFC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/99880/func_800BF008.s")

#pragma GLOBAL_ASM("asm/nonmatchings/99880/func_800BF090.s")

#pragma GLOBAL_ASM("asm/nonmatchings/99880/func_800BF128.s")

#pragma GLOBAL_ASM("asm/nonmatchings/99880/func_800BF1AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/99880/func_800BF1F0.s")

void func_800BF230(s32 arg0, s32 arg1, s32 arg2, void* arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, f32 arg8, f32 arg9) {
    func_80050F54(0);
    func_800514FC(0);
    func_80050F38(arg0, arg1, arg2);
    func_80050FE0(arg4, arg5, arg6, arg7);
    func_80051020(arg8, arg9);
    func_80051014(1);
    func_80050DA0(arg3);
}

#pragma GLOBAL_ASM("asm/nonmatchings/99880/func_800BF2A8.s")
