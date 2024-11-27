/**
 * @file main.c
 * @author David Chung 
 * @brief Main entry point for simple-calc.
 * 
 * This program performs simple arithmetic calculations given user input via CLI.
 * 
 * @version 3.1
 * @date 2024-11-25
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <errno.h>
#include <string.h>
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
    
Operation checkOperator(const char *operator)
{
    if (strncmp(operator, "+") == 0)
    { 
        return ADD;
    }
    else if (strncmp(operator, "-") == 0) 
    {
        return SUBTRACT;
    }
    else if (strncmp(operator, "x") == 0)
    { 
        return MULTIPLY;
    }
    else if (strncmp(operator, "/") == 0)
    {
        return DIVIDE;
    }
    else 
        return INVALID;
}

/**
 * @brief Main function for the simple-calc program
 * 
 * @param argc Number of CMD Line arguments
 * @param argv Array of CMD Line argument strings 
 * @return int 0 if successful.
 */

int main(int argc, char *argv[]) {

    Operation operation;

    //int opt = 0;
    long num1, num2;                /**< Numeric arguments will be converted to a long int. */
    long result;
    //char operation = 0;             /**< Which operator we are going to use. */
    //bool has_numbers;               /**< Status: Does *argv have numbers? */
    char *numEnd1, *numEnd2;        /**< Pointers to the ends of num1 and num2. */ 
    bool argCheck;                  /**< Check number of CL arguments */
    bool has_num1, has_num2, opCheck;        /**< Validate num1, num2, and operator */

    errno = 0;                      
    num1 = 0;                       
    num2 = 0;                       

   /**
    * @brief Checks to make sure there should only be four total arguments. 
    * 
    */
    if (4 != argc) 
    {
        /*
        for (int i = 0; i < argc; i++)
        {
            printf("argv[%d] = %s\n", i, argv[i]);
        }
        */
        fprintf(stderr, "Argument Error! Reading %d of 4 required args\n", argc);
        printf("Make sure you input the following:\n");
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }
    else
        argCheck = true;

    // TODO: Is num1 valid?
    num1 = strtol(argv[1], &numEnd1, 10);
    if (0 != errno || '\0' != *numEnd1)   // Check for over/underflow and validity of string 
    {
        fprintf(stderr, "'%s' is an invalid operand\n", argv[1]);
        printf("Make sure you input the following:\n");
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }
    else
        has_num1 = true;

    // TODO: Is num2 valid?
    num2 = strtol(argv[3], &numEnd2, 10);
    if (0 != errno || '\0' != *numEnd2)             
    {
        fprintf(stderr, "'%s' is an invalid operand\n", argv[3]);
        printf("Make sure you input the following:\n");
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }
    else
        has_num2 = true;

    // TODO: Is the operator valid?
    operation = checkOperator(argv[2]);
    if (operation == INVALID)
    {
        fprintf(stderr, "'%s' is an invalid operator\n", argv[2]);
        printf("Make sure you input the following:\n");
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }
    else
        opCheck = true;

    // TODO: Perform the calculation based on recognized operator
    // TODO: Print the output  
    if (true == argCheck && true == has_num1 && true == has_num2 && true == opCheck)
    {    
    //    long result;
        switch (operation) 
        {
            case ADD:
                result = add(num1, num2);
                printf("%ld + %ld = %ld\n", num1, num2, result);
                break;
            case SUBTRACT:
                result = subtract(num1, num2);
                printf("%ld - %ld = %ld\n", num1, num2, result);
                break;
            case MULTIPLY:
                result = multiply(num1, num2);
                printf("%ld * %ld = %ld\n", num1, num2, result);
                break;
            case DIVIDE:
                if (num2 == 0) {
                    fprintf(stderr, "Error: Division by zero is not allowed.\n");
                    return 1;
                }
                result = divide(num1, num2);
                printf("%ld / %ld = %ld\n", num1, num2, result);
                break;
            default:
                fprintf(stderr, "Invalid operation.\n");
                return 1;
        }
    }
/*
    while (-1 != (opt = getopt(argc, argv, "a:s:m:d:hv"))) // CMD Line options 
    {
        switch (opt) 
        {
            case 'a': // Add
                operation = 'a';
                num1 = strtol(optarg, &numEnd1, 10);
                if (0 != errno || '\0' != *numEnd1)   // Check for over/underflow and valid string 
                {
                    fprintf(stderr, "'%s' is an invalid operand\n", optarg);
                    exit(EXIT_FAILURE);
                }
                num2 = strtol(argv[optind], &numEnd2, 10);
                if (0 != errno || '\0' != *numEnd2)             
                {
                    fprintf(stderr, "'%s' is an invalid operand\n", argv[optind]);
                    exit(EXIT_FAILURE);
                }
                has_numbers = true;
                break;

            case 's': // Subtract
                operation = 's';
                num1 = strtol(optarg, &numEnd1, 10);
                if (0 != errno || '\0' != *numEnd1)   // Check for over/underflow and valid string
                {
                    fprintf(stderr, "'%s' is an invalid operand\n", optarg);
                    exit(EXIT_FAILURE);
                }
                num2 = strtol(argv[optind], &numEnd2, 10);
                if (0 != errno || '\0' != *numEnd2)             
                {
                    fprintf(stderr, "'%s' is an invalid operand\n", argv[optind]);
                    exit(EXIT_FAILURE);
                }
                has_numbers = true;
                break;

            case 'm': // Multiply
                operation = 'm';
                num1 = strtol(optarg, &numEnd1, 10);
                if (0 != errno || '\0' != *numEnd1)   // Check for over/underflow and valid string
                {
                    fprintf(stderr, "'%s' is an invalid operand\n", optarg);
                    exit(EXIT_FAILURE);
                }
                num2 = strtol(argv[optind], &numEnd2, 10);
                if (0 != errno || '\0' != *numEnd2)             
                {
                    fprintf(stderr, "'%s' is an invalid operand\n", argv[optind]);
                    exit(EXIT_FAILURE);
                }
                has_numbers = true;
                break;

            case 'd': // Divide
                operation = 'd';
                num1 = strtol(optarg, &numEnd1, 10);
                if (0 != errno || '\0' != *numEnd1)   // Check for over/underflow and valid string
                {
                    fprintf(stderr, "'%s' is an invalid operand\n", optarg);
                    exit(EXIT_FAILURE);
                }
                num2 = strtol(argv[optind], &numEnd2, 10);
                if (0 != errno || '\0' != *numEnd2)             
                {
                    fprintf(stderr, "'%s' is an invalid operand\n", argv[optind]);
                    exit(EXIT_FAILURE);
                }
                has_numbers = true;
                break;

            case 'h': // Help
                print_help();
                return 0;

            case 'v': // Version
                print_version();
                return 0;

            default: // Invalid option
                print_help(argv[0]);
                return 0;
        }
    }
*/

/*
    if (has_numbers) 
    {
        long result;
        switch (operation) 
        {
            case 'a':
                result = add(num1, num2);
                printf("%ld + %ld = %ld\n", num1, num2, result);
                break;
            case 's':
                result = subtract(num1, num2);
                printf("%ld - %ld = %ld\n", num1, num2, result);
                break;
            case 'm':
                result = multiply(num1, num2);
                printf("%ld * %ld = %ld\n", num1, num2, result);
                break;
            case 'd':
                if (num2 == 0) {
                    fprintf(stderr, "Error: Division by zero is not allowed.\n");
                    return 1;
                }
                result = divide(num1, num2);
                printf("%ld / %ld = %ld\n", num1, num2, result);
                break;
            default:
                fprintf(stderr, "Invalid operation.\n");
                return 1;
        }
    */

/*
    } else if (optind >= argc) {
        fprintf(stderr, "Error: Missing required options.\n");
        print_help(argv[0]);
        return 1;
    }
*/

    return 0;

    #if 0 
    DEBUG_PRINT("Hello, from debug mode\n");

    printf("6 + 3 = %d\n", add(6,3));
    printf("6 - 3 = %d\n", subtract(6,3));
    printf("6 * 3 = %d\n", multiply(6,3));
    printf("6 / 3 = %d\n", divide(6,3));

    return 0;
    #endif 
}
