#include "common.h"
#include "PR/os_message.h"

typedef struct unk {
    struct unk* unk0;
    OSMesgQueue* queue;
    s16 unk8;
} unk;

extern void		osWritebackDCacheAll(void);
void func_800E03F0(void);                                  /* extern */
extern void (*D_800F1F80)(void);
extern OSMesgQueue D_8019CEB0;
extern OSMesgQueue D_801C7E44;
extern s32 D_801C8450;
void func_800D5AA4(s16* arg0);
void osViSetYScale(f32);

extern OSMesgQueue D_801C7DD4;
extern OSMesgQueue D_801C7E7C;
extern OSMesgQueue D_801C7EEC;

typedef struct unkTaskStruct {
/* 0x00 */ OSMesg mesg;
/* 0x04 */ char unk_04[12];
/* 0x10 */ OSTask tp; //unknown size
/* 0x50 */ OSMesgQueue* MesgQueue;
/* 0x54 */ OSMesg Mesg;
} unkTaskStruct;

typedef struct unkTaskStruct2 {
    s16 unk_00[2];
    char unk_04[0x668];
    unkTaskStruct* unk66C;
    unkTaskStruct* unk670;
    s32 unk674;
} unkTaskStruct2;

extern unkTaskStruct2 D_801C7DD0;

extern unk* D_801C8438;

#pragma GLOBAL_ASM("asm/nonmatchings/B0A20/func_800D5620.s")

OSMesgQueue* func_800D5854(void) {
    return &D_801C7DD4;
}

extern s32 D_801C7E0C;

s32* func_800D5860(void) {
    return &D_801C7E0C;
}

void func_800D586C(void) {
    OSMesg sp54;
    s32 temp_t7;

    D_801C8450 = 0;
    while (1) {
        osRecvMesg(&D_801C7E44, &sp54, 1);
        if (sp54 != (void* )0x29A) {
            if (sp54 != (void* )0x29D) {
                continue;
            }
        } else {
            D_801C8450++;
            if (D_801C8450 & 1) {
                func_800D5AA4(D_801C7DD0.unk_00);
                continue;
            } else {
                osSendMesg(&D_8019CEB0, D_801C7DD0.unk_00, 0);
                continue;
            }            
        }

        osViSetYScale(1.0f);
        func_800E03F0();
        func_800D5AA4(&D_801C7DD0.unk_00[1]);
        if (D_800F1F80 == NULL) {
            continue;
        }
        D_800F1F80();
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/B0A20/func_800D59B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B0A20/func_800D5A14.s")

void func_800D5AA4(s16* arg0) {
    unk* var_s0;

    var_s0 = D_801C8438;
    while (var_s0 != NULL) {
        if (*arg0 & var_s0->unk8) {
            osSendMesg(var_s0->queue, arg0, 0);
        }
        var_s0 = var_s0->unk0;
    }
}

void func_800D5B08(void) {
    unkTaskStruct* temp_s1;
    unkTaskStruct* sp50;
    void* sp4C;
    s32 var_s0;

    while (1) {
        var_s0 = 0;
        osRecvMesg(&D_801C7DD4, (void*)&sp50, 1);
        osWritebackDCacheAll();
        temp_s1 = D_801C7DD0.unk66C;
        if (temp_s1 != 0) {
            osSpTaskYield();
            osRecvMesg(&D_801C7E7C, &sp4C, 1);
            if (osSpTaskYielded(&temp_s1->tp) != 0) {
                var_s0 = 1;
            } else {
                var_s0 = 2;
            }
        }
        D_801C7DD0.unk670 = sp50;
        osSpTaskLoad(&sp50->tp);
        osSpTaskStartGo(&sp50->tp);
        osRecvMesg(&D_801C7E7C, &sp4C, 1);
        D_801C7DD0.unk670 = NULL;
        if (D_801C7DD0.unk674 != 0) {
            osSendMesg(&D_801C7EEC, &sp4C, 1);
        }
        
        if (var_s0 == 1) {
            osSpTaskLoad(&temp_s1->tp);
            osSpTaskStartGo(&temp_s1->tp);
        } else if (var_s0 == 2) {
            osSendMesg(&D_801C7E7C, &sp4C, 1);
        }

        osSendMesg(sp50->MesgQueue, sp50->Mesg, 1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/B0A20/func_800D5C90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B0A20/func_800D5E08.s")
