#include "common.h"

void func_800CFDAC(void*, void*);                         /* extern */
extern s32 D_8019CAD0;
extern s32 D_8019CE58;

//#pragma GLOBAL_ASM("asm/nonmatchings/A89D0/func_800CD5D0.s")
void func_800CD5D0(unk_func_800CD5D0* arg0) {
    arg0->unk8 = &D_8019CAD0;
    func_800CFDAC(&D_8019CE58, arg0);
}