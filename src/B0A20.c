#include "common.h"
#include "PR/os_message.h"
#include "PR/os_exception.h"


#define STACK_START(stack) \
    ((u8*)(stack) + sizeof(stack))

/* Linked-list client registered to receive events */
typedef struct ScClient {
    struct ScClient* next;     /* was unk0 */
    OSMesgQueue* msgQueue;     /* was queue */
    s16 maskFlag;              /* was unk8 */
} ScClient;

/* Audio / graphics task wrapper */
typedef struct ScTask {
    /* 0x00 */ void* mesg;
    /* 0x04 */ char pad4[4];
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ void* framebuffer;
    /* 0x10 */ OSTask tp;
    /* 0x50 */ OSMesgQueue* MesgQueue;
    /* 0x54 */ void* Mesg;
} ScTask;

/* Small registration node used for waiting clients */
typedef struct ScClientNode {
    struct ScClientNode* next; /* was unk_00 (keeps linked-list usage similar) */
    void* msgQueuePtr;         /* was unk_04 */
    s16 flags;                 /* was unk_08 */
} ScClientNode;

/* Big per-system task state */
typedef struct ScTaskManager {
    s16 unk_00;
    s16 unk_02;
    char unk_04[0x664];
    ScClientNode* clientList;   /* was unk668 */
    ScTask* pendingTask;        /* was unk66C */
    ScTask* runningTask;        /* was unk670 */
    ScTask* yieldedTask;        /* was unk674 */
    s32 unk678;
} ScTaskManager;

/* Externs (kept their original names) */
extern OSMesgQueue D_801C7DD4;
extern OSMesgQueue D_801C7E7C;
extern OSMesgQueue D_801C7EEC;
extern OSMesgQueue D_801C7EB4;
extern ScTaskManager D_801C7DD0;
extern OSMesgQueue D_801C7E0C;
extern ScClient* D_801C8438;
extern void* D_801C7DEC;
extern void* D_801C7E24;
extern OSMesgQueue D_801C7E44;
extern void* D_801C7E5C;
extern OSMesgQueue D_801C7E7C; /* duplicate extern in original - kept */
extern void* D_801C7E94;
extern OSMesgQueue D_801C7EB4; /* duplicate extern in original - kept */
extern void* D_801C7ECC;
extern OSMesgQueue D_801C7EEC; /* duplicate extern in original - kept */
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

/* Forward declarations (kept same names except for type clarity) */
void func_800D5C90(void);
void func_800D586C(void);
void nnScExecuteAudio(void);
void osWritebackDCacheAll(void);
void osAfterPreNMI(void);
void func_800D5AA4(s16* arg0);
void osViSetYScale(f32);
void nnScWaitTaskReady(ScTask*);
void* func_800DC9A0(void);
OSIntMask osSetIntMask(OSIntMask);


