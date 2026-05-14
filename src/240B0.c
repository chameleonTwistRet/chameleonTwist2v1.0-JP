#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/240B0/func_80048CB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/240B0/func_80048D14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/240B0/func_80048DEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/240B0/func_80049214.s")

typedef struct OrthBasis {
/* 0x00 */ Vec3f vec1;
/* 0x0C */ Vec3f vec2;
/* 0x18 */ Vec3f normal;
} OrthBasis;

//TODO: verify Poly struct taken from ct1 (it definitely is different)
typedef struct Poly {
/* 0x00 */ char unk_00[2];
/* 0x02 */ s16 infoLevel;    // level of computation (0-3, -1=invalid)
/* 0x04 */ char unk_04[4];
/* 0x08 */ Vec3f origin;
/* 0x14 */ Vec3f edgeVec;
/* 0x20 */ Vec3f edgeVec2;
/* 0x2C */ Rect3D boundBox;
/* 0x44 */ char unk[8]; //TODO: this goes somewhere between `origin` and `orthBasis` for sure
/* 0x4C */ OrthBasis orthBasis;
/* 0x74 */ f32 unk_74;
/* 0x78 */ f32 invMtxU;
/* 0x7C */ f32 invMtxUSkew;
/* 0x80 */ f32 invMtxVSkew;
/* 0x84 */ f32 invMtxV;
/* 0x88 */ Vec2f uvOffset;
/* 0x90 */ Vec2f edgeData;
/* 0x98 */ Vec2f projData;
} Poly; //sizeof 0xA0?

void func_80035C2C(char*, ...);
void func_80048DEC(Poly*, s32);
void func_80049214(Poly* poly, s32 levelCheck, char* funcStr);

void func_8004925C(Poly* poly, s32 level) {
    s32 i;

    func_80035C2C("CheckPolyInfoLevel: %d, (%X)\n", level, poly);
    if (poly->infoLevel < level) {
        for (i = poly->infoLevel + 1; (level >= i); i++) {
            func_80048DEC(poly, i);
        }    
    }
    func_80035C2C("CheckPolyInfoLevel: (OUT)\n");
}

Vec3f* func_800492E0(Vec3f* vec, f32 perspX, f32 perspY, f32 perspZ, Poly* poly) {
    Vec3f vec_proj;
    f32 p_x;
    f32 dotProduct;
    f32 dist;
    f32 p_x2;

    func_80049214(poly, 2, "ProjectOnPolygon");
    p_x = poly->orthBasis.vec1.x;
    p_x2 = poly->orthBasis.vec2.x;
    dotProduct = (poly->orthBasis.vec1.z * perspZ) + ((perspX * p_x) + (perspY * poly->orthBasis.vec1.y));
    dist = (poly->orthBasis.vec2.z * perspZ) + ((perspX * p_x2) + (perspY * poly->orthBasis.vec2.y));
    vec_proj.x = (p_x2 * dist) + (dotProduct * p_x);
    vec_proj.y = (poly->orthBasis.vec2.y * dist) + (dotProduct * poly->orthBasis.vec1.y);
    vec_proj.z = (poly->orthBasis.vec2.z * dist) + (dotProduct * poly->orthBasis.vec1.z);
    *vec = vec_proj;
    return vec;
}

#pragma GLOBAL_ASM("asm/nonmatchings/240B0/func_800493D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/240B0/func_800494D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/240B0/func_800495D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/240B0/func_800496A4.s")
