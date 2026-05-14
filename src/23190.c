#include "common.h"

/**
 * @brief Compares two given rectangles to determine if they intersect.
 *
 * @param[in,out] rectA: first rectangle
 * @param[in,out] rectB: second rectangle
 *
 * @return (s32) 1 if the two rectangles intersect, 0 otherwise
 */
s32 IfRectsIntersect(Rect3D* rectA, Rect3D* rectB) {
    if ((f64) rectB->max.x < (f64) rectA->min.x) {
        return 0;
    }
    if ((f64) rectA->max.x < (f64) rectB->min.x) {
        return 0;
    }
    if ((f64) rectB->max.y < (f64) rectA->min.y) {
        return 0;
    }
    if ((f64) rectA->max.y < (f64) rectB->min.y) {
        return 0;
    }
    if ((f64) rectB->max.z < (f64) rectA->min.z) {
        return 0;
    }
    if ((f64) rectA->max.z < (f64) rectB->min.z) {
        return 0;
    }
    return 1;
}

void func_80047E8C(Rect3D* arg0, f32 arg1) {
    arg0->min.x -= arg1;
    arg0->max.x += arg1;
    arg0->min.y -= arg1;
    arg0->max.y += arg1;
    arg0->min.z -= arg1;
    arg0->max.z += arg1;
}

/**
 * @brief Create a bounding box from two given vectors.
 *
 * @param vecA: First vector
 * @param vecB: Second vector
 * @param rect: Pointer to rectangle to store bounding box in
 */
void CalculateBoundingRectFromVectors(Vec3f vecA, Vec3f vecB, Rect3D* rect) {
    if (vecA.x < vecB.x) {
        rect->min.x = vecA.x;
        rect->max.x = vecB.x;
    } else {
        rect->min.x = vecB.x;
        rect->max.x = vecA.x;
    }
    if (vecA.y < vecB.y) {
        rect->min.y = vecA.y;
        rect->max.y = vecB.y;
    } else {
        rect->min.y = vecB.y;
        rect->max.y = vecA.y;
    }
    if (vecA.z < vecB.z) {
        rect->min.z = vecA.z;
        rect->max.z = vecB.z;
        return;
    }
    rect->min.z = vecB.z;
    rect->max.z = vecA.z;
}

#pragma GLOBAL_ASM("asm/nonmatchings/23190/func_80047F7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/23190/func_800481E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/23190/func_8004846C.s")
