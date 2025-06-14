/**
 * @file stack.h
 * @author David Chung (david.t.chung2.mil@army.mil)
 * @brief Prototypes and describes the functions in associated helper file stack.c 
 * @version 2 (13FEB25)
 * @date 10DEC24
 *  
*/

#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stddef.h>

#define STACKMAX    10

typedef struct Stack
{
    int top;
    int capacity;
    void** pp_array;       // Array of void pointers to store any data type
} Stack;

/** @brief Create a Stack object. Accepts any data type. 
 * 
 * @return Stack 
 */
Stack*
create_stack(void);

/** @brief See if the stack is full
 * 
 * @return Bool 
 */
bool
is_full(Stack* stack);

/** @brief Push data onto stack
 * (must handle overflow)
 * @param stack 
 * @param data 
 */
void
stack_push(Stack* stack, void* data);

/** @brief Function to print the stack data
 * 
 * @param stack 
 * @param print_func Whatever print function suits the need
 */
void
stack_print(Stack* stack, void (*print_func)(void*));

/** @brief Custom int print function 
 * 
 * @param data 
 */
void
print_int(void* data);

/** @brief Frees the data taken up by the stack
 * 
 * @param stack 
 */
void
stack_free(Stack* stack);

/** @brief See if the stack is empty
 * 
 * @return Bool 
 */
bool
is_empty(Stack* stack);

/** @brief View what is currently at the top of the stack
 * 
 * @param stack 
 * @return void* 
 */
void*
stack_peek(Stack* stack);

/** @brief Pops data off of stack. Error if underflow
 * 
 * @param stack 
 * @return void* 
 */
void*
stack_pop(Stack* stack);

/** @brief Deletes the stack and frees up the dynamically allocated memory 
 * 
 * @param stack 
 */
void
destroy_stack(Stack* stack);

#endif

/************************ END OF FILE ***********************/