#include "common.h"

// extern s16 D_800FF20E;
// extern s32 D_80165200;

// /**
//  * @brief Returns a random integer between min and max, inclusive.
//  * Uses a fixed seed if UseFixedRNGSeed is TRUE or guRandom() if FALSE.
//  * @param min: Minimum value to return
//  * @param max: Maximum value to return
//  * 
//  * @return: A random integer between min and max, inclusive
//  */
// s32 Random(s32 min, s32 max) {
//     s32 randVal;
//     f32 randFloat;
//     f32 randFloat2;
    
//     if (D_800FF20E != FALSE) {
//         randFloat = ((D_80165200 * 256) + D_80165200) % 65535 / 65535.0f;
//         randFloat2 = max - min + 1;
//         randVal = randFloat2 * randFloat + min;
//     } else {
//         randFloat2 = guRandom() % 65535;
//         randVal = (max - min + 1) * (randFloat2 / 65535.0f) + min;
//     }

//     return randVal;
// }

// /**
//  * @brief Returns a random float between 0 and 1 by calling Random().
//  * @return A random float between 0 and 1 
//  */
// f32 RandomF(void) {
//     return Random(0, 0xFFFF) / 65535.0f;
// }


#pragma GLOBAL_ASM("asm/nonmatchings/17E90/Random.s")

#pragma GLOBAL_ASM("asm/nonmatchings/17E90/RandomF.s")
