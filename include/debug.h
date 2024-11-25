#ifndef DEBUG_H
#define DEBUG_H

#include <stdio.h>

// Define DEBUG_PRINT macro
#ifdef DEBUG
    #define DEBUG_PRINT(msg, ...) \
        fprintf(stderr, "%s:%d | " msg "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#else
    #define DEBUG_PRINT(msg, ...) // No-op in release mode
#endif

#endif // DEBUG_H
