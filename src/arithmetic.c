/**
 * @file arithmetic.c
 * @author David Chung (david.chung1719@outlook.com)
 * @brief Defines the different arithmetic operations used in main.c
 * @version 3.0
 * @date 02Dec24
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdint.h>
#include "arithmetic.h"
#include "debug.h"

int32_t add(int32_t x, int32_t y)
{
    // Check for overflow
    if (0 < x && 0 < y && (INT32_MAX - y) < x) 
    {
        fprintf(stderr, "Overflow: Result is too large\n");
        return -1;
    }
    // Check for underflow
    else if (0 > x && 0 > y && (INT32_MIN - y) > x) 
    {
        fprintf(stderr, "Underflow: Result is too low\n");
        return -1;
    }
    else
        return x + y;
}

int32_t subtract(int32_t x, int32_t y)
{
    // Check for overflow
    if (0 < y && (INT32_MIN + y) > x)   
    {
        fprintf(stderr, "Overflow: Result is too large\n");
        return -1;
    }
    // Check for underflow
    else if (y < 0 && x > INT32_MAX + y) 
    { 
        fprintf(stderr, "Underflow: Result is too low\n");
        return -1;
    }
    else
        return x - y;
}

int32_t multiply(int32_t x, int32_t y)
{
    // Overflow check with two positive arguments  
    if (0 < x && 0 < y && (INT32_MAX / y) < x) 
    {  
        fprintf(stderr, "Overflow: Result is too large\n");
        return -1;
    }
    // Overflow check with two negative arguments
    else if (0 > x && 0 > y && (INT32_MAX / y) > x) 
    {
        fprintf(stderr, "Overflow: Result will be too large\n");
        return -1;
    }
    // Underflow check 
    else if ((0 < x && 0 > y && (INT32_MIN / x) > y) ||         /**> Positive x, Negative y */
            (0 > x && 0 < y && (INT32_MIN / y) > x))            /**> Negative x, Positive y */
    {     
        fprintf(stderr, "Underflow: Result will be too low\n");
        return -1;
    }
    else
        return x * y;
}

int32_t divide(int32_t x, int32_t y)
{
    // Prevent division by 0
    if (0 == y)                 
    {
        fprintf(stderr, "Can't divide by 0!");
        return -1;
    }
    // Overflow check
    else if (INT32_MIN == x && -1 == y) 
    {  
        fprintf(stderr, "Overflow: Result is too large\n");
        return -1;
    }
    else
        return x / y;
}
