/**
 * @file test_arithmetic.c
 * @author David Chung (david.chung1719@outlook.com)
 * @brief Basic testing suites developed for ensuring proper behavior of arithmetic functions.
 * @version 0.1
 * @date 02Dec24
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <stdint.h>
#include "arithmetic.h"


// Tests for add function 
void testAdd(void) {
    CU_ASSERT(add(1, 2) == 3);                                  /**< Positive assertion */  
    CU_ASSERT(add(100, 200) == 300);                            /**< Larger Positive assertion */ 
    CU_ASSERT(add(-1, -1) == -2);                               /**< Negative assertion */ 
    CU_ASSERT(add(-5, 5) == 0);                                 /**< Negative-Zero assertion */ 
    CU_ASSERT_FALSE(add(2,2) == 5);                             /**< False Assertion */
    CU_ASSERT(add(0, 0) == 0);                                  /**< Zero Assertion */ 
    CU_ASSERT_EQUAL(add(2, INT32_MAX), -1);                     /**< Resultant overflow check */
    CU_ASSERT_EQUAL(add(INT32_MIN, -1), -1);                    /**< Resultant underflow check */
}

// Tests for subtract function
void testSubtract(void) {
    CU_ASSERT(subtract(5, 3) == 2);                                 /**< Positive assertion */  
    CU_ASSERT(subtract(500, 300) == 200);                           /**< Larger Positive assertion */ 
    CU_ASSERT(subtract(-5, 3) == -8);                               /**< Negative assertion */ 
    CU_ASSERT(subtract(-5, -5) == 0);                               /**< Negative-Zero assertion */ 
    CU_ASSERT_FALSE(subtract(3,2) == 3);                            /**< False Assertion */
    CU_ASSERT(subtract(0, 0) == 0);                                 /**< Zero Assertion */
    CU_ASSERT_EQUAL(subtract(INT32_MAX, -1), -1);                   /**< Resultant overflow check */
    CU_ASSERT_EQUAL(subtract(INT32_MIN, 1), -1);                    /**< Resultant underflow check */
}

// Tests for multiply function
void testMultiply(void) {
    CU_ASSERT(multiply(5, 3) == 15);                               /**< Positive assertion */
    CU_ASSERT(multiply(500, 300) == 150000);                       /**< Larger Positive assertion */
    CU_ASSERT(multiply(-5, 3) == -15);                             /**< Negative assertion */
    CU_ASSERT(multiply(-5, 1) == -5);                              /**< Negative-identity assertion */
    CU_ASSERT_FALSE(multiply(3,2) == 3);                           /**< False Assertion */
    CU_ASSERT(multiply(0, 5) == 0);                                /**< Zero Assertion */
    CU_ASSERT_EQUAL(multiply(INT32_MAX, 2), -1);                   /**< Resultant overflow check */
    CU_ASSERT_EQUAL(multiply(200000, 200000), -1);                  /**< Resultant overflow check */
    CU_ASSERT_EQUAL(multiply(INT32_MIN, 2), -1);                   /**< Resultant underflow check */
}

// Tests for divide function
void testDivide(void) {
    CU_ASSERT(divide(6, 3) == 2);                               /**< Positive assertion  */
    CU_ASSERT(divide(600, 200) == 3);                           /**< Larger Positive assertion */
    CU_ASSERT(divide(-10, 2) == -5);                            /**< Negative assertion */
    CU_ASSERT(divide(-5, -5) == 1);                             /**< Negative-identity assertion */
    CU_ASSERT_FALSE(divide(3,2) == 3);                          /**< False Assertion */
    CU_ASSERT(divide(0, 5) == 0);                               /**< Zero Assertion */
    CU_ASSERT_EQUAL_FATAL(divide(4,0), -1);                     /**< Cannot divide by zero (should return -1) */
    CU_ASSERT_EQUAL(divide(INT32_MIN, -1), -1);                 /**< Resultant overflow check */
}

int main() 
{
    // Initialize the CUnit test registry
    if (CUE_SUCCESS != CU_initialize_registry()) {
        return CU_get_error();
    }

    // Create a test suite
    CU_pSuite suite = CU_add_suite("Math Suite", NULL, NULL);
    if (suite == NULL) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Add tests to the suite
    if ((CU_add_test(suite, "Test Add Function", testAdd) == NULL) ||
        (CU_add_test(suite, "Test Subtract Funtion", testSubtract) == NULL) ||
        (CU_add_test(suite, "Test Multiply Function", testMultiply) == NULL) || 
        (CU_add_test(suite, "Test Divide Function", testDivide) == NULL)) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Run tests using the basic interface
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return CU_get_error();
}
