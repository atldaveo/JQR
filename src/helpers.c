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
#include "debug.h"

/**
 * @brief Prints instructions on what the CMD Line input
 * for simple-calc ought to be. 
 * 
 */

void print_help()
{
    printf("Usage: simple-calc [OPTIONS]\n");
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