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

Operation checkOperator(const char *operator)
{
    if  (0 != operator && 1 == strlen(operator))
    {
        if (0 == strncmp(operator, "+", 1))
        { 
            return ADD;
        }
        else if (0 == strncmp(operator, "-", 1)) 
        {
            return SUBTRACT;
        }
        else if (0 == strncmp(operator, "x", 1) || 0 == strncmp(operator, "*", 1))
        { 
            return MULTIPLY;
        }
        else if (0 == strncmp(operator, "/", 1))
        {
            return DIVIDE;
        }
        else 
            return INVALID;
    }
    else
    {
        fprintf(stderr, "Invalid operator\n");
        return INVALID;
    }
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

    bool hasNum1 = false;                       /**< Validation gates to ensure good arguments */
    bool hasNum2 = false;
    bool opCheck = false;        
    bool argCheck = false;
    int32_t num1 = 0;                           /**< Variable that will hold an operand with MAX 32 bits */
    int32_t num2 = 0;                           /**< Variable that will hold an operand with MAX 32 bits */
    int32_t result = 0;                         /**< Variable that will hold the resulting calculated number */
    char *numEnd1 = NULL;                       /**< Pointer to the end of num1 */
    char *numEnd2 = NULL;                       /**< Pointer to the end of num2 */                               
    
    Operation operation;                        
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
            fprintf(stderr, "Likely encountered wildcard expansion. Precede CLI command with commmand 'set -f'\n");
        } 
        printf("See below for more troubleshooting\n");
        printHelp(argv[0]);
        exit(EXIT_FAILURE);
    }
    else
        argCheck = true;
    
/**
 * @brief Error-checking for valid first operand <num1> 
 * 
 */

    num1 = strtol(argv[1], &numEnd1, 10);
    if (0 != errno || '\0' != *numEnd1)     /**< Check for over/underflow and validity of string */
    {
        fprintf(stderr, "'%s' is an invalid operand\n", argv[1]);
        printf("Make sure you input the following:\n");
        printHelp(argv[0]);
        exit(EXIT_FAILURE);
    }
    else
        hasNum1 = true;

/**
 * @brief Error-checking for valid first operand <num1> 
 * 
 */

    num2 = strtol(argv[3], &numEnd2, 10);
    if (0 != errno || '\0' != *numEnd2)     /**< Check for over/underflow and validity of string */
    {
        fprintf(stderr, "'%s' is an invalid operand\n", argv[3]);
        printf("Make sure you input the following:\n");
        printHelp(argv[0]);
        exit(EXIT_FAILURE);
    }
    else
        hasNum2 = true;

/**
 * @brief Error-checking for valid arithmetic operator 
 * 
 */

    operation = checkOperator(argv[2]);

    if (operation == INVALID)
    {
        fprintf(stderr, "'%s' is an invalid operator\n", argv[2]);
        printf("Make sure you input the following:\n");
        printHelp(argv[0]);
        exit(EXIT_FAILURE);
    }
    else
        opCheck = true;

/**
 * @brief Based on passing error-checks, execute the proper arithmetic
 * operation and print the results in the form of <num1> <operator> <num2> = <result> 
 * to the terminal.
 * 
 * All the cases for the switch (operation) refer to the enumeration defined at the beginning
 * of the code. 
 */

    if (argCheck && hasNum1 && hasNum2 && opCheck)
    {    
        switch (operation) 
        {
            case ADD:
                result = add(num1, num2);
                printf("%d + %d = %d\n", num1, num2, result);
                break;
            case SUBTRACT:
                result = subtract(num1, num2);
                printf("%d - %d = %d\n", num1, num2, result);
                break;
            case MULTIPLY:
                result = multiply(num1, num2);
                printf("%d * %d = %d\n", num1, num2, result);
                break;
            case DIVIDE:
                if (num2 == 0) 
                {
                    fprintf(stderr, "Error: Division by zero is not allowed.\n");
                    exit(EXIT_FAILURE);
                }
                result = divide(num1, num2);
                printf("%d / %d = %d\n", num1, num2, result);
                break;
            default:
                fprintf(stderr, "Invalid operation.\n");
                exit(EXIT_FAILURE);
        }
    }
    return 0;
}
