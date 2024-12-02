#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <errno.h>
#include "debug.h"

/**
 * @brief Prints a guide on using simple-calc.
 * 
 * @param programName Same as argv[0]. 
 */

void print_help(const char *programName)
{
    printf("Usage: %s [OPTIONS]\n", programName);
    printf("Options:\n");
    printf("  <num1> + <num2>     Add two numbers\n");
    printf("  <num1> - <num2>     Subtract two numbers\n");
    printf("  <num1> * <num2>     Multiply two numbers\n");
    printf("  <num1> / <num2>     Divide two numbers\n");
    printf("  -h                  Show this help message\n");
    printf("  -v                  Show version information\n");
}

/**
 * @brief Prints software information.
 * 
 */

void print_version() 
{
    printf("simple-calc version 2.5\n");
    printf("Now includes other operators and more flexibility\n");
}