#include "math.h"
#include "debug.h"

int add(int x, int y)
{
    DEBUG_PRINT("%d + %d", x, y);
    return x + y;
}

int subtract(int x, int y)
{
    return x - y;
}

int multiply(int x, int y)
{
    return x * y;
}

int divide(int x, int y)
{
    return x / y;
}

/*
int add(int32_t x, int32_t y, int32_t *res) {
    // check if overflow / underflow, if so, return -1
    // otherwise, put x + y in *res
    // return 0 (success)
}
*/

/*
int32_t res = 0; // initialize
if (add(x, y, &res) == -1) {
    // error occurred
}
else {
    printf("res;ult: %d", res)
}
*/