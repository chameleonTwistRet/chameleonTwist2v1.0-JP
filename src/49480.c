#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/49480/func_8006E080.s")

#pragma GLOBAL_ASM("asm/nonmatchings/49480/func_8006E134.s")

#pragma GLOBAL_ASM("asm/nonmatchings/49480/func_8006E1B4.s")

//#pragma GLOBAL_ASM("asm/nonmatchings/49480/func_8006E1C4.s")
typedef struct {
    /* 0x000 */ char pad000[0xD];
    /* 0x00D */ s8 unkD;
    /* 0x00E */ u8 unkE;
} UnkPtr8006E1C4; // size unknown

typedef struct {
    /* 0x000 */ char pad000[0x8];
    /* 0x008 */ UnkPtr8006E1C4* unk8;
} Unk8006E1C4; // size unknown

void func_8006E1C4(Unk8006E1C4* arg0) {
    UnkPtr8006E1C4* temp_v0 = arg0->unk8;
    temp_v0->unkD = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/49480/func_8006E1D0.s")
/* TODO: fix $t6 -> $v1: https://decomp.me/scratch/KVGIk
u8 func_8006E1D0(Unk8006E1C4* arg0) {
    return ((UnkPtr8006E1C4*)arg0->unk8)->unkE;
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/49480/func_8006E1DC.s")
