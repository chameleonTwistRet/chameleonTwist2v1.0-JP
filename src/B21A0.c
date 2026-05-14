#include "common.h"

void func_800D4040(void*);                                /* extern */
void func_800D4180(void);                                  /* extern */
void func_800D4330(void);                                  /* extern */
void func_800D4644(Gfx*, s32, s32, s32);                   /* extern */
void func_800D6CA8(void);                                  /* extern */
void func_800D6E60(void*, s32);                             /* extern */
extern s32 D_800F2940[]; //something related to n_aspMain_data
extern void* D_800F2970[3]; //triple framebuffer pointers
extern Gfx D_800F2980[];
extern s32* D_801A13A8;
extern s32 D_801A1748;
void func_800D6E90(void);

#ifdef NON_MATCHING
void func_800D6DA0(void) {
    Gfx sp10[256];
    Gfx* gfx;

    func_800D6CA8();
    func_800D6E60(D_800F2970, 3);
    D_801A1748 = 0x80000400; //depth buffer hardcoded to 0x80000400
    func_800D4040(&func_800D6E90);
    D_801A13A8 = &D_800F2940[0];
    func_800D4330();
    gfx = sp10;
    gSPDisplayList(&sp10[0], OS_K0_TO_PHYSICAL(D_800F2980));
    gDPFullSync(&sp10[1]);
    gSPEndDisplayList(&sp10[2]);
    
    //((s32) (((s32) &sp10 * 0) + 0x18) >> 3) * 8 is always just 0x18??
    func_800D4644(sp10, (&sp10[3] - gfx) * sizeof(Gfx), 0, 0); //??
    func_800D4180();
}

#else
#pragma GLOBAL_ASM("asm/nonmatchings/B21A0/func_800D6DA0.s")
#endif
