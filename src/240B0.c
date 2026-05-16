#include "common.h"

typedef struct OrthBasis {
/* 0x00 */ Vec3f vec1;
/* 0x0C */ Vec3f vec2;
/* 0x18 */ Vec3f normal;
} OrthBasis; //sizeof 0x24

//TODO: verify Poly struct taken from ct1 (it definitely is different)
typedef struct Poly {
/* 0x00 */ char unk_00[2];
/* 0x02 */ s16 infoLevel;    // level of computation (0-3, -1=invalid)
/* 0x04 */ char unk_04[4];
/* 0x08 */ char unk[8]; //TODO: this goes somewhere between `origin` and `orthBasis` for sure
/* 0x10 */ Vec3f origin;
/* 0x1C */ Vec3f edgeVec;
/* 0x28 */ Vec3f edgeVec2;
/* 0x34 */ Rect3D boundBox; //size of struct 0x18
/* 0x48 */ OrthBasis orthBasis; //size of struct 0x24
/* 0x78 */ f32 invMtxU; //?
/* 0x7C */ f32 invMtxUSkew;
/* 0x80 */ f32 invMtxVSkew;
/* 0x84 */ f32 invMtxV;
/* 0x88 */ Vec2f uvOffset;
/* 0x90 */ Vec2f edgeData;
/* 0x98 */ Vec2f projData;
} Poly; //sizeof 0xA0?

void func_80035C2C(char*, ...);
void func_80048DEC(Poly*, s32);
void Poly_AssertInfoLevel(Poly* poly, s32 levelCheck, char* funcStr);

#pragma GLOBAL_ASM("asm/nonmatchings/240B0/func_80048CB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/240B0/func_80048D14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/240B0/func_80048DEC.s")

void Poly_AssertInfoLevel(Poly* arg0, s32 arg1, char* funcStr) {
    if (arg0->infoLevel < arg1) {
        func_80035C2C("OnlyCheckPolyInfoLevel: Need More Info Level\n");
        func_80035C2C("Function: %s\n", funcStr);
    }
}

void Poly_EnsureInfoLevel(Poly* poly, s32 level) {
    s32 i;

    func_80035C2C("CheckPolyInfoLevel: %d, (%X)\n", level, poly);
    if (poly->infoLevel < level) {
        for (i = poly->infoLevel + 1; (level >= i); i++) {
            func_80048DEC(poly, i);
        }    
    }
    func_80035C2C("CheckPolyInfoLevel: (OUT)\n");
}

/**
 * @brief Projects a given 3D vector onto a polygon in 3D space, returning the projected vector.
 * 
 * @param[in,out]  vec:    the vector to project.
 * @param          perspX: the X coordinate of the perspective point.
 * @param          perspY: the Y coordinate of the perspective point.
 * @param          perspZ: the Z coordinate of the perspective point.
 * @param          poly:   the polygon to project onto.
 * 
 * @return (Vec3f) the projected vector.
 */
