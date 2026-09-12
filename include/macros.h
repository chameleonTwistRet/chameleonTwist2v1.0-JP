#ifndef MACROS_H
#define MACROS_H

// GENERAL MATHS //
#define PI_SHORT 3.14156 //for unknown reasons, less digits are randomly required
#define PI 3.141592653589793
#define TAU 6.283185307179586
#define PI_HALF 1.57078
#define SQ(x) ((x)*(x))
#define SUM_OF_SQUARES(x,y) (SQ(x) + SQ(y))
#define NORM_2(x,y) (sqrtf(SQ(x) + SQ(y)))
#define NORM_3(x,y,z) (sqrtf(SQ(x) + SQ(y) + SQ(z)))
#define sqrtf __sqrtf
#define sinf __sinf
#define cosf __cosf
#define DEGREES_TO_RADIANS_2PI(x) ((x) * 2 * PI / 360.0)
#define DEGREES_TO_RADIANS_PI(x) (x * PI / 180.0)
#define ARRAY_COUNT(arr) (s32)(sizeof(arr) / sizeof(arr[0]))
#define ROUND(d)	(int)(((d) >= 0.0) ? ((d) + 0.5) : ((d) - 0.5))
#define	ABS(d)		((d) > 0) ? (d) : -(d)
#define	ABS2(d)		(((d) < 0) ? -(d) : (d))
#define _ALIGN(val, alignment) ((((val) + ((alignment) - 1)) / (alignment)) * (alignment))
#define ALIGN_128(val) ((val + 0x7F) & ~0x7F)
#define SQROOT_2_DIV_2 0.70710678f

#endif //MACROS_H
