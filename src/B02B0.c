#include "common.h"

void func_800D5170(void);
void func_800D5318(void);
void func_800D5384(void);
void func_800D5428(void);
void func_800D54AC(void);

#pragma GLOBAL_ASM("asm/nonmatchings/B02B0/func_800D4EB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B02B0/func_800D4F44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B02B0/func_800D4F68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B02B0/func_800D5170.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B02B0/func_800D5318.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B02B0/func_800D5384.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B02B0/func_800D5428.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B02B0/func_800D54AC.s")

s32 func_800D5540(s16* arg0) {
    switch (*arg0) {
        case 0x1:
            func_800D5170();
            return 0;
        case 0x101:
            return 0;
        case 0x3000:
            func_800D5318();
            break;
        case 0x3001:
            func_800D54AC();
            break;
        case 0x2:
            func_800D5384();
            return 0;
        case 0x3002:
            func_800D5384();
            break;
        case 0x3003:
            func_800D5428();
            break;
        default:
            return 0;
    }
    return 1;
}
