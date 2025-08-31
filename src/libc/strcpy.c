#include "common.h"

char* strcpy(char* dest, const unsigned char* src) {
    char* d = dest;
    
    while (*src != '\0') {
        *d++ = *src++;
    }
    
    *d = '\0';  // Add null terminator
    
    return dest;
}
