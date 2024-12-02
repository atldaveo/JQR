#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "arithmetic.h"

// Tests for add function 
void test_add(void) {
    CU_ASSERT(add(1, 2) == 3);          // Positive assertion 
    CU_ASSERT(add(100, 200) == 300);    // Larger Positive assertion
    CU_ASSERT(add(-1, -1) == -2);       // Negative assertion
    CU_ASSERT(add(-5, 5) == 0);         // Negative-Zero assertion
    CU_ASSERT_FALSE(add(2,2) == 5);     // False Assertion
    CU_ASSERT(add(0, 0) == 0);          // Zero Assertion
}

// Tests for subtract function
void test_subtract(void) {
    CU_ASSERT(subtract(5, 3) == 2);         // Positive assertion 
    CU_ASSERT(subtract(500, 300) == 200);   // Larger Positive assertion
    CU_ASSERT(subtract(-5, 3) == -8);       // Negative assertion
    CU_ASSERT(subtract(-5, -5) == 0);       // Negative-Zero assertion
    CU_ASSERT_FALSE(subtract(3,2) == 3);    // False Assertion
    CU_ASSERT(subtract(0, 0) == 0);         // Zero Assertion
}

// Tests for multiply function
void test_multiply(void) {
    CU_ASSERT(multiply(5, 3) == 15);            /**< Positive assertion */
    CU_ASSERT(multiply(500, 300) == 150000);    /**< Larger Positive assertion */
    CU_ASSERT(multiply(-5, 3) == -15);          /**< Negative assertion */
    CU_ASSERT(multiply(-5, 1) == -5);           /**< Negative-identity assertion */
    CU_ASSERT_FALSE(multiply(3,2) == 3);        /**< False Assertion */
    CU_ASSERT(multiply(0, 5) == 0);             /**< Zero Assertion */
}

// Tests for divide function
void test_divide(void) {
    CU_ASSERT(divide(6, 3) == 2);                   /**< Positive assertion  */
    CU_ASSERT(divide(600, 200) == 3);               /**< Larger Positive assertion */
    CU_ASSERT(divide(-10, 2) == -5);                /**< Negative assertion */
    CU_ASSERT(divide(-5, -5) == 1);                 /**< Negative-identity assertion */
    CU_ASSERT_FALSE(divide(3,2) == 3);              /**< False Assertion */
    CU_ASSERT(divide(0, 5) == 0);                   /**< Zero Assertion */
    CU_ASSERT_EQUAL_FATAL(divide(4,0), -1);         /**< Cannot divide by zero (should return -1) */
}

// Tests for correct input arguments
// TODO: Check that num1 and num2 are convertable input strings.
// TODO: Check that num1 and num2 are bounded by LONG_MIN and LONG_MAX.
// TODO: There are only two operand arguments.  
// TODO: Make sure there is a valid operator in between operands.

int main() {
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
    if ((CU_add_test(suite, "Test Add Function", test_add) == NULL) ||
        (CU_add_test(suite, "Test Subtract Funtion", test_subtract) == NULL) ||
        (CU_add_test(suite, "Test Multiply Function", test_multiply) == NULL) || 
        (CU_add_test(suite, "Test Divide Function", test_divide) == NULL)) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Run tests using the basic interface
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return CU_get_error();
}
