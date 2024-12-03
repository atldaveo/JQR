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

int32_t add(int32_t x, int32_t y, int32_t *res)
{
    // Check for overflow
    if ((0 < x) && (0 < y) && ((INT32_MAX - y) < x)) 
    {
        fprintf(stderr, "\nOverflow: Result is too large\n");
        return -1;
    }
    // Check for underflow
    else if ((0 > x) && (0 > y) && ((INT32_MIN - y) > x)) 
    {
        fprintf(stderr, "\nUnderflow: Result is too small\n");
        return -1;
    }
    // Null pointer check
    else if (NULL == res) 
    {
        fprintf(stderr, "\nError: Null pointer.\n");
        return -1;  
    }
    else
    {
        *res = x + y;
        return 0;
    }
}

int32_t subtract(int32_t x, int32_t y, int32_t *res)
{
    // Check for overflow
    if ((0 < y) && ((INT32_MIN + y) > x))   
    {
        fprintf(stderr, "\nOverflow: Result is too large\n");
        return -1;
    }
    // Check for underflow
    else if ((y < 0) && (x > INT32_MAX + y)) 
    { 
        fprintf(stderr, "\nUnderflow: Result is too small\n");
        return -1;
    }
    // Null pointer check
    else if (NULL == res) 
    {
        fprintf(stderr, "\nError: Null pointer.\n");
        return -1;  
    }
    else
    {
        *res = x - y;
        return 0;
    }
}

int32_t multiply(int32_t x, int32_t y, int32_t *res)
{
    // Overflow check with two positive arguments  
    if ((0 < x) && (0 < y) && ((INT32_MAX / y) < x)) 
    {  
        fprintf(stderr, "\nOverflow: Result is too large\n");
        return -1;
    }
    // Overflow check with two negative arguments
    else if ((0 > x) && (0 > y) && ((INT32_MAX / y) > x)) 
    {
        fprintf(stderr, "\nOverflow: Result is too large\n");
        return -1;
    }
    // Underflow check 
    else if (((0 < x) && (0 > y) && ((INT32_MIN / x) > y)) ||         /**> Positive x, Negative y */
            ((0 > x) && (0 < y) && ((INT32_MIN / y) > x)))            /**> Negative x, Positive y */
    {     
        fprintf(stderr, "\nUnderflow: Result is too small\n");
        return -1;
    }
    // Null pointer check
    else if (NULL == res) 
    {
        fprintf(stderr, "\nError: Null pointer.\n");
        return -1;  
    }
    else
    {
        *res = x * y;
        return 0;
    }
}

int32_t divide(int32_t x, int32_t y, int32_t *res)
{
    // Prevent division by 0
    if (0 == y)                 
    {
        fprintf(stderr, "\nError: Can't divide by 0!\n");
        return -1;
    }
    // Null pointer check
    else if (NULL == res) 
    {
        fprintf(stderr, "\nError: Null pointer.\n");
        return -1;  
    }
    // Overflow check
    else if ((INT32_MIN == x) && (-1 == y)) 
    {  
        fprintf(stderr, "\nOverflow: Result is too large\n");
        return -1;
    }
    else
    {
        *res = x / y;       /**< Allows for the result to be stored in memory location &res */
        return 0;          
    }
}
