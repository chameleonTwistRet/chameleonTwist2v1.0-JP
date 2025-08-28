#include "common.h"

// double → long long
long long __d_to_ll(double d) {
    return (long long)d;
}

// float → long long
long long __f_to_ll(float f) {
    return (long long)f;
}

unsigned long long __d_to_ull(double d) {
    return (unsigned long long)d;
}

// float → unsigned long long
unsigned long long __f_to_ull(float f) {
    return (unsigned long long)f;
}

// long long → double
double __ll_to_d(long long x) {
    return (double)x;
}

// long long → float
float __ll_to_f(long long x) {
    return (float)x;
}

// unsigned long long → double
double __ull_to_d(unsigned long long x) {
    return (double)x;
}

// unsigned long long → float
float __ull_to_f(unsigned long long x) {
    return (float)x;
}

