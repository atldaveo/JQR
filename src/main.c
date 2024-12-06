/**
 * @file main.c
 * @author David Chung 
 * @brief Main entry point for simple-calc.
 * 
 * This program performs simple arithmetic calculations given user input via CLI.
 * 
 * @version 3.5
 * @date 2024-11-25
 * 
 */

// TODO: Make the program more modular. Maybe use for-loop to iterate
// through CMD Line arguments instead of just checking the first four string
// arguments for valid input.  
                                                                            
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <errno.h>                  /**< Required for errno */
#include <string.h>
#include <stdint.h>                 /**< Required for int32_t usage */
#include "arithmetic.h"
#include "debug.h"
#include "helpers.h"

typedef enum
{
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE,
    RIGHTSHIFT,
    LEFTSHIFT,
    INVALID
} Operation;

/**
 * @brief function uses strncmp (instead of strcmp) in order to more precisely compare the
 * operator as to preserve computing resources / more precisely compare the operator in
 * question.
 * 
 * @param operator user input operator on CMD Line 
 * @return Operation determines which arithmetic operation to execute
 */

Operation check_operator(const char *operator)
{
    if (NULL != operator)
    {
        if (1 == strlen(operator))    
        {
            if (0 == strncmp(operator, "+", 1))
            { 
                return ADD;
            }
            else if (0 == strncmp(operator, "-", 1)) 
            {
                return SUBTRACT;
            }
            else if ((0 == strncmp(operator, "x", 1)) || (0 == strncmp(operator, "*", 1)))
            { 
                return MULTIPLY;
            }
            else if (0 == strncmp(operator, "/", 1))
            {
                return DIVIDE;
            }
        }
        else if (2 == strlen(operator))
        {
            if (0 == strncmp(operator, ">>", 2))
            {
                return RIGHTSHIFT;
            }
            else if (0 == strncmp(operator, "<<", 2))
            {
                return LEFTSHIFT;
            }
        }
    }
    else
    {
        fprintf(stderr, "Invalid operator\n");
        return INVALID;
    }
    fprintf(stderr, "Invalid operator\n");
    return INVALID;
}

/**
 * @brief Main function for the simple-calc program
 * 
 * @param argc Number of CMD Line arguments
 * @param argv Array of CMD Line argument strings 
 * @return int 0 if successful.
 */

