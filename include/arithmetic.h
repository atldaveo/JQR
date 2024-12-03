/**
 * @file arithmetic.h
 * @author David Chung
 * @brief Function prototyping of all arithmetic functions to be used in the main program.
 * @version 2.1
 * @date 2024-11-25
 * 
 */

#ifndef ARITHMETIC_H
#define ARITHMETIC_H

/**
 * @brief Addition function.
 * 
 * @param x First number in addition sequence.
 * @param y Second number in addition sequence.
 * @param res Pointer pointing to the portion of memory holding the result of the calculation.
 * @return int32_t On success, returns a 0. Otherwise, return -1.
 */

int32_t add(int32_t x, int32_t y, int32_t *res);

/**
 * @brief Subtraction function.
 * 
 * @param x First number in subtraction sequence.
 * @param y Second number in subtraction sequence.
 * @param res Pointer pointing to the portion of memory holding the result of the calculation.
 * @return int32_t On success, returns a 0. Otherwise, return -1.
 * 
 */

int32_t subtract(int32_t x, int32_t y, int32_t *res);

/**
 * @brief Multiplication function.
 * 
 * @param x First number in multiplication sequence.
 * @param y Second number in multiplication sequence.
 * @param res Pointer pointing to the portion of memory holding the result of the calculation.
 * @return int32_t On success, returns a 0. Otherwise, return -1.
 */

int32_t multiply(int32_t x, int32_t y, int32_t *res);

/**
 * @brief Division function. Integrates error-handling for overflow, underflow, 0 dividend,
 *  and null ptr
 * 
 * @param x First number in division sequence.
 * @param y Second number in division sequence.
 * @param res Pointer pointing to the portion of memory holding the result of the calculation.
 * @return int32_t On success, returns a 0. Otherwise, return -1.
 */

int32_t divide(int32_t x, int32_t y, int32_t *res); 


#endif
