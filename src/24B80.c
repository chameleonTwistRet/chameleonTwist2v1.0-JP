#include "common.h"
#include "PR/os.h"

void func_80050F54(s32);
void func_80050FE0(s32, s32, s32, s32);
void func_80051014(s32);
void func_80051034(s32);
void func_80051040(s32, s32, s32, s32, s32);
void func_800510A8(s32, s32, s32, s32);
void func_800514FC(s32);
void func_80051508(s32, s32);
void func_8005151C(s32);
void func_80049DE8(u8);
s32 func_8003A91C(u32 arg0, s32 arg1);
extern s32 D_800FF210;
extern s32 D_801651B0;
extern u8 D_802078A0[]; //unknown size/type
extern u8 D_80203350[]; //unknown size/type

s32 func_80049780(s32 arg0, s32 arg1, s32 arg2) {
    return 0;
}

//required 1 liner to match
void func_80049794(void) {\
    D_801651B0 = func_8003A91C((u32)&D_802078A0, (u32)D_800FF210 - (u32)D_802078A0);
}

void func_800497C8(void) {
    OSIoMesg sp50;
    OSMesgQueue sp38;
    OSMesg sp34;
    u32 vramSizeCopy;
    u32 vramSize;

    osCreateMesgQueue(&sp38, &sp34, 1);
    vramSize = Unk0_VRAM_END - Unk0_VRAM;
    vramSizeCopy = vramSize;
    osInvalDCache(Unk0_VRAM, vramSize);
    osInvalICache(Unk0_VRAM, vramSizeCopy);
    osPiStartDma(&sp50, 0, 0, (u32)Unk0_ROM_START, Unk0_VRAM, (u32)Unk0_ROM_END - (u32)Unk0_ROM_START, &sp38);
    osRecvMesg(&sp38, NULL, 1);
}

//required 1 liner to match
void func_8004986C(void) {\
    D_801651B0 = func_8003A91C((u32)&D_80203350, D_800FF210 - (u32)&D_80203350);
}

void func_800498A0(void) {
    OSIoMesg sp50;
    OSMesgQueue sp38;
    OSMesg sp34;
    u32 vramSizeCopy;
    u32 vramSize;

    osCreateMesgQueue(&sp38, &sp34, 1);
    vramSize = ControllerPakAndVictoryScreen_VRAM_END - ControllerPakAndVictoryScreen_VRAM;
    vramSizeCopy = vramSize;
    osInvalDCache(ControllerPakAndVictoryScreen_VRAM, vramSize);
    osInvalICache(ControllerPakAndVictoryScreen_VRAM, vramSizeCopy);
    osPiStartDma(&sp50, 0, 0, (u32)ControllerPakAndVictoryScreen_ROM_START, ControllerPakAndVictoryScreen_VRAM, (u32)ControllerPakAndVictoryScreen_ROM_END - (u32)ControllerPakAndVictoryScreen_ROM_START, &sp38);
    osRecvMesg(&sp38, NULL, 1);
}

void func_80049944(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/24B80/func_8004994C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/24B80/func_80049A6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/24B80/func_80049CE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/24B80/func_80049DE8.s")

void func_8004A0F4(void) {
    func_80049DE8(0xFF);
}

void func_8004A114(s16 arg0) {
    func_80051040(0, 180, 180, 180, arg0);
    func_80051040(3, 180, 180, 180, arg0);
    func_80051040(1, 115, 115, 115, arg0);
    func_80051040(2, 115, 115, 115, arg0);
}

void func_8004A1A0(void) {
    func_8004A114(0xFE);
}

void func_8004A1C0(void) {
    func_80050F54(1);
    func_80051014(1);
    func_80050FE0(0xFF, 0xFF, 0xFF, 0xFF);
    func_80051034(1);
    func_80051040(0, 0xFF, 0x80, 0, 0xFF);
    func_80051040(3, 0xFF, 0x80, 0, 0xFF);
    func_80051040(1, 0xFF, 0xFF, 0, 0xFF);
    func_80051040(2, 0xFF, 0xFF, 0, 0xFF);
    func_800514FC(1);
    func_80051508(0x10, 0x10);
    func_8005151C(4);
    func_800510A8(0, 0, 0x140, 0xF0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/24B80/func_8004A2A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/24B80/func_8004A45C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/24B80/func_8004A9C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/24B80/func_8004AA10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/24B80/func_8004AC28.s")