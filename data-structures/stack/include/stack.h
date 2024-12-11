#ifndef STACK_H
#define STACK_H

#define STACK_MAX 5

typedef struct 
{
    void* arr[STACK_MAX];
    int top;
} Stack;

/** @brief Initialize an empty stack
 * 
 * @param s Stack Pointer
 */
void initStack(Stack* s);

/** @brief Check if stack is full 
 * 
 * @param s Stack Pointer
 * @return int indicates if stack is full or not
 */
int isFull(Stack* s); 

/** @brief Check if the stack is empty 
 * 
 * @param s Stack pointer
 * @return int If top of the stack == -1, return 1 (isEmpty). 
 * Else, return 0 (false).
 */
int isEmpty(Stack* s);

/** @brief Push data into stack 
 * 
 * @param s  pointer to stack data is intended to be pushed onto
 * @param value data being pushed
 * @param size memory intended to be pushed
 */
void push(Stack* s, void* value, size_t size);

/** @brief Pop data off stack
 * 
 * @param s stack pointer
 * @return void* no return value
 */
void* pop(Stack* s);

/** @brief View data at the top of the stack 
 * 
 * @param s stack pointer
 * @return void* 
 */
void* peek(Stack* s);

/** @brief Display the stack in its entirety
 * 
 * @param s stack pointer
 * @param print print function pointer dependent on data type
 */
void display(Stack* s, void (*print)(void*)); 

/**@brief Print the specific data type of data held in stack 
 * 
 */
void printInt(void* value); 

#endif

