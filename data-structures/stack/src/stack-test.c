#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"

int main()
{
    Stack s;
    initStack(&s);

    // Data to be pushed
    int a = 10;
    int b = 20; 
    int c = 30;

    // Push integers onto the stack
    push(&s, &a, sizeof(a));
    push(&s, &b, sizeof(b));
    push(&s, &c, sizeof(c));
    display(&s, printInt);

    // Peek at the top element
    int* topElement = (int*)peek(&s);
    if (NULL != topElement) 
    {
        printf("Top element: %d\n", *topElement);
    }

    // Pop an element
    int* poppedElement = (int*)pop(&s);
    if (0 != poppedElement) 
    {
        printf("Popped element: %d\n", *poppedElement);
        free(poppedElement);  
    }
    display(&s, printInt);

    // Clean up remaining elements
    while (0 == isEmpty(&s)) 
    {
        int* element = (int*)pop(&s);
        if (NULL != element) 
        {
            free(element);  // Free memory
        }
    }

    return 0;
}