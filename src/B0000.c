#include "common.h"

extern s32 D_801C1BEC;

void func_800D4C00() {
    s32 temp_v0;

    temp_v0 = osSetIntMask(1);
    D_801C1BEC = 1;
    osSetIntMask(temp_v0);
}

void func_800D4C34() {
    s32 temp_v0;

    temp_v0 = osSetIntMask(1);
    D_801C1BEC = 0;
    osSetIntMask(temp_v0);
}
