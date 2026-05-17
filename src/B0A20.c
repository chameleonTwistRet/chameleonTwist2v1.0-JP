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

extern OSMesgQueue gScAudioCmdQueue;
extern OSMesgQueue gScSPMesgQueue;
extern OSMesgQueue gScYieldMesgQueue;
extern OSMesgQueue gScDPMesgQueue;
extern ScTaskManager gScScheduler;
extern OSMesgQueue gScGraphicsCmdQueue;
extern ScClient* D_801C8438;
extern void* gScAudioCmdMsgBuf;
extern void* gScGraphicsCmdMsgBuf;
extern OSMesgQueue gScRetraceQueue;
extern void* gScRetraceMsgBuf;
extern void* gScSPMsgBuf;
extern void* gScDPMsgBuf;
extern void* gScYieldMsgBuf;
extern OSThread gScViThread;
extern OSThread gScAudioThread;
extern OSThread gScGraphicsThread;
extern OSViMode gViModeTable[];
extern void (*D_800F1F80)(void);
extern OSMesgQueue D_8019CEB0;
extern OSMesgQueue gScRetraceQueue;
extern s32 D_801C8450;

extern char gScViThreadStack[0x2000];
extern char gScAudioThreadStack[0x2000];
extern char gScGraphicsThreadStack[0x2000];

void nnScExecuteGraphics (void);
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
void Scheduler_Init(u8 viMode, u8 retraceCount) {
    gScScheduler.pendingTask = NULL;
    gScScheduler.runningTask = NULL;
    gScScheduler.yieldedTask = NULL;
    gScScheduler.clientList = NULL;
    gScScheduler.unk_00 = 1; //OS_SC_RETRACE_MSG ?
    gScScheduler.unk_02 = 2; //OS_SC_DONE_MSG
    gScScheduler.unk678 = retraceCount;

    osCreateMesgQueue(&gScRetraceQueue, &gScRetraceMsgBuf, 8);
    osCreateMesgQueue(&gScSPMesgQueue, &gScSPMsgBuf, 8);
    osCreateMesgQueue(&gScDPMesgQueue, &gScDPMsgBuf, 8);
    osCreateMesgQueue(&gScGraphicsCmdQueue, &gScGraphicsCmdMsgBuf, 8);
    osCreateMesgQueue(&gScAudioCmdQueue, &gScAudioCmdMsgBuf, 8);
    osCreateMesgQueue(&gScYieldMesgQueue, &gScYieldMsgBuf, 8);

    osCreateViManager(OS_PRIORITY_VIMGR);
    osViSetMode(&gViModeTable[viMode]);

    if (osTvType == 0) {
        osViSetYScale(0.833f);
    }

    osViBlack(1);
    osViSetEvent(&gScRetraceQueue, (void*)0x29A, retraceCount);
    osSetEventMesg(OS_EVENT_SP, &gScSPMesgQueue, (void*)0x29B);
    osSetEventMesg(OS_EVENT_DP, &gScDPMesgQueue, (void*)0x29C);
    osSetEventMesg(OS_EVENT_PRENMI, &gScRetraceQueue, (void*)0x29D);

    osCreateThread(&gScViThread, 0x13, (void*)func_800D586C, &gScScheduler, STACK_START(gScViThreadStack), 0x78);
    osStartThread(&gScViThread);

    osCreateThread(&gScAudioThread, 0x12, (void*)nnScExecuteAudio, &gScScheduler, STACK_START(gScAudioThreadStack), 0x6E);
    osStartThread(&gScAudioThread);

    osCreateThread(&gScGraphicsThread, 0x11, (void*)nnScExecuteGraphics , &gScScheduler, STACK_START(gScGraphicsThreadStack), 0x64);
    osStartThread(&gScGraphicsThread);
}

OSMesgQueue* nnScGetAudioCmdQueue(void) {
    return &gScAudioCmdQueue;
}

OSMesgQueue* nnScGetGraphicsCmdQueue(void) {
    return &gScGraphicsCmdQueue;
}

