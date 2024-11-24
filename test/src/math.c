#include "math.h"
#include "debug.h"

int add(int x, int y)
{
    DEBUG_PRINT("%d + %d", x, y);
    return x + y;
}