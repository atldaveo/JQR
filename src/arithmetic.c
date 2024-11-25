/**
 * @file arithmetic.c
 * @author David Chung
 * @brief Function prototyping of all arithmetic functions to be used in the main program.
 * @version 2.1
 * @date 2024-11-25
 * 
 */

#include "arithmetic.h"
#include "debug.h"

/**
 * @brief Addition function.
 * 
 * @param x First number in addition sequence.
 * @param y Second number in addition sequence.
 * @return int Sum of the argument values.
 */

int add(int x, int y)
{
    DEBUG_PRINT("%d + %d", x, y);
    return x + y;
}

/**
 * @brief Subtraction function.
 * 
 * @param x First number in subtraction sequence.
 * @param y Second number in subtraction sequence.
 * @return int Difference of the argument values.
 */

int subtract(int x, int y)
{
    return x - y;
}

/**
 * @brief Multiplication function.
 * 
 * @param x First number in multiplication sequence.
 * @param y Second number in multiplication sequence.
 * @return int Product of the argument values.
 */

int multiply(int x, int y)
{
    return x * y;
}

/**
 * @brief Division function.
 * 
 * @param x First number in division sequence.
 * @param y Second number in division sequence.
 * @return int Quotient of the argument values.
 */

int divide(int x, int y)
{
    return x / y;
}

#if 0
int add(int32_t x, int32_t y, int32_t *res) 
{
    // check if overflow / underflow, if so, return -1
    // otherwise, put x + y in *res
    // return 0 (success)
}

int32_t res = 0; // initialize
if (add(x, y, &res) == -1)
{
    // error occurred
}
else 
{
    printf("res;ult: %d", res)
}
#endif