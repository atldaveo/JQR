/** 
 * @file arithmetic.h
 * @author David Chung
 * @brief Function prototype for all arithmetic functions to be used in the program.
 * @version 3 (2025-04-08)
 * @date 2024-11-25
 * 
 */

#ifndef ARITHMETIC_H
#define ARITHMETIC_H

/** @brief Addition function.
 * 
 * @param first_operand First number in addition sequence.
 * @param second_operand Second number in addition sequence.
 * @param p_result Pointer pointing to the portion of memorsecond_operand holding the p_result of the calculation.
 * @return int32_t On success, returns a 0. Otherwise, return -1.
 */
int32_t
add(int32_t first_operand, int32_t second_operand, int32_t* p_result);

/** @brief Subtraction function.
 * 
 * @param first_operand First number in subtraction sequence.
 * @param second_operand Second number in subtraction sequence.
 * @param p_result Pointer pointing to the portion of memorsecond_operand holding the p_result of the calculation.
 * @return int32_t On success, returns a 0. Otherwise, return -1.
 * 
 */
int32_t
subtract(int32_t first_operand, int32_t second_operand, int32_t* p_result);

/** @brief Multiplication function.
 * 
 * @param first_operand First number in multiplication sequence.
 * @param second_operand Second number in multiplication sequence.
 * @param p_result Pointer pointing to the portion of memorsecond_operand holding the p_result of the calculation.
 * @return int32_t On success, returns a 0. Otherwise, return -1.
 */
int32_t
multiply(int32_t first_operand, int32_t second_operand, int32_t* p_result);

/** @brief Division function. Integrates error-handling for overflow, underflow, 0 dividend,
 *  and null ptr
 * 
 * @param first_operand First number in division sequence.
 * @param second_operand Second number in division sequence.
 * @param p_result Pointer pointing to the portion of memorsecond_operand holding the p_result of the calculation.
 * @return int32_t On success, returns a 0. Otherwise, return -1.
 */
int32_t
divide(int32_t first_operand, int32_t second_operand, int32_t* p_result); 

/** @brief Shift Right function
 * 
 * @param num Number to be shifted.
 * @param space Number of bits to be shifted bsecond_operand.
 * @param p_result Pointer pointing to the portion of memorsecond_operand holding the p_result of the calculation.
 * @return int32_t On success, returns a 0. Otherwise, return -1.
 */
int32_t
shift_right(uint32_t num, uint32_t space, uint32_t* p_result);

/** @brief Shift Left function
 * 
 * @param num Number to be shifted.
 * @param space Number of bits to be shifted bsecond_operand.
 * @param p_result Pointer pointing to the portion of memorsecond_operand holding the p_result of the calculation.
 * @return int32_t On success, returns a 0. Otherwise, return -1.
 */
int32_t
shift_left(uint32_t num, uint32_t space, uint32_t* p_result);

#endif

/* END OF FILE */