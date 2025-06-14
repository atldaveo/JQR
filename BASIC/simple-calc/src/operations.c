#include <stdio.h>
#include <string.h>
#include <stdint.h>                 
#include "operations.h"
#include "validations.h"
#include "arithmetic.h"

#define OPERATOR_SIZE   1
#define SHIFT_SIZE      2
    
Operation
get_operator(const char* p_operator)
{
    if (NULL == p_operator)
    {
        print_error(INVALID_OPTR);
        return INVALID;
    }

    if (OPERATOR_SIZE == strlen(p_operator))    
    {
        if (PASS == strncmp(p_operator, "+", OPERATOR_SIZE))
        { 
            return ADD;
        }
        if (PASS == strncmp(p_operator, "-", OPERATOR_SIZE)) 
        {
            return SUBTRACT;
        }
        if ((PASS == strncmp(p_operator, "x", OPERATOR_SIZE)) || (PASS == strncmp(p_operator, "*", OPERATOR_SIZE)))
        { 
            return MULTIPLY;
        }
        if (PASS == strncmp(p_operator, "/", OPERATOR_SIZE))
        {
            return DIVIDE;
        }
    }

    if (SHIFT_SIZE == strlen(p_operator))
    {
        if (PASS == strncmp(p_operator, ">>", SHIFT_SIZE))
        {
            return RIGHTSHIFT;
        }
        if (PASS == strncmp(p_operator, "<<", SHIFT_SIZE))
        {
            return LEFTSHIFT;
        }
    }
    
    print_error(INVALID_OPTR);
    return INVALID;
    
}

void
execute_opn(int32_t first_operand, int32_t second_operand, Operation operation)
{
    int32_t result = 0;
    int32_t state = 0;
    uint32_t u_num = 0;
    uint32_t u_result = 0;
    uint32_t space = 0;

    switch (operation) 
    {
        case ADD:
            state = add(first_operand, second_operand, &result);
            break;

        case SUBTRACT:
            state = subtract(first_operand, second_operand, &result);
            break;

        case MULTIPLY:
            state = multiply(first_operand, second_operand, &result);
            break;

        case DIVIDE:
            state = divide(first_operand, second_operand, &result);
            break;

        case RIGHTSHIFT:
            while (PASS == state)
            {
                state = check_signed_data(first_operand, second_operand);
                u_num = (uint32_t)first_operand;
                space = (uint32_t)second_operand;
                state = shift_right(u_num, space, &u_result);
                break;
            }
            break;
            
        case LEFTSHIFT:
            while (PASS == state)
            {
                state = check_signed_data(first_operand, second_operand);
                u_num = (uint32_t)first_operand;
                space = (uint32_t)second_operand;
                state = shift_left(u_num, space, &u_result);
                break;
            }
            break;

        default:
            print_help();
            break;
    }
}

/* END OF FILE */