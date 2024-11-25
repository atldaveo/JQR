#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "math.h"
#include "debug.h"
#include "helpers.h"


int main(int argc, char *argv[]) {
    int opt, num1, num2 = 0;            // Only works for integers for now
    char operation = 0;             // Which operator we are going to use
    int has_numbers = 0;            // Status: Does *argv have numbers?

    // Parse command-line options
    while ((opt = getopt(argc, argv, "a:s:m:d:hv")) != -1) // CMD Line options 
    {
        switch (opt) 
        {
            case 'a': // Add
                operation = 'a';
                num1 = atof(optarg);
                num2 = atof(argv[optind]);
                has_numbers = 1;
                break;

            case 's': // Subtract
                operation = 's';
                num1 = atof(optarg);
                num2 = atof(argv[optind]);
                has_numbers = 1;
                break;

            case 'm': // Multiply
                operation = 'm';
                num1 = atof(optarg);
                num2 = atof(argv[optind]);
                has_numbers = 1;
                break;

            case 'd': // Divide
                operation = 'd';
                num1 = atof(optarg);
                num2 = atof(argv[optind]);
                has_numbers = 1;
                break;

            case 'h': // Help
                print_help();
                return 0;

            case 'v': // Version
                print_version();
                return 0;

            default: // Invalid option
                print_help();
                return 1;
        }
    }

    // Perform the selected operation
    if (has_numbers) 
    {
        int result;
        switch (operation) 
        {
            case 'a':
                result = add(num1, num2);
                printf("%d + %d = %d\n", num1, num2, result);
                break;
            case 's':
                result = subtract(num1, num2);
                printf("%d - %d = %d\n", num1, num2, result);
                break;
            case 'm':
                result = multiply(num1, num2);
                printf("%d * %d = %d\n", num1, num2, result);
                break;
            case 'd':
                if (num2 == 0) {
                    fprintf(stderr, "Error: Division by zero is not allowed.\n");
                    return 1;
                }
                result = divide(num1, num2);
                printf("%d / %d = %d\n", num1, num2, result);
                break;
            default:
                fprintf(stderr, "Invalid operation.\n");
                return 1;
        }
    } else if (optind >= argc) {
        fprintf(stderr, "Error: Missing required options.\n");
        print_help();
        return 1;
    }

    return 0;

    //Below contains the body of the previous iteration of code
    /*
    DEBUG_PRINT("Hello, from debug mode\n");

    printf("6 + 3 = %d\n", add(6,3));
    printf("6 - 3 = %d\n", subtract(6,3));
    printf("6 * 3 = %d\n", multiply(6,3));
    printf("6 / 3 = %d\n", divide(6,3));

    return 0;
    */
}
