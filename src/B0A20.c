#include "common.h"
#include "PR/os_message.h"
#include "PR/os_exception.h"


#define STACK_START(stack) \
    ((u8*)(stack) + sizeof(stack))

typedef struct unk {
    struct unk* unk0;
    OSMesgQueue* queue;
    s16 unk8;
} unk;

typedef struct unkTaskStruct {
    /* 0x00 */ void* mesg;
    /* 0x04 */ char pad4[4];
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ void* framebuffer;
    /* 0x10 */ OSTask tp;
    /* 0x50 */ OSMesgQueue* MesgQueue;
    /* 0x54 */ void* Mesg;
} unkTaskStruct;

typedef struct unkTaskStruct4 {
    struct unkTaskStruct4* unk_00; //TODO: is this right?
    void* unk_04;
    s16 unk_08;
} unkTaskStruct4;

typedef struct unkTaskStruct2 {
    s16 unk_00;
    s16 unk_02;
    char unk_04[0x664];
    unkTaskStruct4* unk668;
    unkTaskStruct* unk66C;
    unkTaskStruct* unk670;
    unkTaskStruct* unk674;
    s32 unk678;
} unkTaskStruct2;

typedef struct UnkTaskStruct3 {
    OSViMode* unk_00;
    char unk_04[0x4C];
} UnkTaskStruct3;

extern OSMesgQueue D_801C7DD4;
extern OSMesgQueue D_801C7E7C;
extern OSMesgQueue D_801C7EEC;
extern OSMesgQueue D_801C7EB4;
extern unkTaskStruct2 D_801C7DD0;
extern OSMesgQueue D_801C7E0C;
extern unk* D_801C8438;
extern void* D_801C7DEC;
extern void* D_801C7E24;
extern OSMesgQueue D_801C7E44;
extern void* D_801C7E5C;
extern OSMesgQueue D_801C7E7C;
extern void* D_801C7E94;
extern OSMesgQueue D_801C7EB4;
extern void* D_801C7ECC;
extern OSMesgQueue D_801C7EEC;
extern void* D_801C7F04;
extern OSThread D_801C7F28;
extern OSThread D_801C80D8;
extern OSThread D_801C8288;
extern OSViMode D_800F2E20[];
extern void (*D_800F1F80)(void);
extern OSMesgQueue D_8019CEB0;
extern OSMesgQueue D_801C7E44;
extern s32 D_801C8450;

extern char D_801C1DD0[0x2000];
extern char D_801C3DD0[0x2000];
extern char D_801C5DD0[0x2000];

void func_800D5C90(void);
void func_800D586C(void);
void nnScExecuteAudio(void);
void osWritebackDCacheAll(void);
void osAfterPreNMI(void);
void func_800D5AA4(s16* arg0);
void osViSetYScale(f32);
void nnScWaitTaskReady(unkTaskStruct*);
void* func_800DC9A0(void);
OSIntMask osSetIntMask(OSIntMask);


void func_800D5620(u8 arg0, u8 arg1) {
    D_801C7DD0.unk66C = 0;
    D_801C7DD0.unk670 = 0;
    D_801C7DD0.unk674 = 0;
    D_801C7DD0.unk668 = NULL;
    D_801C7DD0.unk_00 = 1;
    D_801C7DD0.unk_02 = 2;
    D_801C7DD0.unk678 = arg1;
    osCreateMesgQueue(&D_801C7E44, &D_801C7E5C, 8);
    osCreateMesgQueue(&D_801C7E7C, &D_801C7E94, 8);
    osCreateMesgQueue(&D_801C7EB4, &D_801C7ECC, 8);
    osCreateMesgQueue(&D_801C7E0C, &D_801C7E24, 8);
    osCreateMesgQueue(&D_801C7DD4, &D_801C7DEC, 8);
    osCreateMesgQueue(&D_801C7EEC, &D_801C7F04, 8);
    osCreateViManager(0xFE);
    osViSetMode(&D_800F2E20[arg0]);

    if (osTvType == 0) {
        osViSetYScale(0.833f);
    }

    osViBlack(1);
    osViSetEvent(&D_801C7E44, (void* )0x29A, (u32) arg1);
    osSetEventMesg(4, &D_801C7E7C, (void* )0x29B);
    osSetEventMesg(9, &D_801C7EB4, (void* )0x29C);
    osSetEventMesg(0xE, &D_801C7E44, (void* )0x29D);
    osCreateThread(&D_801C7F28, 0x13, (void*)func_800D586C, &D_801C7DD0, STACK_START(D_801C1DD0), 0x78);
    osStartThread(&D_801C7F28);
    osCreateThread(&D_801C80D8, 0x12, (void*)nnScExecuteAudio, &D_801C7DD0, STACK_START(D_801C3DD0), 0x6E);
    osStartThread(&D_801C80D8);
    osCreateThread(&D_801C8288, 0x11, (void*)func_800D5C90, &D_801C7DD0, STACK_START(D_801C5DD0), 0x64);
    osStartThread(&D_801C8288);
}

