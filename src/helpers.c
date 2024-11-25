#include <stdio.h>
#include <unistd.h>
#include "debug.h"

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

void print_version() 
{
    printf("simple-calc version 1.0\n");
}