#include "common.h"

void* memset(void* s, int c, u32 n) {
    unsigned char* p = s;

    while (n--) {
        *p++ = (unsigned char)c;
    }
    
    return s;
}
