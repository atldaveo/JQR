#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"

void initStack(Stack* s)
{
    s->top = -1;  // Empty stack
}

int isFull(Stack* s)
{
    return s->top == STACK_MAX - 1;
}

int isEmpty(Stack* s)
{
    return s->top == -1;        // Check if top of the stack is -1 
}

void push(Stack* s, void* value, size_t size)
{
    if (1 == isFull(s))
    {
        printf("Stack Overflow! Cannot push the element.\n");
    } 
    else
    {
        // Allocate memory for the new value and copy the data
        s->arr[++(s->top)] = malloc(size);
        if (s->arr[s->top] == (void*)NULL)
        {
            printf("Memory allocation failed!\n");
            return;
        }
        // Copy the value into the allocated memory
        memcpy(s->arr[s->top], (void*)value, size);
        printf("Pushed element onto the stack.\n");
    }
}

void* pop(Stack* s)
{
    if (1 == isEmpty(s))
    {
        printf("Stack Underflow! No element to pop.\n");
        return NULL;  // Return NULL to indicate underflow
    } 
    else
    {
        void* value = (void*)s->arr[s->top];
        s->arr[s->top--] = (void*)NULL;
        return value;
    }
}

void* peek(Stack* s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty!\n");
        return NULL;  // Return NULL to indicate empty stack
    } 
    else
    {
        return (void*)s->arr[s->top];
    }
}

void display(Stack* s, void (*print)(void*))
{
    if (isEmpty(s))
    {
        printf("Stack is empty!\n");
    } 
    else
    {
        printf("Stack elements: ");
        for (int i = 0; i <= s->top; i++)
        {
            print((void*)s->arr[i]);
        }
        printf("\n");
    }
}

void printInt(void* value)
{
    printf("%d ", *((int*)value));
}