/* Main VI / pre-NMI thread (nnScEventHandler?) */
void func_800D586C(void) {
    OSMesg sp54;
    s32 temp_t7;

    D_801C8450 = 0;
    while (1) {
        osRecvMesg(&gScRetraceQueue, &sp54, 1);
        if (sp54 != (void*)0x29A) {
            if (sp54 != (void*)0x29D) {
                continue;
            }
        } else {
            D_801C8450++;
            if (D_801C8450 & 1) {
                func_800D5AA4(&gScScheduler.unk_00);
                continue;
            } else {
                osSendMesg(&D_8019CEB0, &gScScheduler.unk_00, 0);
                continue;
            }
        }

        osViSetYScale(1.0f);
        osAfterPreNMI();
        func_800D5AA4(&gScScheduler.unk_02);
        if (D_800F1F80 == NULL) {
            continue;
        }
        D_800F1F80();
    }
}

/* Add a client node to the manager's clientList */
void nnScAddClient(ScClientNode* node, void* queuePtr, s16 flags) {
    u32 mask = osSetIntMask(1);

    node->msgQueuePtr = queuePtr;
    node->next = gScScheduler.clientList;
    node->flags = flags;
    gScScheduler.clientList = node;

    osSetIntMask(mask);
}

/* Remove a registered client from the global client list */
void nnScRemoveClient(ScClient** clientPtr) {
    ScClient* curr = D_801C8438;
    ScClient* prev = NULL;
    u32 mask = osSetIntMask(1);

    while (curr != NULL) {
        /* comparison as u32 required or doesn't match */
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
        osRecvMesg(&gScAudioCmdQueue, (void*)&sp50, 1);
        osWritebackDCacheAll();

        yielded = gScScheduler.pendingTask;
        if (yielded != NULL) {
            osSpTaskYield();
            osRecvMesg(&gScSPMesgQueue, &sp4C, 1);
            if (osSpTaskYielded(&yielded->tp) != 0) {
                resumeState = 1;
            } else {
                resumeState = 2;
            }
        }

        gScScheduler.runningTask = sp50;
        osSpTaskStart(&sp50->tp);
        osRecvMesg(&gScSPMesgQueue, &sp4C, 1);
        gScScheduler.runningTask = NULL;

        if (gScScheduler.yieldedTask != NULL) {
            osSendMesg(&gScYieldMesgQueue, &sp4C, 1);
        }

        if (resumeState == 1) {
            osSpTaskStart(&yielded->tp);
        } else if (resumeState == 2) {
            osSendMesg(&gScSPMesgQueue, &sp4C, 1);
        }

        osSendMesg(sp50->MesgQueue, sp50->Mesg, 1);
    }
}

/* Main graphics/task thread */
void nnScExecuteGraphics (void) {
    void* sp44;
    ScTask* sp40;
    u32 mask;

    while (1) {
        osRecvMesg(&gScGraphicsCmdQueue, (void*)&sp40, 1);
        nnScWaitTaskReady(sp40);

        mask = osSetIntMask(1);
        if (gScScheduler.runningTask != NULL) {
            gScScheduler.yieldedTask = sp40;
            osSetIntMask(mask);
            osRecvMesg(&gScYieldMesgQueue, &sp44, 1);
            mask = osSetIntMask(1);
            gScScheduler.yieldedTask = NULL;
        }
        osSetIntMask(mask);

        mask = osSetIntMask(1);
        gScScheduler.pendingTask = sp40;
        osSetIntMask(mask);

        osSpTaskStart(&sp40->tp);
        osRecvMesg(&gScSPMesgQueue, &sp44, 1);

        mask = osSetIntMask(1);
        gScScheduler.pendingTask = NULL;
        osSetIntMask(mask);

        if (!(sp40->unk_08 & 2)) {
            osRecvMesg(&gScDPMesgQueue, &sp44, 1);
        }
        osSendMesg(sp40->MesgQueue, sp40, 1);
    }
}

/* Wait until a task's framebuffer is not the current or pending framebuffer.
   The function registers a stack node as a client and removes it afterwards. */
void nnScWaitTaskReady(ScTask* task) {
    ScClientNode stackNode;
    void* framebuffer = task->framebuffer;

    nnScAddClient(&stackNode, &gScYieldMesgQueue, 1);
    while ((osViGetCurrentFramebuffer() == framebuffer) || (func_800DC9A0() == framebuffer)) {
        osRecvMesg(&gScYieldMesgQueue, NULL, 1);
        if (framebuffer != NULL) {
            continue;
        }
    }

    nnScRemoveClient((ScClient**)&stackNode);
}