int main(int argc, char *argv[])
{
    #define ARGCOUNT 4                          /**< Using constant at beginning of code for modularity */ 

    bool has_num1 = false;                      /**< Validation gates to ensure good arguments */
    bool has_num2 = false;
    bool op_check = false;        
    bool arg_check = false;
    int32_t num1 = 0;                           /**< Variable that will hold an operand with MAX 32 bits */
    int32_t num2 = 0;                           /**< Variable that will hold an operand with MAX 32 bits */
    int32_t result = 0;                         /**< Pointer to the location of arithmetic results */
    int32_t state = 0;                          /**< Variable holding the return value for arithmetic functions */
    uint32_t u_result = 0;
    uint32_t num = 0;
    uint32_t space = 0;
    char *num_end1 = NULL;                      /**< Pointer to the end of num1 */
    char *num_end2 = NULL;                      /**< Pointer to the end of num2 */
    int rc = -1;                                /**< Initiate 'return code' as fail - enable single exit point */                                
    
    Operation operation = {0};                        
    errno = 0;                                  /**< Reset errno */

    /**
    * @brief Error-checking for number of CMD Line arguments
    * Should be 4 <filename> <operand> <operator> <operand>
    */

    if (ARGCOUNT != argc)                                  
    {
        fprintf(stderr, "Argument Error! Reading %d of %d required args\n", argc, ARGCOUNT);
        // Handle wildcard expansion / globbing 
        if (argc > ARGCOUNT)            
        {
            fprintf(stderr, "Likely encountered wildcard expansion. Precede CLI command with 'set -f'\n");
        } 
        printf("See below for more troubleshooting\n");
        print_help(argv[0]);
        goto end;
    }
    else
    {
        arg_check = true;
    }
/**
 * @brief Error-checking for valid first operand <num1> 
 * 
 */

    num1 = strtol(argv[1], &num_end1, 10);
    if (0 != errno || '\0' != *num_end1)     /**< Check for over/underflow and validity of string */
    {
        fprintf(stderr, "'%s' is an invalid operand\n", argv[1]);
        printf("Make sure you input the following:\n");
        print_help(argv[0]);
        goto end;
    }
    else
    {
        has_num1 = true;
    }

/**
 * @brief Error-checking for valid first operand <num1> 
 * 
 */

    num2 = strtol(argv[3], &num_end2, 10);
    if ((0 != errno) || ('\0' != *num_end2))     /**< Check for over/underflow and validity of string */
    {
        fprintf(stderr, "'%s' is an invalid operand\n", argv[3]);
        printf("Make sure you input the following:\n");
        print_help(argv[0]);
        goto end;
    }
    else
    {
        has_num2 = true;
    }

/**
 * @brief Error-checking for valid arithmetic operator 
 * 
 */

    operation = check_operator(argv[2]);

    if (operation == INVALID)
    {
        fprintf(stderr, "'%s' is an invalid operator\n", argv[2]);
        printf("Make sure you input the following:\n");
        print_help(argv[0]);
        goto end;
    }
    else
    {
        op_check = true;
    }

/**
 * @brief Based on passing error-checks, execute the proper arithmetic
 * operation and print the results in the form of <num1> <operator> <num2> = <result> 
 * to the terminal.
 * 
 * All the cases for the switch (operation) refer to the enumeration defined at the beginning
 * of the code. 
 */

    if ((true == arg_check) && (true == has_num1) && (true == has_num2) && (true == op_check))
    {    
        switch (operation) 
        {
            case ADD:
                state = add(num1, num2, &result);
                if (0 == state)
                {
                    printf("%d + %d = %d\n", num1, num2, result);
                    rc = 0;
                    break;
                }
                else
                {
                    fprintf(stderr, "Operation invalid. Review your work\n");
                    break;
                }
            case SUBTRACT:
                state = subtract(num1, num2, &result);
                if (0 == state)
                {
                    printf("%d - %d = %d\n", num1, num2, result);
                    rc = 0;
                    break;
                }
                else
                {
                    fprintf(stderr, "Operation invalid. Review your work\n");
                    break;
                }
            case MULTIPLY:
                state = multiply(num1, num2, &result);
                if (0 == state)
                {
                    printf("%d * %d = %d\n", num1, num2, result);
                    rc = 0;
                    break;
                }
                else
                {
                    fprintf(stderr, "Operation invalid. Review your work\n");
                    break;
                }
            case DIVIDE:
                state = divide(num1, num2, &result);
                if (0 == state)
                {
                    printf("%d / %d = %d\n", num1, num2, result);
                    rc = 0;
                    break;
                }
                else
                {
                    fprintf(stderr, "Operation invalid. Review your work\n"); 
                    break;
                }
            case RIGHTSHIFT:
                if ((0 <= num1) && (0 <= num2))
                {
                    num = (uint32_t)num1;
                    space = (uint32_t)num2;
                    state = shift_right(num, space, &u_result);
                    if (0 == state)
                    {
                        printf("%d >> %d = %d\n", num, space, u_result);
                        rc = 0;
                        break;
                    }
                    else
                    {
                        fprintf(stderr, "Right-Shift Error!\n");
                        break;
                    }
                }
                else
                {
                    fprintf(stderr, "Error: Invalid shift!\n");
                    break;
                }
                
            case LEFTSHIFT:
                if ((0 <= num1) && (0 <= num2))
                {
                    num = (uint32_t)num1;
                    space = (uint32_t)num2;
                    state = shift_left(num, space, &u_result);
                    if (0 == state)
                    {
                        printf("%d >> %d = %d\n", num, space, u_result);
                        rc = 0;
                        break;
                    }
                    else
                    {
                        fprintf(stderr, "Left-Shift error!\n");
                        break;
                    }
                }
                else
                {
                    fprintf(stderr, "Error: Invalid shift!\n");
                    break;
                }
            default:
                fprintf(stderr, "Operation invalid! Check your inputs!\n");
                break;
        }
    }
    else
    {
        goto end;
    }
// Single Exit Point
end:
    return rc;
}
