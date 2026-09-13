#include "common.h"

typedef struct UnkC {
    /* 0x00 */ char   unk00[0x8];
    /* 0x08 */ Rect3D bounds;
} UnkC;

typedef struct Object {
    /* 0x00 */ struct Object* prev;
    /* 0x04 */ struct Object* next;
    /* 0x08 */ char  unk08[0x4];
    /* 0x0C */ UnkC* collider;
    /* 0x10 */ char  unk10[0x44];
    /* 0x54 */ s32   kind;
    /* 0x58 */ char  unk58[0x14];
    /* 0x6C */ Vec3f pos;
    /* 0x78 */ char  unk78[0x2C];
    /* 0xA4 */ struct Object* unk_A4;
    /* 0xA8 */ s16 unk_A8;
    /* 0xAA */ char unk_AA[0x32];
    /* 0xDC */ s16 unkDC;
} Object;

/* externs */
s32 IfRectsIntersect(Rect3D*, Rect3D*);
void func_80043824(Object*, s32);

extern Object* D_800ECBC4;   /* object to exclude from the sweep */
extern Object* D_80160660;   /* list manager */
extern Object* D_80160800;   /* list tail sentinel */

void Poly_EnsureInfoLevel(unk_func_80040C10*, s32);

s32 func_80040C10(unk_func_80040C10* arg0, s32 arg1) {
    if (arg0->unk2 < 0) {
        return 0;
    }
    Poly_EnsureInfoLevel(arg0, 1);
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/1C010/func_80040C4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1C010/func_80040CA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1C010/func_80040E3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1C010/func_80041450.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1C010/func_80041778.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1C010/func_800418C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1C010/func_800419B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1C010/func_80041C00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1C010/func_80041F3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1C010/func_80041FDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1C010/func_800422B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1C010/func_80042398.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1C010/func_800429E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1C010/func_80042B94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1C010/func_80042BD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1C010/func_80042C14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1C010/func_80042C48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1C010/func_80042C7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1C010/func_800430DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1C010/func_80043174.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1C010/func_80043824.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1C010/func_80043918.s")

s32 func_80043A50(Rect3D* arg0, s32 arg1) {
    Object* obj;
    char pad[8];
    Rect3D sp44;
    s32 count;

    obj = D_80160660->next;
    count = 0;

    while (obj != D_80160800) {
        if (obj != D_800ECBC4) {
            if (obj->kind >= 0xC352) {
                break;
            }
            if ((obj->kind >= 0xC351) && (obj->collider != NULL)) {
                sp44 = *arg0;

                sp44.max.x -= obj->pos.x;
                sp44.max.y -= obj->pos.y;
                sp44.max.z -= obj->pos.z;
                sp44.min.x -= obj->pos.x;
                sp44.min.y -= obj->pos.y;
                sp44.min.z -= obj->pos.z;

                if (!obj->collider) {}

                if (IfRectsIntersect(&sp44, &obj->collider->bounds) == 0) {
                    //
                } else {
                    func_80043824(obj, 1);
                    count++;
                }
            }
        }
        obj = obj->next;
    }

    return count;
}

extern f32 D_800EAED4;

s32 func_80043BDC(Rect3D* arg0, s32 arg1) {
    Object* obj;
    s32 count;
    f32 recip;
    Rect3D sp54;
    UnkC *new_var;
    
    obj = D_80160660->next;
    count = 0;

    while (obj != D_80160800) {
        if (obj->kind >= 0xC352) {
            break;
        }
        if ((obj->kind >= 0xC351) && (obj->collider != NULL)) {
            sp54 = *arg0;

            sp54.max.x -= obj->pos.x;
            sp54.max.y -= obj->pos.y;
            sp54.max.z -= obj->pos.z;
            sp54.min.x -= obj->pos.x;
            sp54.min.y -= obj->pos.y;
            sp54.min.z -= obj->pos.z;
            new_var = obj->collider;

            if (obj->unkDC == 5) {
                recip = 1.0 / D_800EAED4;
                sp54.max.x *= recip;
                sp54.max.z *= recip;
                sp54.min.x *= recip;
                sp54.min.z *= recip;
            } else if (obj->unkDC == 4) {
                recip = 1.0 / D_800EAED4;
                if (obj) {}
                sp54.max.x *= recip;
                sp54.max.y *= recip;
                sp54.min.x *= recip;
                sp54.min.y *= recip;
            }

            

            if (IfRectsIntersect(&sp54, &new_var->bounds) == 0) {
                //
            } else {
                func_80043824(obj, 2);
                count++;
            }
        }
        obj = obj->next;
    }

    return count;
}

void func_80043E1C(Object* obj) {
    while (obj != NULL) {
        if (obj->unk_A8 == 0) {
            break;
        }
        obj->unk_A8 = 0;
        obj = obj->unk_A4;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/1C010/func_80043E48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1C010/func_80043E84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1C010/func_80043F90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1C010/func_80043FF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1C010/func_80044070.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1C010/func_800440A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1C010/func_80044354.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1C010/func_800443F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1C010/func_800446D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1C010/func_80045B0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1C010/func_80045E1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1C010/func_80046024.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1C010/func_80046178.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1C010/func_8004637C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1C010/func_8004641C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1C010/CheckTongueCollision.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1C010/func_800469C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1C010/func_80047164.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1C010/func_80047250.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1C010/func_800472A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1C010/func_800473C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1C010/func_80047CA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1C010/func_80047CD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1C010/D_800F5E8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1C010/D_800F5E94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1C010/D_800F5EA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1C010/D_800F5EB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1C010/D_800F5EBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1C010/D_800F5EC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1C010/D_800F5ED8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1C010/D_800F5EE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1C010/D_800F5EF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1C010/D_800F5F0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1C010/D_800F5F18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1C010/D_800F5F24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1C010/D_800F5F30.s")
