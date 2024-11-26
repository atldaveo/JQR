/**
 * @file main.c
 * @author David Chung 
 * @brief Main entry point for simple-calc.
 * 
 * This program performs simple arithmetic calculations given user input via CLI.
 * 
 * @version 2.2
 * @date 2024-11-25
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <errno.h>
#include "arithmetic.h"
#include "debug.h"
#include "helpers.h"

/**
 * @brief Main function for the simple-calc program
 * 
 * @param argc Number of CMD Line arguments
 * @param argv Array of CMD Line argument strings 
 * @return int 0 if successful.
 */

int main(int argc, char *argv[]) {
     
    int opt = 0;
    long num1, num2;                /**< Numeric arguments will be converted to a long int. */
    char operation = 0;             /**< Which operator we are going to use. */
    bool has_numbers;               /**< Status: Does *argv have numbers? */
    char *numEnd1, *numEnd2;        /**< Pointers to the ends of num1 and num2. */
    
    errno = 0;                      /**< Reset error number from (errno.h) */
    num1 = 0;                       /**< Initialize the variables. */
    num2 = 0;                       /**< Initialize the variables. */

 /**
 * @brief Parse command-line options using getopt.
 * 
 * Supported options:
 * - `-a` for addition
 * - `-s` for subtraction
 * - `-m` for multiplication
 * - `-d` for division
 * - `-h` for help
 * - `-v` for version
 */

    while (-1 != (opt = getopt(argc, argv, "a:s:m:d:hv"))) // CMD Line options 
    {
        switch (opt) 
        {
            case 'a': // Add
                operation = 'a';
                num1 = strtol(optarg, &numEnd1, 10);
                if (0 != errno || '\0' != *numEnd1)   /**> Check for over/underflow and valid string */
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
                if (0 != errno || '\0' != *numEnd1)   /**> Check for over/underflow and valid string */
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
                if (0 != errno || '\0' != *numEnd1)   /**> Check for over/underflow and valid string */
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
                if (0 != errno || '\0' != *numEnd1)   /**> Check for over/underflow and valid string */
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

/**
 * @brief Perform the selected operation using the if-statement.
 * @param boolean variable `has_numbers` is true
 */
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
    } else if (optind >= argc) {
        fprintf(stderr, "Error: Missing required options.\n");
        print_help(argv[0]);
        return 1;
    }

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
