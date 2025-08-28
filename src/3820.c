#include "common.h"

void RandomF(void);                                        /* extern */
void func_80028C00(void);                                  /* extern */
void func_800293F0(s32);                                 /* extern */
void func_800294A8(void);                                  /* extern */
void func_800297A0(void);                                  /* extern */
void func_80029860(void);                                  /* extern */
void func_8003D1B8(void);                                  /* extern */
void func_8007BB40(void);                                  /* extern */
void func_8007E400(void);                                  /* extern */
void func_800AC440(void);                                  /* extern */
void func_800AC710(void);                                  /* extern */
void func_800BE480(void);                                  /* extern */
void func_801FFE88_2083F8(void);                                  /* extern */
void func_802005E8_210C08(void);                                  /* extern */
void func_80200B18_209088(void);                                  /* extern */
void func_80200E88_2114A8(void);                                  /* extern */
void func_80201908_211F28(void);                                  /* extern */
void func_802019CC_209F3C(void);                                  /* extern */
void func_802023F8_212A18(void);                                  /* extern */
void func_80202564_20AAD4(void);                                  /* extern */
void func_80202B08_213128(void);                                  /* extern */
void func_80203640_20BBB0(void);                                  /* extern */
void func_80204060_20C5D0(void);                                  /* extern */
void func_80204EEC_20D45C(void);                                  /* extern */
void func_802063AC_20E91C(void);                                  /* extern */

typedef struct UnkDebug {
/* 0x00 */ u16 unk_00;
/* 0x02 */ char unk_02[4];
/* 0x06 */ u16 unk_06;
} UnkDebug;

extern s16 D_800EAE64;
extern s16 D_800EAE70;
extern s16 D_800EAE74;
extern s16 D_800EAF60;
extern UnkDebug D_800FF1C0;
extern u8 D_80160648;
extern u8 D_80160659;

#pragma GLOBAL_ASM("asm/nonmatchings/3820/func_80028420.s")

#pragma GLOBAL_ASM("asm/nonmatchings/3820/func_8002847C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/3820/func_8002852C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/3820/func_8002858C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/3820/func_80028634.s")

#pragma GLOBAL_ASM("asm/nonmatchings/3820/func_80028674.s")

#pragma GLOBAL_ASM("asm/nonmatchings/3820/func_800286E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/3820/func_8002877C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/3820/func_80028C00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/3820/func_800293C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/3820/func_800293F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/3820/func_80029458.s")

#pragma GLOBAL_ASM("asm/nonmatchings/3820/func_800294A8.s")

void func_8002956C(void) {
    #define MAIN_GAME_STEP 3
    #define INTRO_SCENES_STEP 4
    #define DEBUG_MENU_STEP 12
    #define NEW_GAME_CUTSCENE_STEP 15
    #define GAME_SELECTION_STEP 18 //title screen, file select, training room select, etc
    
    RandomF();
    if ((D_800EAE64 != 0) && (D_800FF1C0.unk_00 & 0x1000) && (D_800FF1C0.unk_06 & 0x8000) && (D_800EAF60 != 0xC)) {
        func_800293F0(0xC);
        return;
    }
    if (D_800EAE70 != 0) {
        D_80160648 = 0xFF;
    }
    if (D_800EAE74 != 0) {
        D_80160659 = 0xFF;
    }
    func_800294A8();
    switch (D_800EAF60) {
    case 0:
        func_800297A0();
        return;
    case 1:
        func_80029860();
        return;
    case MAIN_GAME_STEP:
        func_80028C00();
        return;
    case INTRO_SCENES_STEP:
        func_8003D1B8();
        return;
    case 22:
        func_802023F8_212A18();
        return;
    case 21:
        func_80200E88_2114A8();
        return;
    case 8:
        func_80202564_20AAD4();
        return;
    case 2:
        func_80204EEC_20D45C();
        return;
    case 7:
        func_80204060_20C5D0();
        return;
    case 20:
        func_802005E8_210C08();
        return;
    case 9:
        func_802063AC_20E91C();
        return;
    case 11:
        func_802019CC_209F3C();
        return;
    case 10:
        func_80200B18_209088();
        return;
    case DEBUG_MENU_STEP:
        func_80203640_20BBB0();
        return;
    case NEW_GAME_CUTSCENE_STEP:
        func_800AC440();
        return;
    case 16:
        func_800AC710();
        return;
    case 19:
        func_80201908_211F28();
        return;
    case 13:
        func_801FFE88_2083F8();
        return;
    case GAME_SELECTION_STEP: //includes JSS logo start up
        func_800BE480();
        return;
    case 6:
        func_8007BB40();
        return;
    case 23:
        func_8007E400();
        return;
    case 24:
        func_80202B08_213128();
        return;
    default:
        return;
    }
}


#pragma GLOBAL_ASM("asm/nonmatchings/3820/func_800297A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/3820/func_80029860.s")

#pragma GLOBAL_ASM("asm/nonmatchings/3820/func_8002989C.s")
