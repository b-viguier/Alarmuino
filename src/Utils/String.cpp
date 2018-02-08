#include "String.h"

void Utils::String::copy(char *dst, const char *src) {
    for (; (*dst++ = *src++) != 0;);
}

unsigned int Utils::String::length(const char *src) {
    unsigned int len = 0;
    for (; *src++; ++len);
    return len;
}