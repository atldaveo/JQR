#include <stdint.h>
#include <stdio.h>
#include "operations.h"
#include "validations.h"
#include "arithmetic.h"

#define PASS 0
#define FAIL (-1)
#define MAXSHIFT 32

int32_t
add(int32_t first_operand, int32_t second_operand, int32_t *p_result)
{
    // Check for overflow
    if ((PASS < first_operand) && (PASS < second_operand) && ((INT32_MAX - second_operand) < first_operand))
    {
        print_error(RESULT_OVERFLOW);
        return FAIL;
    }
    // Check for underflow
    if ((PASS > first_operand) && (PASS > second_operand) && ((INT32_MIN - second_operand) > first_operand))
    {
        print_error(RESULT_UNDERFLOW);
        return FAIL;
    }
    // Null pointer check
    if (NULL == p_result)
    {
        print_error(NULL_PTR);
        return FAIL;
    }
    *p_result = first_operand + second_operand;
    printf("%d + %d = %d\n", first_operand, second_operand, *p_result);
    return PASS;
}

int32_t
subtract(int32_t first_operand, int32_t second_operand, int32_t *p_result)
{
    // Check for overflow
    if ((PASS < second_operand) && ((INT32_MIN + second_operand) > first_operand))
    {
        print_error(RESULT_OVERFLOW);
        return FAIL;
    }
    // Check for underflow
    if ((second_operand < PASS) && (first_operand > INT32_MAX + second_operand))
    {
        print_error(RESULT_UNDERFLOW);
        return FAIL;
    }
    // Null pointer check
    if (NULL == p_result)
    {
        print_error(NULL_PTR);
        return FAIL;
    }
    *p_result = first_operand - second_operand;
    printf("%d - %d = %d\n", first_operand, second_operand, *p_result);
    return PASS;
}

int32_t
multiply(int32_t first_operand, int32_t second_operand, int32_t *p_result)
{
    // Overflow check with two positive arguments
    if ((PASS < first_operand) && (PASS < second_operand) && ((INT32_MAX / second_operand) < first_operand))
    {
        print_error(RESULT_OVERFLOW);
        return FAIL;
    }
    // Overflow check with two negative arguments
    if ((PASS > first_operand) && (PASS > second_operand) && ((INT32_MAX / second_operand) > first_operand))
    {
        print_error(RESULT_OVERFLOW);
        return FAIL;
    }
    // Underflow check
    if (((PASS < first_operand) && (PASS > second_operand) && ((INT32_MIN / first_operand) > second_operand)) || /**> Positive first_operand, Negative second_operand */
        ((PASS > first_operand) && (PASS < second_operand) && ((INT32_MIN / second_operand) > first_operand)))   /**> Negative first_operand, Positive second_operand */
    {
        print_error(RESULT_UNDERFLOW);
        return FAIL;
    }
    // Null pointer check
    if (NULL == p_result)
    {
        print_error(NULL_PTR);
        return FAIL;
    }
    *p_result = first_operand * second_operand;
    printf("%d * %d = %d\n", first_operand, second_operand, *p_result);

    return PASS;
}

int32_t
divide(int32_t first_operand, int32_t second_operand, int32_t *p_result)
{
    // Prevent division by 0
    if (0 == second_operand)
    {
        print_error(DIV_BY_ZERO);
        return FAIL;
    }
    // Null pointer check
    if (NULL == p_result)
    {
        print_error(NULL_PTR);
        return FAIL;
    }
    // Overflow check
    if ((INT32_MIN == first_operand) && (FAIL == second_operand))
    {
        print_error(RESULT_OVERFLOW);
        return FAIL;
    }
    if (PASS != (first_operand % second_operand))
    {
        print_error(DIV_BY_WHOLE);
        return FAIL;
    }
    *p_result = first_operand / second_operand;
    printf("%d / %d = %d\n", first_operand, second_operand, *p_result);
    return PASS;
}

int32_t
shift_right(uint32_t u_num, uint32_t space, uint32_t *p_result)
{
    // Invalid shift spacing
    if (MAXSHIFT <= space)
    {
        print_error(OVERSHIFT);
        return FAIL;
    }
    *p_result = u_num >> space;
    printf("%u >> %u = %u\n", u_num, space, *p_result);
    return PASS;
}

int32_t
shift_left(uint32_t num, uint32_t space, uint32_t *p_result)
{
    // Invalid shift spacing
    if (MAXSHIFT < space)
    {
        print_error(OVERSHIFT);
        return FAIL;
    }
    // Overflow handling
    if (UINT32_MAX < num)
    {
        print_error(RESULT_OVERFLOW);
        return FAIL;
    }
    // Upon input validation
    *p_result = num << space;
    printf("%u << %u = %u\n", num, space, *p_result);
    return PASS;
}

/* END OF FILE */