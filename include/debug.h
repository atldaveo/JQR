/**
 * @file debug.h
 * @author David Chung (david.chung1719@outlook.com)
 * @brief Outlines capabilities when running the main code in DEBUG mode.
 * @version 0.1
 * @date 02Dec24
 * 
 * @copyright Copyright (c) 2024
 * 
 */

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
