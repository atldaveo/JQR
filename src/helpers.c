#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <errno.h>
#include "debug.h"

void print_help(const char *programName)
{
    printf("Usage: %s [OPTIONS]\n", programName);
    printf("Options:\n");
    printf("  <num1> + <num2>    Add two numbers\n");
    printf("  <num1> - <num2>    Subtract two numbers\n");
    printf("  <num1> x <num2>    Multiply two numbers\n");
    printf("  <num1> / <num2>    Divide two numbers\n");
    //printf("  -h                 Show this help message\n");
    //printf("  -v                 Show version information\n");
    
    /*
    printf("  -a <num1> <num2>    Add two numbers\n");
    printf("  -s <num1> <num2>    Subtract two numbers\n");
    printf("  -m <num1> <num2>    Multiply two numbers\n");
    printf("  -d <num1> <num2>    Divide two numbers\n");
    printf("  -h                  Show this help message\n");
    printf("  -v                  Show version information\n");
    */
}

void print_version() 
{
    printf("simple-calc version 2.1\n");
    printf("Now includes other operators and better tests!\n");
}