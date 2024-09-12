#include "common.h"

void func_8003B8B8(s32);
void func_800AFE64(Player*, f32);
void func_800B0568(Player* arg0, Player* arg1, Tongue* arg2);
void func_800B065C(Player* arg0, Player* arg1, Tongue* arg2);

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800ADB80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800ADBC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800ADC58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800ADD20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800ADE58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800ADF50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800ADF5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800ADF68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800AE9C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800AEC48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800AEF7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800AEF9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800AF068.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800AF170.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800AF230.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800AF2E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800AF40C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800AF530.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800AF570.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800AF584.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800AF5B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800AF5F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800AF64C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800AF670.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800AF6F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800AF738.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800AF77C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800AF7C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800AF84C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800AF890.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800AF924.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800AF988.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800AF9EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800AFA38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800AFADC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800AFBA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800AFC90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800AFCE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800AFD30.s")

void func_800AFE64(Player* arg0, f32 arg1) {
    arg0->unk8AC = 1;
    arg0->unk8B0 = 0;
    arg0->unk8B4 = 0;
    arg0->unk8B8 = 0;
    arg0->unk8C4 = 0;
    arg0->unk8C8 = 0;
    arg0->unk890 = arg1;
}

void func_800AFE8C(Player* arg0, s32 arg1) {
    arg0->unk858 = arg1;
    arg0->unk85C = 0;
    switch (arg1) {
    case 12:
        arg0->unk8B4 = 0;
        func_800AFE64(arg0, 0.0f);
        break;
    case 3:
        func_8003B8B8(9);
        break;
    case 9:
        func_8003B8B8(0x18);
        break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800AFEF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800AFF64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800AFFC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B004C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B008C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B0288.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B0360.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B041C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B04B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B0530.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B0568.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B065C.s")

void func_800B072C(Player* arg0, Player* arg1, s32 buttonMask) {
    if (arg0->unk8D4 == 0) {
        if ((arg1->unk844 != 0) && (arg0->unk952 == 0)) {
            if (buttonMask & B_BUTTON) {
                arg0->unk8D0 = arg1->unk844;
                return;
            }
            if (buttonMask & Z_TRIG) {
                arg0->unk8D0 = 1;
            }
        } else if ((buttonMask & B_BUTTON) && (arg0->unk8C8 == 0)) {
            if (arg0->unk952 == 0) {
                func_800B0568(arg0, arg1, &arg1->tongueData);
            }
        } else if ((buttonMask & Z_TRIG) && (arg0->unk8AC == 0)) {
            if ((arg0->unk952 == 0) && (arg0->unk8A8 == 0) && (arg0->unk94C != 0xC) && (arg0->unk952 == 0)) {
                func_800B065C(arg0, arg1, &arg1->tongueData);
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B080C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B0A78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B0B4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B0C8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B0CE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B0EFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B0F7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B1010.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B1048.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B10D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B10F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B1280.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B136C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B13E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B148C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B14EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B16F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B1888.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B19F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B1AD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B1C48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B1D54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B1DF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B1E24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B1F68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B2040.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B2150.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B2208.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B22EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B24F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B2564.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B2668.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B2708.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B28E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B2A84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B2B40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B2C24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B2E2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B2F18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B3020.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B3228.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B3300.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B3390.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B346C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B34F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B3598.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B35C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B36F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B3840.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B38F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B39EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B3A04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B3CC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B3E58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B3EB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B404C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B41F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B4228.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B42E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B4404.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B4560.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B47E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B4A54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B4B04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B4B50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B4B7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B4C40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B4C9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B4D14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B4DC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B5D04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B5EF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B608C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B60C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B67DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B6938.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B6ACC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B6CD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B6F20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B719C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B72EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/88F80/func_800B74B0.s")
