#include "common.h"

// handwritten ASM
/*
.text
LEAF(osGetCount)
    STAY2(mfc0 v0, C0_COUNT)
    jr ra
END(osGetCount)
*/
#pragma GLOBAL_ASM("asm/nonmatchings/os/getcount/osGetCount.s")
