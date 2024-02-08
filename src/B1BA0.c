#include "common.h"

s32 osSetIntMask(s32);                             /* extern */
extern s32 D_800F1F70;

void func_800D67A0(s32 arg0) {
    s32 temp_a0;

    temp_a0 = osSetIntMask(1);
    D_800F1F70 = arg0;
    osSetIntMask(temp_a0);
}