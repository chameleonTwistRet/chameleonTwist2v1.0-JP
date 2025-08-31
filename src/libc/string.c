#include "common.h"

void* memcpy(void* s1, const void* s2, u32 n) {
    char* su1 = (char*)s1;
    const char* su2 = (const char*)s2;
    while (n > 0) {
        *su1 = *su2;
        su1++;
        su2++;
        n--;
    }
    return (void*)s1;
}

u32 strlen(const char* s) {
    const char* sc = s;
    while (*sc) {
        sc++;
    }
    return sc - s;
}

char* strchr(const char* s, int c) {
    const char ch = c;
    while (*s != ch) {
        if (*s == 0) {
            return 0;
        }
        s++;
    }
    return (char*)s;
}
