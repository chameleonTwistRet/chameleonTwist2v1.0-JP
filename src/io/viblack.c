#include "common.h"
#include "viint.h"

//#pragma GLOBAL_ASM("asm/nonmatchings/io/viblack/osViBlack.s")
void osViBlack(u8 active)
{
    register u32 saveMask = __osDisableInt();
    if (active)
        __osViNext->state |= VI_STATE_BLACK;
    else
        __osViNext->state &= ~VI_STATE_BLACK;
    __osRestoreInt(saveMask);
}