Vec3f* ProjectOnPolygon(Vec3f* vec, f32 perspX, f32 perspY, f32 perspZ, Poly* poly) {
    Vec3f vec_proj;
    f32 p_x;
    f32 dotProduct;
    f32 dist;
    f32 p_x2;

    Poly_AssertInfoLevel(poly, 2, "ProjectOnPolygon");
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

/** 
 * @brief Converts a 3D vector from world space to local space. 
 * 
 * @param[in,out]  outVec: Pointer to a Vec3f where the resulting local-space vector will be stored.
 * @param          vec:    The 3D vector to be converted from world space to local space.
 * @param          poly:   The polygon with respect to which the conversion should be performed.
 *
 * @return (Vec3f) A pointer to the resulting local-space vector, stored in the `outVec` parameter.
 */
Vec3f* WorldToLocal(Vec3f* outVec, Vec3f vec, Poly* poly) {
    // Take P to be a matrix with the columns being the x, y, and z vectors of the poly struct
    // P(v) = outVec, where v is the input vector after being translated by an offset vector
    Vec3f temp_vec;
 
    Poly_AssertInfoLevel(poly, 2, "WorldToLocal");
    vec.x = vec.x - poly->origin.x;
    vec.y = vec.y - poly->origin.y;
    vec.z = vec.z - poly->origin.z;
    temp_vec.x = (poly->orthBasis.vec1.z * vec.z) + ((vec.x * poly->orthBasis.vec1.x) + (vec.y * poly->orthBasis.vec1.y));
    temp_vec.y = (poly->orthBasis.vec2.z * vec.z) + ((vec.x * poly->orthBasis.vec2.x) + (vec.y * poly->orthBasis.vec2.y));
    temp_vec.z = (poly->orthBasis.normal.z * vec.z) + ((vec.x * poly->orthBasis.normal.x) + (vec.y * poly->orthBasis.normal.y));
    *outVec = temp_vec;

    return outVec;
}

/** 
 * @brief Converts a 3D vector from local space to world space. 
 * 
 * @param[in,out] outVec:     Pointer to a Vec3f where the resulting world-space vector will be stored.
 * @param         vec:        The 3D vector to be converted from local space to world space.
 * @param         poly:       The polygon with respect to which the conversion should be performed.
 *
 * @return (Vec3f) A pointer to the resulting world-space vector, stored in the `outVec` parameter.
 */
Vec3f* LocalToWorld(Vec3f* outVec, Vec3f vec, Poly* poly) {
    Vec3f temp_vec;

    Poly_AssertInfoLevel(poly, 2, "LocalToWorld");
    temp_vec.x = (poly->orthBasis.normal.x * vec.z) + ((vec.x * poly->orthBasis.vec1.x) + (vec.y * poly->orthBasis.vec2.x));
    temp_vec.y = (poly->orthBasis.normal.y * vec.z) + ((vec.x * poly->orthBasis.vec1.y) + (vec.y * poly->orthBasis.vec2.y));
    temp_vec.z = (poly->orthBasis.normal.z * vec.z) + ((vec.x * poly->orthBasis.vec1.z) + (vec.y * poly->orthBasis.vec2.z));
    temp_vec.x += poly->origin.x;
    temp_vec.y += poly->origin.y;
    temp_vec.z += poly->origin.z;
    *outVec = temp_vec;
    return outVec;
}

/**
 * @brief Checks if a given point is inside a polygon using barycentric coordinates.
 *        Computes barycentric coordinates (U, V) of the point relative to the polygon,
 *        and returns 1 if the point lies within the triangle (U >= 0, V >= 0, U+V <= 1).
 * 
 * @param vec:  the point to check.
 * @param poly: the polygon to check against. Must be at info level 3.
 * 
 * @return (s32 bool) 1 if the point is inside the polygon, 0 otherwise.
 */
s32 IsInsidePolygon(Vec3f vec, Poly* poly) {
    f32 baryU;
    f32 baryV;
    Poly_AssertInfoLevel(poly, 3, "IsInsidePolygon");
    baryU = (poly->invMtxVSkew * vec.y) + (poly->invMtxU * vec.x);
    baryV = (poly->invMtxV * vec.y) + (poly->invMtxUSkew * vec.x);
    if (baryU < -0.0001) {
        return 0;
    }
    if (baryV < -0.0001) {
        return 0;
    }
    if (1.0001 < (baryU + baryV)) {
        return 0;
    }
   return 1;
}

/**
 * @brief Uses the dot product of the point and the polygon's normal vector to determine if the point is on the polygon.
 * 
 * @param vec:  the point to check
 * @param poly: the polygon to check
 * 
 * @return (s32 bool) 1 if the point is on the polygon, 0 otherwise
 */
s32 IsOnPolygon(Vec3f vec, Poly* poly) {
    f32 dotProduct;
    
    Poly_AssertInfoLevel(poly, 2, "IsOnPolygon");
    vec.x -= poly->origin.x;
    vec.y -= poly->origin.y;
    vec.z -= poly->origin.z;
    
    dotProduct = vec.z * poly->orthBasis.normal.z + (vec.x * poly->orthBasis.normal.x + vec.y * poly->orthBasis.normal.y);

    if (dotProduct < -1.0) {
        return 0;
    }
    if (dotProduct > 1.0) {
        return 0;
    }
    return 1;
}
