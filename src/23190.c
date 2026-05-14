#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/23190/func_80047D90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/23190/func_80047E8C.s")

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
