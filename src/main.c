#include <stdio.h>
#include <stdlib.h>
#include "math.h"
#include "debug.h"

///int add(int x, int y);

int main()
{
    DEBUG_PRINT("Hello from debug mode\n");
    printf("2 + 3 = %d", add(2,3));
    return 0;
}
