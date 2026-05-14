#include "common.h"
#include "viint.h"

//#pragma GLOBAL_ASM("asm/nonmatchings/B84B0/osViBlack.s")
void osViBlack(u8 active)
{
    register u32 saveMask = __osDisableInt();
    if (active)
        __osViNext->state |= VI_STATE_BLACK;
    else
        __osViNext->state &= ~VI_STATE_BLACK;
    __osRestoreInt(saveMask);
}

#pragma GLOBAL_ASM("asm/nonmatchings/B84B0/__osSpRawReadIo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B84B0/osSpTaskYield.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B84B0/__osPfsGetNextPage.s")

#pragma GLOBAL_ASM("asm/nonmatchings/B84B0/osPfsReadWriteFile.s")
