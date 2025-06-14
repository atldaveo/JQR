/**
 * @file stack.c
 * @author David Chung (david.t.chung2.mil@army.mil)
 * @brief Function definitions for a simple stack 
 * @version 2 (10APR25)
 * @date 10DEC24
 *  
*/

#include <stdio.h>
#include <stdbool.h>
#include "../include/stack.h"

#define MAXSIZE 10     
#define EMPTY   (-1)
#define INDEXER (1)         
#define PASS    0  

Stack*
create_stack(void)
{
    Stack* new_stack = (Stack*)malloc(sizeof(Stack));   // malloc returns a pointer to STACK
    if (NULL == new_stack)
    {
        printf("Creation failed\n");
        return NULL;
    }

    new_stack->capacity = MAXSIZE;
    new_stack->top = EMPTY;              // top of stack is index -1 to indicate empty
    new_stack->pp_array = (void**)malloc(new_stack -> capacity * sizeof(void*)); // allocate enough memory to hold max number of datum (10)

    if (NULL == new_stack->pp_array)
    {
        printf("Memory allocation failed\n");
        return NULL; 
    }

    return new_stack;
}

bool
is_full(Stack* stack)
{
    if (stack->top == stack->capacity - INDEXER)
    {
        return true;
    }
    return false;
}

void
stack_push(Stack* stack, void* p_data)
{
    if (true == is_full(stack))
    {
        // Double the stack capacity if there is an overflow
        stack->capacity *= 2;
        stack->pp_array = (void**)realloc(stack->pp_array, stack->capacity * sizeof(void*));
        if (NULL == stack -> pp_array)
        {
            printf("Reallocation failed\n");
            exit(EXIT_FAILURE);
        }
    }
    stack ->pp_array[++stack -> top] = p_data; 
}

void
stack_print(Stack* stack, void (*print_func)(void*))
{
    printf("[");
    for (int index = 0; index <= stack->top; index++) 
    {
        print_func(stack->pp_array[index]);
        if (index < stack->top)
        {
            printf(", ");
        }
    }
    printf("]\n");
}

void print_int(void* p_data) 
{
    printf("%d ", *(int*)p_data);
}

void stack_free(Stack* stack)
{
    free(stack->pp_array);
    free(stack);
}

bool is_empty(Stack* stack)
{
    if (EMPTY == stack->top)
    {
        return true;
    }
    return false;
}

void* stack_peek(Stack* stack)
{
    if (true == is_empty(stack))
    {
        printf("There is nothing in the stack!");
        return NULL;
    }
    return stack -> pp_array[stack -> top];
}

void* stack_pop(Stack* stack)
{
    if (true == is_empty(stack))
    {
        printf("Underflow! There is nothing in the stack!");
        return PASS;
    }
    return stack->pp_array[stack->top--]; 
}

void destroy_stack(Stack* stack)
{
    if (NULL != stack)
    {
        free(stack->pp_array);
        free(stack);
    }
}

void stack_iterate(Stack* stack, void (*process)(void*)) 
{
    if (NULL == stack || NULL == process) 
    {
        fprintf(stderr, "Stack or process function is NULL.\n");
        return;
    }
}


/************************ END OF FILE ***********************/