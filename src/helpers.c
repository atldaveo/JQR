/**
 * @file helpers.c
 * @author David Chung
 * @brief A series of function prototypes for miscellaneous helper functions
 * to be used throughout the main program simple-calc.
 * 
 * @version 2.1
 * @date 2024-11-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include "debug.h"

/**
 * @brief Prints instructions on what the CMD Line input
 * for simple-calc ought to be. 
 * 
 * @param Passes the name of the program (ie. the first CMD Line
 * input) as argv[0] as a const char pointer so that it can't be
 * altered. 
 */

void print_help(const char *programName)
{
    printf("Usage: %s [OPTIONS]\n", programName);
    printf("Options:\n");
    printf("  -a <num1> <num2>    Add two numbers\n");
    printf("  -s <num1> <num2>    Subtract two numbers\n");
    printf("  -m <num1> <num2>    Multiply two numbers\n");
    printf("  -d <num1> <num2>    Divide two numbers\n");
    printf("  -h                  Show this help message\n");
    printf("  -v                  Show version information\n");
}

/**
 * @brief Prints the version information for simple-calc.
 * 
 */

void print_version() 
{
    printf("simple-calc version 2.1\n");
    printf("Now includes other operators and better tests!\n");
}

/**
 * @brief 
 * 
 * @param inputStr The CMD Line input operand.
 * @return true The input is a valid, computable number. 
 * @return false  The input is not a valid number.
 */

/*
bool validate_inputStr(const char *inputStr)
{
    char *endptr;

// If there is nothing in the operand input
    if (NULL == inputStr || *inputStr == '\0')
    {
        return false;
    }
    else
        return true;     
}

bool validate_inputLong(long num)
{

}
*/