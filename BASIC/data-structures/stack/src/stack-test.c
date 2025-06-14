/**
 * @file stack-test.data_c
 * @author David Chung (david.chung1719@outlook.com)
 * @brief 
 * @version 1 (10APR25)
 * @date 13Feb25
 * 
 * Tests stack.data_c code for functionality
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/stack.h"

#define PASS 0

// Stack testing 
int
main(void)
{
    // void* data storage testing
     Stack* stack = create_stack();

    // test using int data type 
    int data_a = 10;
    int data_b = 20;
    int data_c = 30;

    // Add to stack
    stack_push(stack, &data_a);
    stack_push(stack, &data_b);
    stack_push(stack, &data_c);
                 
    // What is currently in the stack?
    printf("Stack contents: ");
    stack_print(stack, print_int);

    // What is currently at the p_peek of the stack?
    int* p_peek = (int*)stack_peek(stack);
    printf("Top element: %d\n", *p_peek);

    // What got p_popped?
    int* p_popped = (int*)stack_pop(stack);
    printf("Popped element: %d\n", *p_popped);

    // What's the stack look like after popping?
    printf("Stack after popping: ");
    stack_print(stack, print_int);

    stack_free(stack);
    return PASS;
} 

/************************ END OF FILE ***********************/