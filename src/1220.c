#include "common.h"

extern s8 osViYScaleSetFlag;
void osViSetYScale(f32);

void osSyncPrintf(const char *fmt, ...) {
}

void osSetViYScale(void) {
    osViSetYScale(1.0f);
    osViYScaleSetFlag = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/1220/func_80025E6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1220/func_80025FF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1220/func_80026080.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1220/func_80026100.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1220/func_8002616C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1220/func_800262E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1220/func_80026338.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1220/func_8002637C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1220/func_800263B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1220/func_80026604.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1220/func_80026680.s")
