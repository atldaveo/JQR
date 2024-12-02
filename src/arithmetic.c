#include <stdint.h>
#include "arithmetic.h"
#include "debug.h"

int add(int32_t x, int32_t y)
{
    DEBUG_PRINT("%d + %d", x, y);
    return x + y;
}

int subtract(int32_t x, int32_t y)
{
    return x - y;
}

int multiply(int32_t x, int32_t y)
{
    return x * y;
}

int divide(int32_t x, int32_t y)
{
    if (0 == y)                 /** Prevent division by zero */
        {
            return -1;
        }
    else
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