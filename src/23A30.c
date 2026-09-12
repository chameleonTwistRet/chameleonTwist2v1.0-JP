#include "common.h"

f32 AngleFromArcSin(f32 x);
f32 sin_deg(f32);
f32 cos_deg(f32);
void DummiedPrintf3(char* fmt, ...);

/**
 * @brief Calculates the result of a given rotation matrix multiplied by a given vector.
 *
 * @param[in,out]   outVec:                 pointer to the output vector
 * @param           inpVec:                 the input vector
 * @param           theta:                  the angle of rotation
 * @param           rotateAroundAxesIndex:  the axis to rotate around / the rotation matrix to use
 *
 * @return (Vec3f) the vector after the rotation
*/
Vec3f* RotateVector3D(Vec3f* outVec, Vec3f inpVec, f32 theta, s32 rotateAroundAxesIndex) {
    #define NO_ROTATION 0
    #define X_ROTATION 1
    #define Y_ROTATION 2
    #define Z_ROTATION 3
    Vec3f temp_vec;
    f32 sin;
    f32 cos;

    sin = sin_deg(theta);
    cos = cos_deg(theta);
    switch (rotateAroundAxesIndex) {
    case NO_ROTATION:
        temp_vec = inpVec;
        break;
    case X_ROTATION:
        temp_vec.x = inpVec.x;
        temp_vec.y = (cos * inpVec.y) - (sin * inpVec.z);
        temp_vec.z = (sin * inpVec.y) + (cos * inpVec.z);
        break;
    case Y_ROTATION:
        temp_vec.y = inpVec.y;
        temp_vec.x = (sin * inpVec.z) + (cos * inpVec.x);
        temp_vec.z = (cos * inpVec.z) - (sin * inpVec.x);
        break;
    case Z_ROTATION:
        temp_vec.z = inpVec.z;
        temp_vec.x = (cos * inpVec.x) - (sin * inpVec.y);
        temp_vec.y = (sin * inpVec.x) + (cos * inpVec.y);
        break;
    }

    *outVec = temp_vec;
    return outVec;
}

/**
 * @brief Return if a point is within a certain radius of another point.
 *
 * @param   vec1:           first vector
 * @param   vec2:           second vector
 * @param   approxRadius:   radius to check
 *
 * @return (s32 bool) 1 if within radius, 0 if not
 */
s32 IsNearPoint(Vec3f vec1, Vec3f vec2, f32 approxRadius) {
    f32 dx;
    f32 dz;
    f32 dy;
    s32 ret;

    // Find a vector to represent the distance between the two points
    dx = vec1.x - vec2.x;
    dy = vec1.y - vec2.y;
    dz = vec1.z - vec2.z;

    if (NORM_3(dx, dy, dz) < approxRadius) {     // Check if said vector is within the given radius from the origin
        ret = 1;
    } else {
        ret = 0;
    }
    return ret;
}

/**
 * @brief compares two Vec3f structs. [Both are neccessary for checksum]
 *
 * @param vec1: first vector
 * @param vec2: second vector
 *
 * @return (s32 bool) 1 if equal, 0 if not
 */
s32 Vec3f_Equals(Vec3f vec1, Vec3f vec2) {
    return ((vec1.x == vec2.x) && (vec1.y == vec2.y) && (vec1.z == vec2.z)) ? 1 : 0;
}

/**
 * @brief compares two Vec3f structs. [Both are neccessary for checksum]
 *
 * @param vec1: first vector
 * @param vec2: second vector
 *
 * @return (s32 bool) 1 if equal, 0 if not
 */
s32 Vec3f_EqualsCopy(Vec3f vec1, Vec3f vec2) {
    return ((vec1.x == vec2.x) && (vec1.y == vec2.y) && (vec1.z == vec2.z)) ? 1 : 0;
}

/**
 * @brief Sets the input vector to have given values.
 *
 * @param vec: pointer for vector to set
 * @param x: x value to set
 * @param y: y value to set
 * @param z: z value to set
 */
