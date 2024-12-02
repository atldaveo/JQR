/**
 * @file helpers.c
 * @author David Chung (david.chung1719@outlook.com)
 * @brief Defines maintenance functions used in main.c
 * @version 0.1
 * @date 02Dec24
 * 
 * @copyright Copyright (c) 2024
 * 
 */

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

void printHelp(const char *programName)
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

void printVersion() 
{
    printf("simple-calc version 2.5\n");
    printf("Now includes other operators and more flexibility\n");
}