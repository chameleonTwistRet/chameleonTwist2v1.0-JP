#include "common.h"

#define ALIGN_4(x) (((x) >> 1) * 2)

s32 DmaRequest_InsertAtPriority(u32 segmentedAddr, s32 ramAddr, void* counter, s32 dmaSize, s32 priority);
s32 func_8002AA70(s32);
void func_80035C2C(char*, ...);
s32 func_8003A998(s32, s32, void*);
void func_800E0804(void*, char*, s32);
extern u8 D_213970[];
extern s32 D_80162DC0;
extern s32 D_801651B0;

typedef struct StageLoadData {
    s32 segmentedAddr;
    s32 ramAddr;
    // Could rename to s32 refCount
    s32 counter; // < 0 means DMA in flight, 0 means unloaded, 1 means loaded with one ref, and >= 2 means multiple refs
} StageLoadData;

extern StageLoadData gStageLoadData[];

#define SEGMENT_MASK 0x0F000000
#define SEGMENT_OFFSET_CUSTOM(x)        (((u32)(x) & ~SEGMENT_MASK))

s32 Stage_Open(s32 arg0) {
    u32 segAddr;
    char pad1[0x4];
    s32 dmaSize;
    char pad2[8];
    s32 temp_v0;
    char sp38[0x8];
    StageLoadData* stage;

    func_80035C2C("StageOpen In\n");
    stage = &gStageLoadData[arg0];

    if (stage->counter > 0) {
        if (stage->ramAddr == NULL) {
            func_80035C2C("StageOpen Err !!  Ram Address NULL but Counter is Plus\n");
            return -3;
        }
        stage->counter++;
        return -3;
    }
    
    if (stage->counter < 0) {
        stage->counter--;
        return -2;
    }
    
    func_80035C2C("Start Add %X\n", (u32)D_213970);
    segAddr = SEGMENT_OFFSET_CUSTOM(stage->segmentedAddr) + (u32)D_213970;

    dmaSize = ALIGN_4(stage[1].segmentedAddr - stage[0].segmentedAddr);
    
    func_80035C2C("Size = %d\n", dmaSize, (u32)D_213970);
    func_800E0804(&sp38, "StageOpen %d ", dmaSize);
    stage->ramAddr = func_8003A998(D_801651B0, dmaSize, &sp38);
    
    if (stage->ramAddr == NULL) {
        func_80035C2C("// 確保できなかった\n"); //could not secure
        return -4;
    }
    
    func_80035C2C("// 読み込み開始\n"); //Loading...
    temp_v0 = DmaRequest_InsertAtPriority(segAddr, stage->ramAddr, &stage->counter, dmaSize, 100); //is 100 the thread the DMA was started on?
    if (temp_v0 < 0) {
        return temp_v0;
    }
    
    while (func_8002AA70(temp_v0) == 0) {}
    while (func_8002AA70(temp_v0) == 0) {}
    while (func_8002AA70(temp_v0) == 0) {}

    
    func_80035C2C("// 読み込み終了\n"); //loading complete
    D_80162DC0 = dmaSize;
    return 0;
}

const char mapStr[] = "MAP(%X),%d<%d>\n";

// Stage_FreeCallback (?)
#pragma GLOBAL_ASM("asm/nonmatchings/2B30/func_80027918.s")

#pragma GLOBAL_ASM("asm/nonmatchings/2B30/Stage_Close.s") 
//calls: func_80027918

// Stage_CloseAll (?)
#pragma GLOBAL_ASM("asm/nonmatchings/2B30/func_80027B14.s") 
//calls: Stage_Close (SPRクローズできない | Unable to close)
//https://decomp.me/scratch/IKO7r
