#include <stdio.h>
#include <stdbool.h>
#include <errno.h>                 
#include <stdint.h>
#include <stdlib.h>
#include <limits.h>                
#include "operations.h"
#include "validations.h"
#include "arithmetic.h"

#define BASE            10
#define ERRNO_RESET     0

void
print_help(void)
{
    printf("Usage: ./simple-calc [OPTIONS]\n");
    printf("OPTIONS:\n");
    printf("  <num1> + <num2>     Add two numbers\n");
    printf("  <num1> - <num2>     Subtract two numbers\n");
    printf("  <num1> * <num2>     Multiply two numbers\n");
    printf("  <num1> / <num2>     Divide two numbers\n");
    printf("  <num> >> <space>    Right shift a number by space(s)\n");
    printf("  <num> << <space>    Left shift a number by space(s)\n");
    printf("  -h                  Show this help message\n\n");

    printf("Remember, the operands must be between -2147483648 and 2147483647 (32 bits)\n");
}

void
flush_terminal(void)
{
    int32_t item;
    while ((item = getchar()) != '\n' && item != EOF);
}

void
print_error(ErrorMsg code)
{
    switch (code) 
    {
        case RESULT_OVERFLOW:
            printf("Error: Overflow. Result is too large\n");
            break;
        case RESULT_UNDERFLOW:
            printf("Error: Underflow. Result is too small\n");
            break;
        case NULL_PTR:
            printf("Error: Null pointer\n");
            break;
        case DIV_BY_ZERO:
            printf("Error: Can't divide by 0!\n");
            break;
        case DIV_BY_WHOLE:
            printf("Inputs must divide into whole numbers!\n");
            break;
        case OVERSHIFT:
            printf("Error: Can't shift that far!\n");
            break;
        case ARG_ERROR:
            printf("Error: Incorrect number of args\n");
            break;
        case INVALID_OPTR:
            printf("Error: Invalid operator \n");
            break;
        case INVALID_OPND:
            printf("Error: Invalid operand.\n");
            break;
        case INVALID_OPN:
            printf("Error: Unrecognized command. Follow usage below.\n");
            print_help();
            break;

        default:
            printf("Error: Unknown error occurred.\n");
            break;
    }
}

int32_t
check_signed_data(int32_t first_operand, int32_t second_operand)
{
    if ((0 > first_operand) && (0 > second_operand))
    {
        return PASS;
    }
    return FAIL;
}

bool
count_check(int argc, int arg_reqd)
{
    if (arg_reqd != argc)                                  
    {
        print_error(ARG_ERROR);
        printf("Reading %d of %d required args\n", argc, arg_reqd);
        printf("Try putting the operator between quotes " " \n");
        print_help();   
        return false;
    }
    return true;
}

bool
check_opnd(char* p_argv, char* p_op_end, int32_t* p_operand)
{
    long number; 
    errno = ERRNO_RESET;                                  

    number = strtol(p_argv, &p_op_end, BASE);

    if (ERRNO_RESET != errno || '\0' != *p_op_end)         
    {
        return false;
    }

    if (number < INT32_MIN)
    {
        printf("Operand too small!\n");
        return false;
    }

    if (number > INT32_MAX)
    {
        printf("Operand too big!\n");
        return false;
    }

    *p_operand = (int32_t)number;
    return true;
}

bool
check_operator(Operation operation)
{
    if (operation != INVALID)
    {
        return true;
    }
    return false;
}

/* END OF FILE */