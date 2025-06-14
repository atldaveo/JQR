/**
 * @file validations.h
 * @author David Chung
 * @brief A series of function prototypes for validating the inputs required for the program to
 * function properly.
 * 
 * @version 3 (2025-03-11)
 * @date 2025-01-04
 *
 */


#ifndef VALIDATIONS_H
#define VALIDATIONS_H

#include <stdbool.h>

#define PASS    0 
#define FAIL    (-1)

typedef enum
{
    SUCCESS = 0,
    RESULT_OVERFLOW,
    RESULT_UNDERFLOW,
    NULL_PTR,
    DIV_BY_ZERO,
    DIV_BY_WHOLE,
    OVERSHIFT,
    ARG_ERROR,
    INVALID_OPTR,
    INVALID_OPND,
    INVALID_OPN
} ErrorMsg;

/** @brief Prints instructions on what the CMD Line input
 * for simple-calc ought to be. 
 * 
 */
void
print_help(void);

/** @brief Sanitizes input. Reads/consumes input args into a local variable until 
 * everything from the command line has been read.
 */
void
flush_terminal(void);

/**  @brief This function prints the appropriate error message based on the enumeration of 
 * several common errors that often appear in the code.   
 * 
 * @param code The enumerated error found in the structure above. 
 */
void
print_error(ErrorMsg code);

/** @brief Ensures that the input numbers are valid unsigned integers for shift operations
 * 
 * @param first_operand First operand the user input (serves as the number to be shifted)
 * @param second_operand Second operand the user input (serves as the space shifted)
 * @return int32_t Will return an exit code depending on success (0) or failure (-1)
 */
int32_t
check_signed_data(int32_t first_operand, int32_t second_operand);

/** @brief Error-checking for number of CMD Line arguments
 * Should be 4 <filename> <p_operand> <operator> <p_operand>
 * 
 * @param argc Number of input arguments
 * @param p_argv Pointer to individual string arguments
 * @param arg_reqd Number of arguments expected
 * @return bool return code ('rc') in main
 */
bool
count_check(int argc, int arg_reqd);

/** @brief Error-checking for valid p_operand (valid number AND size)
 * 
 * @param p_argv Pointer to the potential p_operand
 * @param p_op_end Pointer to the end of the potential p_operand
 * @param p_operand Pointer to where the p_operand will be stored (outside of function) 
 * @return bool return code ('rc') in main
 */
bool
check_opnd(char* p_argv, char* p_op_end, int32_t* p_operand);

/** @brief Check validity of operator
 * 
 * @param operation Extracted enum operation
 * @return bool Returns error code value
 */
bool
check_operator(Operation operation);

#endif

/* END OF FILE */