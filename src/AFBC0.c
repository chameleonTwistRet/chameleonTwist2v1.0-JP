#include "common.h"

typedef struct UnkController {
    s16 unk_00;
    s16 unk_02;
    OSMesgQueue* mesgQueue;
    void* unk_08;
} UnkController;

typedef struct UnkStruct {
    void* unk_00;
    void* unk_04; //points to a function
} UnkStruct;

void func_800D498C(void);
void func_800D49B8(void);
extern void osContGetReadData(OSContPad *);
extern s32 osContStartReadData(OSMesgQueue *);
extern s32 osRecvMesg(OSMesgQueue *, OSMesg *, s32);
void func_800D4A54(UnkController*);
extern s32 osSendMesg(OSMesgQueue *, OSMesg, s32);
s32 func_800D4AB0(UnkController* arg0);
void func_800D4C70(UnkStruct*);

extern OSMesgQueue D_801C1BA0;
extern void (*D_800F1F60)(s16);
extern OSMesgQueue D_801C1B60;
extern OSContPad D_801C1BD0; //p1 OSContPad
extern s32 D_801C1BEC;
extern OSMesgQueue D_8019CFC0;
extern OSContStatus D_801C1BC0;
extern UnkStruct D_801C1D90;

#pragma GLOBAL_ASM("asm/nonmatchings/AFBC0/func_800D47C0.s")

void func_800D4968(void) {
    func_800D4C70(&D_801C1D90);
}

void func_800D498C(void) {
    osSendMesg(&D_801C1BA0, 0, 1);
}

void func_800D49B8(void) {
    osRecvMesg(&D_801C1BA0, NULL, 1);
}

void func_800D49E4(OSContPad* arg0, s32 arg1) {
    osContStartReadData(&D_8019CFC0);
    osRecvMesg(&D_8019CFC0, 0, 1);
    if (!(arg1 & D_801C1BEC)) {
        func_800D498C();
        osContGetReadData(arg0);
        func_800D49B8();
    }
}

void func_800D4A54(UnkController* arg0) {
    osContStartQuery(&D_8019CFC0);
    osRecvMesg(&D_8019CFC0, NULL, 1);
    osContGetQuery(&D_801C1BC0);
    osSendMesg(arg0->mesgQueue, 0, 0);
}

s32 func_800D4AB0(UnkController* arg0) {
    s32 var; //TODO: why is this required?
    
    switch (arg0->unk_00) {
    case 0x1:
        osRecvMesg(&D_801C1B60, NULL, 0);
        if (D_800F1F60 != NULL) {
            D_800F1F60(arg0->unk_00);
        }
        osSendMesg(&D_801C1B60, NULL, 0);
        return 0;
    case 0x1000:
        func_800D49E4(arg0->unk_08, 0);
        osSendMesg(arg0->mesgQueue, NULL, 0);
        var = 1;
        break;
    case 0x1001:
        osRecvMesg(&D_801C1B60, NULL, 0);
        func_800D49E4(&D_801C1BD0, 0);
        if (D_800F1F60 != NULL) {
            D_800F1F60(arg0->unk_00);
        }
        osSendMesg(&D_801C1B60, NULL, 0);
        var = 1;
        break;
    case 0x1002:
        func_800D4A54(arg0);
        return 1;
    default:
        return 0;
    }
    return var;
}