void Vec3f_Set(Vec3f* vec, f32 x, f32 y, f32 z) {
    vec->x = x;
    vec->y = y;
    vec->z = z;
}

/**
 * @brief Sets the input vector to the zero vector.
 *
 * @param vec: pointer for vector to zero
 */
void Vec3f_Zero(Vec3f* vec) {
    vec->x = 0.0f;
    vec->y = 0.0f;
    vec->z = 0.0f;
}

/**
 * @brief Normalizes the input vector then returns its norm.
 *
 * @param[in,out] vec: pointer to the vector to be normalized
 *
 * @return (f32) the norm of the input vector
 */
f32 Vec3f_Normalize(Vec3f* vec) {
    f32 norm = NORM_3(vec->x,vec->y,vec->z);
    if (norm == 0.0f) {
        Vec3f_Zero(vec);                    // if the norm is 0, then we cannot divide by it
    } else {
        vec->x = (f32) (vec->x / norm);
        vec->y = (f32) (vec->y / norm);
        vec->z = (f32) (vec->z / norm);
    }
    return norm;
}

/**
 * @brief Linearly interpolates between two input vectors.
 *
 * @param[in,out]  outVec:     pointer to the output vector
 * @param          vecOne:     first input vector
 * @param          vecTwo:     second input vector
 * @param          scalar:     scalar value to interpolate between the two vectors
 *
 * @return (Vec3f) pointer to the output vector
 */
Vec3f* Vec3f_Lerp(Vec3f* outVec, Vec3f vecOne, Vec3f vecTwo, f32 scalar) {
    Vec3f temp_vec;

    if ((scalar < 0.0f) || (scalar > 1.0f)) {
        DummiedPrintf3("?? ratio = %f\n", outVec, scalar);
    }

    temp_vec.x = ((1.0f - scalar) * vecOne.x) + (vecTwo.x * scalar);
    temp_vec.y = ((1.0f - scalar) * vecOne.y) + (vecTwo.y * scalar);
    temp_vec.z = ((1.0f - scalar) * vecOne.z) + (vecTwo.z * scalar);
    *outVec = temp_vec;
    return outVec;
}

/**
 * @brief Converts a cartesian vector to spherical coordinates.
 *
 * @param          inputVec:   input vector
 * @param[in,out]  radius:     pointer to the radius of the spherical coordinate
 * @param[in,out]  theta:      pointer to the theta of the spherical coordinate
 * @param[in,out]  phi:        pointer to the phi of the spherical coordinate
 */
void CartesianToSpherical(Vec3f inputVec, f32* radius, f32* theta, f32* phi) {
    f32 sqrtResult;

    *radius = NORM_3(inputVec.x,inputVec.y,inputVec.z);

    if (*radius == 0.0) {
        *theta = 0.0f;
        *phi = 0.0f;
        return;
    } else {
        *theta = AngleFromArcSin(inputVec.y / *radius);
        sqrtResult = NORM_2(inputVec.z,inputVec.x);

        if (sqrtResult == 0.0) {
            *phi = 0.0f;
            return;
        }

        *phi = AngleFromArcSin(inputVec.z / sqrtResult);

        if (inputVec.x < 0.0) {
            *phi = *phi * -1.0;
        }
    }
}

Vec3f* func_80048BBC(Vec3f* arg0, f32 arg1, f32 arg2, f32 arg3) {
    Vec3f sp1C;
    f32 sp18;

    sp18 = sin_deg(arg2) * arg1;
    sp1C.x = sin_deg(arg3) * sp18;
    sp1C.y = cos_deg(arg2) * arg1;
    sp1C.z = cos_deg(arg3) * sp18;
    *arg0 = sp1C;
    return arg0;
}

void func_80048C54(Vec3f arg0) {
    DummiedPrintf3("%7.1f %7.1f %7.1f ", arg0.x, arg0.y, arg0.z);
}

