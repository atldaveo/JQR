/** @file operations.h
 * @author David Chung
 * @brief A series of function prototypes for miscellaneous helper functions
 * to be used throughout the main program simple-calc.
 * 
 * @version 3 (2025-04-08)
 * @date 2025-01-04
 *
 */

#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <stdint.h>
#include <stdio.h>

/** @brief Defines an enumeration of different arithmetic operations used in this program
 * 
 */
typedef enum
{
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE,
    RIGHTSHIFT,
    LEFTSHIFT,
    INVALID
} Operation;

/** @brief Get the operator object
 * 
 * @param operator User input symbol characterizing the operator to be used
 * @return Operation Arithmetic case to be switched
 */
Operation
get_operator(const char* p_operator);

/** @brief Construct a new execute opn object
 * 
 * @param first_operand First operand
 * @param second_operand Second operand
 * @param operation Selected operation
 */
void
execute_opn(int32_t first_operand, int32_t second_operand, Operation operation);

#endif

/* END OF FILE */