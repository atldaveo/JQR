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
void test_add(void)
{
    int32_t res = 0;

    CU_ASSERT_EQUAL(add(1, 2, &res), 0);                    /**< Positive assertion */
    CU_ASSERT(3 == res);  
    CU_ASSERT_EQUAL(add(100, 200, &res), 0);                /**< Larger Positive assertion */ 
    CU_ASSERT(300 == res);
    CU_ASSERT_EQUAL(add(-1, -1, &res), 0);                  /**< Negative assertion */
    CU_ASSERT(-2 == res); 
    CU_ASSERT_EQUAL(add(-5, 5, &res), 0);                   /**< Negative-Zero assertion */
    CU_ASSERT(0 == res); 
    CU_ASSERT_EQUAL(add(0, 0, &res), 0);                    /**< Zero Assertion */
    CU_ASSERT(0 == res); 
    CU_ASSERT_EQUAL(add(2, INT32_MAX, &res), -1);           /**< Resultant overflow check */
    CU_ASSERT(0 == res);
    CU_ASSERT_EQUAL(add(INT32_MIN, -1, &res), -1);          /**< Resultant underflow check */
    CU_ASSERT(0 == res);
}

// Tests for subtract function
void test_subtract(void)
{
    int32_t res = 0;
    
    CU_ASSERT_EQUAL(subtract(5, 3, &res), 0);                           /**< Positive assertion */  
    CU_ASSERT(2 == res);
    CU_ASSERT_EQUAL(subtract(500, 300, &res), 0);                       /**< Larger Positive assertion */
    CU_ASSERT(200 == res);
    CU_ASSERT_EQUAL(subtract(-5, 3, &res), 0);                          /**< Negative assertion */ 
    CU_ASSERT(-8 == res);
    CU_ASSERT_EQUAL(subtract(-5, -5, &res), 0);                         /**< Negative-Zero assertion */ 
    CU_ASSERT(0 == res);
    CU_ASSERT_EQUAL(subtract(3,2, &res), 0);                            /**< False Assertion */
    CU_ASSERT_FALSE(200 == res);
    CU_ASSERT_EQUAL(subtract(0, 0, &res), 0);                                 /**< Zero Assertion */
    CU_ASSERT(0 == res);
    CU_ASSERT_EQUAL(subtract(INT32_MAX, -1, &res), -1);                 /**< Resultant overflow check */
    CU_ASSERT(0 == res);
    CU_ASSERT_EQUAL(subtract(INT32_MIN, 1, &res), -1);                  /**< Resultant underflow check */
    CU_ASSERT(0 == res);
}

// Tests for multiply function
void test_multiply(void)
{
    int32_t res = 0;
    
    CU_ASSERT_EQUAL(multiply(5, 3, &res), 0);                           /**< Positive assertion */
    CU_ASSERT(15 == res);
    CU_ASSERT_EQUAL(multiply(500, 300, &res), 0);                       /**< Larger Positive assertion */
    CU_ASSERT(150000 == res);
    CU_ASSERT_EQUAL(multiply(-5, 3, &res), 0);                          /**< Negative assertion */
    CU_ASSERT(-15 == res);
    CU_ASSERT_EQUAL(multiply(-5, 1, &res), 0);                          /**< Negative-identity assertion */
    CU_ASSERT(-5 == res);
    CU_ASSERT_EQUAL(multiply(3, 2, &res), 0);                           /**< False Assertion */
    CU_ASSERT_FALSE(15 == res);
    CU_ASSERT_EQUAL(multiply(0, 5, &res), 0);                           /**< Zero Assertion */
    CU_ASSERT(0 == res);
    CU_ASSERT_EQUAL(multiply(INT32_MAX, 2, &res), -1);                  /**< Resultant overflow check */
    CU_ASSERT(0 == res);
    CU_ASSERT_EQUAL(multiply(200000, 200000, &res), -1);                /**< Resultant overflow check */
    CU_ASSERT(0 == res);
    CU_ASSERT_EQUAL(multiply(INT32_MIN, 2, &res), -1);                  /**< Resultant underflow check */
    CU_ASSERT(0 == res);
}

// Tests for divide function
void test_divide(void) 
{
    int32_t res = 0;

    CU_ASSERT_EQUAL(divide(6, 3, &res), 0);                      /**< Positive assertion  */
    CU_ASSERT(2 == res);
    CU_ASSERT_EQUAL(divide(600, 200, &res), 0);                  /**< Larger positive assertion */
    CU_ASSERT(3 == res);
    CU_ASSERT_EQUAL(divide(-10, 2, &res), 0);                    /**< Negative assertion */
    CU_ASSERT(-5 == res);
    CU_ASSERT_EQUAL(divide(-5, -5, &res), 0);                    /**< Negative-identity assertion */
    CU_ASSERT(1 == res);
    CU_ASSERT_EQUAL(divide(3, 2, &res), 0);                      /**< False assertion */
    CU_ASSERT_FALSE(15 == res);
    CU_ASSERT_EQUAL(divide(0, 5, &res), 0);                      /**< Zero assertion */
    CU_ASSERT(0 == res);
    CU_ASSERT_EQUAL(divide(4, 0, &res), -1);                     /**< Divide by 0 */
    CU_ASSERT(0 == res);
    CU_ASSERT_EQUAL(divide(INT32_MIN, -1, &res), -1);            /**< Resultant overflow check */
    CU_ASSERT(0 == res);
}

void test_shift_right(void)
{
    int32_t res = 0;

    // TODO: Add test conditions
}

void test_shift_left(void)
{
    int32_t res = 0;

    // TODO: Add test conditions
}

int main() 
{
    // Initialize the CUnit test registry
    if (CUE_SUCCESS != CU_initialize_registry())
    {
        return CU_get_error();
    }

    // Create a test suite
    CU_pSuite suite = CU_add_suite("Math Suite", NULL, NULL);
    if (suite == NULL)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Add tests to the suite
    if ((CU_add_test(suite, "Test Add Function", test_add) == NULL) ||
        (CU_add_test(suite, "Test Subtract Funtion", test_subtract) == NULL) ||
        (CU_add_test(suite, "Test Multiply Function", test_multiply) == NULL) || 
        (CU_add_test(suite, "Test Divide Function", test_divide) == NULL) ||
        (CU_add_test(suite, "Test Shift Right Function", test_shift_right) == NULL) ||
        (CU_add_test(suite, "Test Shift Left Function", test_shift_left) == NULL)
        )
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Run tests using the basic interface
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return CU_get_error();
}