/* Initialize the subsystem: create queues, vmanager, threads */
void func_800D5620(u8 arg0, u8 arg1) {
    D_801C7DD0.pendingTask = 0;
    D_801C7DD0.runningTask = 0;
    D_801C7DD0.yieldedTask = 0;
    D_801C7DD0.clientList = NULL;
    D_801C7DD0.unk_00 = 1;
    D_801C7DD0.unk_02 = 2;
    D_801C7DD0.unk678 = arg1;

    osCreateMesgQueue(&D_801C7E44, &D_801C7E5C, 8);
    osCreateMesgQueue(&D_801C7E7C, &D_801C7E94, 8);
    osCreateMesgQueue(&D_801C7EB4, &D_801C7ECC, 8);
    osCreateMesgQueue(&D_801C7E0C, &D_801C7E24, 8);
    osCreateMesgQueue(&D_801C7DD4, &D_801C7DEC, 8);
    osCreateMesgQueue(&D_801C7EEC, &D_801C7F04, 8);

    osCreateViManager(OS_PRIORITY_VIMGR);
    osViSetMode(&D_800F2E20[arg0]);

    if (osTvType == 0) {
        osViSetYScale(0.833f);
    }

    osViBlack(1);
    osViSetEvent(&D_801C7E44, (void*)0x29A, (u32)arg1);
    osSetEventMesg(4, &D_801C7E7C, (void*)0x29B);
    osSetEventMesg(9, &D_801C7EB4, (void*)0x29C);
    osSetEventMesg(0xE, &D_801C7E44, (void*)0x29D);

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

/* Main VI / pre-NMI thread */
void func_800D586C(void) {
    OSMesg sp54;
    s32 temp_t7;

    D_801C8450 = 0;
    while (1) {
        osRecvMesg(&D_801C7E44, &sp54, 1);
        if (sp54 != (void*)0x29A) {
            if (sp54 != (void*)0x29D) {
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

/* Add a client node to the manager's clientList (interrupt protected) */
void nnScAddClient(ScClientNode* node, void* queuePtr, s16 flags) {
    u32 mask = osSetIntMask(1);

    node->msgQueuePtr = queuePtr;         /* was unk_04 = arg1 */
    node->next = D_801C7DD0.clientList;  /* was unk_00 = manager->unk668 */
    node->flags = flags;
    D_801C7DD0.clientList = node;

    osSetIntMask(mask);
}

/* Remove a registered client from the global client list (interrupt protected)
   NOTE: arg0 is treated as a pointer that was previously passed to nnScAddClient;
   comparisons intentionally match the original decompiled behavior. */
void nnScRemoveClient(ScClient** clientPtr) {
    ScClient* curr = D_801C8438;
    ScClient* prev = NULL;
    u32 mask = osSetIntMask(1);

    while (curr != NULL) {
        //comparison as u32 required or doesn't match
        if ((u32)curr == (u32)clientPtr) {
            if (prev != NULL) {
                prev->next = *clientPtr;
            } else {
                D_801C8438 = *clientPtr;
            }
            break;
        }

        prev = curr;
        curr = curr->next;
    }

    osSetIntMask(mask);
}

/* Broadcast an event bitmask to all registered clients */
void func_800D5AA4(s16* maskPtr) {
    ScClient* iter = D_801C8438;

    while (iter != NULL) {
        if (*maskPtr & iter->maskFlag) {
            osSendMesg(iter->msgQueue, maskPtr, 0);
        }
        iter = iter->next;
    }
}

/* Audio/task executor thread */
void nnScExecuteAudio(void) {
    ScTask* yielded;
    ScTask* sp50;
    void* sp4C;
    s32 resumeState;

    while (1) {
        resumeState = 0;
        osRecvMesg(&D_801C7DD4, (void*)&sp50, 1);
        osWritebackDCacheAll();

        yielded = D_801C7DD0.pendingTask;
        if (yielded != 0) {
            osSpTaskYield();
            osRecvMesg(&D_801C7E7C, &sp4C, 1);
            if (osSpTaskYielded(&yielded->tp) != 0) {
                resumeState = 1;
            } else {
                resumeState = 2;
            }
        }

        D_801C7DD0.runningTask = sp50;
        osSpTaskStart(&sp50->tp);
        osRecvMesg(&D_801C7E7C, &sp4C, 1);
        D_801C7DD0.runningTask = NULL;

        if (D_801C7DD0.yieldedTask != 0) {
            osSendMesg(&D_801C7EEC, &sp4C, 1);
        }

        if (resumeState == 1) {
            osSpTaskStart(&yielded->tp);
        } else if (resumeState == 2) {
            osSendMesg(&D_801C7E7C, &sp4C, 1);
        }

        osSendMesg(sp50->MesgQueue, sp50->Mesg, 1);
    }
}

/* Main graphics/task thread */
void func_800D5C90(void) {
    void* sp44;
    ScTask* sp40;
    u32 mask;

    while (1) {
        osRecvMesg(&D_801C7E0C, (void*)&sp40, 1);
        nnScWaitTaskReady(sp40);

        mask = osSetIntMask(1U);
        if (D_801C7DD0.runningTask != 0) {
            D_801C7DD0.yieldedTask = sp40;
            osSetIntMask(mask);
            osRecvMesg(&D_801C7EEC, &sp44, 1);
            mask = osSetIntMask(1U);
            D_801C7DD0.yieldedTask = NULL;
        }
        osSetIntMask(mask);

        mask = osSetIntMask(1U);
        D_801C7DD0.pendingTask = sp40;
        osSetIntMask(mask);

        osSpTaskStart(&sp40->tp);
        osRecvMesg(&D_801C7E7C, &sp44, 1);

        mask = osSetIntMask(1U);
        D_801C7DD0.pendingTask = NULL;
        osSetIntMask(mask);

        if (!(sp40->unk_08 & 2)) {
            osRecvMesg(&D_801C7EB4, &sp44, 1);
        }
        osSendMesg(sp40->MesgQueue, sp40, 1);
    }
}

/* Wait until a task's framebuffer is not the current or pending framebuffer.
   The function registers a stack node as a client and removes it afterwards. */
void nnScWaitTaskReady(ScTask* task) {
    ScClientNode stackNode;
    void* framebuffer = task->framebuffer;

    nnScAddClient(&stackNode, &D_801C7EEC, 1);
    while ((osViGetCurrentFramebuffer() == framebuffer) || (func_800DC9A0() == framebuffer)) {
        osRecvMesg(&D_801C7EEC, NULL, 1);
        if (framebuffer != NULL) {
            continue;
        }
    }

    nnScRemoveClient((ScClient**)&stackNode);
}
