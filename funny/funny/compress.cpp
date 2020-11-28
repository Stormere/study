//
//  compression.c
//  funny
//
//  Created by steveluccy on 11/28/20.
//


#include "compress.h"

char *compress(const char *src, char *dst) {
    char *result = dst;
    while (*src != '\0') {
        const char c = *src;
        if (c != *(src+1)) {
            *result++=*src++;
        } else {
            *result++=*src;
            while (c == *++src);
        }

    }
    return dst;
}