OSMesgQueue* func_800D5854(void) {
    return &D_801C7DD4;
}

OSMesgQueue* func_800D5860(void) {
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
                func_800D5AA4(&D_801C7DD0.unk_00);
                continue;
            } else {
                osSendMesg(&D_8019CEB0, &D_801C7DD0.unk_00, 0);
                continue;
            }            
        }

        osViSetYScale(1.0f);
        osAfterPreNMI();
        func_800D5AA4(&D_801C7DD0.unk_02);
        if (D_800F1F80 == NULL) {
            continue;
        }
        D_800F1F80();
    }
}

void nnScAddClient(unkTaskStruct4* arg0, void* arg1, s16 arg2) {
    u32 mask;

    mask = osSetIntMask(1);
    
    arg0->unk_04 = arg1;
    arg0->unk_00 = D_801C7DD0.unk668;
    arg0->unk_08 = arg2;
    D_801C7DD0.unk668 = arg0;
    
    osSetIntMask(mask);
}

void nnScRemoveClient(unk** arg0) {
    unk* curr = D_801C8438;
    unk* prev = NULL;
    u32 mask = osSetIntMask(1);
    
    while (curr != NULL) {
        if ((u32)curr == (u32)arg0) {
            // Found the client to remove
            if (prev != NULL) {
                prev->unk0 = *arg0;  // unlink it
            } else {
                D_801C8438 = *arg0;  // removing head
            }
            break;
        }

        prev = curr;
        curr = curr->unk0;
    }

    osSetIntMask(mask);
}

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

void nnScExecuteAudio(void) {
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
        osSpTaskStart(&sp50->tp)
        osRecvMesg(&D_801C7E7C, &sp4C, 1);
        D_801C7DD0.unk670 = NULL;
        if (D_801C7DD0.unk674 != 0) {
            osSendMesg(&D_801C7EEC, &sp4C, 1);
        }
        
        if (var_s0 == 1) {
            osSpTaskStart(&temp_s1->tp);
        } else if (var_s0 == 2) {
            osSendMesg(&D_801C7E7C, &sp4C, 1);
        }

        osSendMesg(sp50->MesgQueue, sp50->Mesg, 1);
    }
}

//main graphics function
void func_800D5C90(void) {
    void* sp44;
    unkTaskStruct* sp40;
    u32 mask;

    while (1) {
        osRecvMesg(&D_801C7E0C, (void*)&sp40, 1);
        nnScWaitTaskReady(sp40);
        mask = osSetIntMask(1U);
        if (D_801C7DD0.unk670 != 0) {
            D_801C7DD0.unk674 = sp40;
            osSetIntMask(mask);
            osRecvMesg(&D_801C7EEC, &sp44, 1);
            mask = osSetIntMask(1U);
            D_801C7DD0.unk674 = NULL;
        }
        osSetIntMask(mask);
        mask = osSetIntMask(1U);
        D_801C7DD0.unk66C = sp40;
        osSetIntMask(mask);
        osSpTaskStart(&sp40->tp)
        osRecvMesg(&D_801C7E7C, &sp44, 1);
        mask = osSetIntMask(1U);
        D_801C7DD0.unk66C = NULL;
        osSetIntMask(mask);
        if (!(sp40->unk_08 & 2)) {
            osRecvMesg(&D_801C7EB4, &sp44, 1);
        }
        osSendMesg(sp40->MesgQueue, sp40, 1);        
    }
}

void nnScWaitTaskReady(unkTaskStruct* arg0) {
    unkTaskStruct4 sp24;
    void* framebuffer;

    framebuffer = arg0->framebuffer;
    nnScAddClient(&sp24, &D_801C7EEC, 1);
    while ((osViGetCurrentFramebuffer() == framebuffer) || (func_800DC9A0() == framebuffer)) {
        osRecvMesg(&D_801C7EEC, NULL, 1);
        if (framebuffer != NULL) {
            continue;
        }
    }
    
    nnScRemoveClient((unk** ) &sp24);
}