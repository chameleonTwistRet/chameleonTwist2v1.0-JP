#include "common.h"
#include "PR/os.h"

s32 func_80049780(s32 arg0, s32 arg1, s32 arg2) {
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/24B80/func_80049794.s")

// #pragma GLOBAL_ASM("asm/nonmatchings/24B80/func_800497C8.s")

void func_800497C8(void) {
    OSIoMesg sp50;
    OSMesgQueue sp38;
    OSMesg sp34;
    u32 vramSizeCopy;
    u32 vramSize;

    osCreateMesgQueue(&sp38, &sp34, 1);
    vramSize = Unk0_VRAM_END - Unk0_VRAM; //why is Unk0_VRAM_END 0x10 too short??
    vramSizeCopy = vramSize;
    osInvalDCache(Unk0_VRAM, vramSize);
    osInvalICache(Unk0_VRAM, vramSizeCopy);
    osPiStartDma(&sp50, 0, 0, (u32)Unk0_ROM_START, Unk0_VRAM, (u32)Unk0_ROM_END - (u32)Unk0_ROM_START, &sp38);
    osRecvMesg(&sp38, NULL, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/24B80/func_8004986C.s")

void func_800498A0(void) {
    OSIoMesg sp50;
    OSMesgQueue sp38;
    OSMesg sp34;
    u32 vramSizeCopy;
    u32 vramSize;

    osCreateMesgQueue(&sp38, &sp34, 1);
    vramSize = Unk1_VRAM_END - Unk1_VRAM;
    vramSizeCopy = vramSize;
    osInvalDCache(Unk1_VRAM, vramSize);
    osInvalICache(Unk1_VRAM, vramSizeCopy);
    osPiStartDma(&sp50, 0, 0, (u32)Unk1_ROM_START, Unk1_VRAM, (u32)Unk1_ROM_END - (u32)Unk1_ROM_START, &sp38);
    osRecvMesg(&sp38, NULL, 1);
}

void func_80049944(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/24B80/func_8004994C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/24B80/func_80049A6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/24B80/func_80049CE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/24B80/func_80049DE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/24B80/func_8004A0F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/24B80/func_8004A114.s")

#pragma GLOBAL_ASM("asm/nonmatchings/24B80/func_8004A1A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/24B80/func_8004A1C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/24B80/func_8004A2A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/24B80/func_8004A45C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/24B80/func_8004A9C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/24B80/func_8004AA10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/24B80/func_8004AC28.s")