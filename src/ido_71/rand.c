#include "common.h"

extern s16 D_800FF20E;
extern s32 D_80165200; //bss


extern f32 D_800F5910; //65535.0f
extern f32 D_800F5914; //65535.0f
extern f32 D_800F5918; //65535.0f

/**
 * @brief Returns a random integer between min and max, inclusive.
 * Uses a fixed seed if UseFixedRNGSeed is TRUE or guRandom() if FALSE.
 * @param min: Minimum value to return
 * @param max: Maximum value to return
 * 
 * @return: A random integer between min and max, inclusive
 */
s32 Random(s32 min, s32 max) {
    s32 temp_v0;
    f32 randFloat;

    if (D_800FF20E != 0) {
        temp_v0 = D_80165200 * 0x14D;
        if (temp_v0 < 0) {
            D_80165200 = -temp_v0;
        } else {
            D_80165200 = temp_v0;
        }
        randFloat = ((D_80165200)) % 65535 / 65535.0f;
        return (max - min + 1) * randFloat + min;
    }
    randFloat = guRandom() % 65535;
    return (max - min + 1) * (randFloat / 65535.0f) + min;
}


/**
 * @brief Returns a random float between 0 and 1 by calling Random().
 * @return A random float between 0 and 1 
 */
f32 RandomF(void) {
    return Random(0, 0xFFFF) / 65535.0f;
}
