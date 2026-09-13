#include "common.h"

extern f32 D_80160620;
s32 func_8003B914(s32 effectId, f32 *x, f32 *y, f32 *z, s32 arg4);
s32 func_80027BE0(Actor*);
void func_800AADE8(Actor *actor, f32 x1, f32 y1, f32 z1, f32 x2, f32 y2, f32 z2, s32 arg7);
void func_8002A164(Actor *actor); 

#pragma GLOBAL_ASM("asm/nonmatchings/2FE0/func_80027BE0.s")

void func_80027D94(Actor* arg0) {
    f32 temp_f0;

    if ((arg0->mode == 1) || ((arg0->unk_F2 & 0x80) && (arg0->mode == 0))) {
        if (func_80027BE0(arg0) != 0) {
            func_8003B914(0x10, &arg0->renderX, &arg0->renderY, &arg0->renderZ, 0x30);
            func_800AADE8(arg0, arg0->unkD0 * 8.0, arg0->unkD0 * 8.0, arg0->unkD0 * 8.0, 100.0f, 100.0f, 100.0f, 0xA);
            func_8002A164(arg0);
            return;
        }
        arg0->func(arg0);
        return;
    }
    arg0->func(arg0);
}

void func_80027E90(s32 arg0) {

}

void func_80027E98(Actor* arg0) {
    D_80160620 = arg0->facing;
}

void func_80027EA8(Actor* arg0) {
    if (D_80160620 != arg0->facing) {
        arg0->unk_F2 = (arg0->unk_F2 | 4);
        return;
    }
    arg0->unk_F2 = (arg0->unk_F2 & ~4);
}
