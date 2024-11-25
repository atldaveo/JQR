#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "math.h"

// Test for add function: positive numbers
void test_add_positive(void) {
    CU_ASSERT(add(1, 2) == 3);
    CU_ASSERT(add(100, 200) == 300);
}

// Test for add function: negative numbers
void test_add_negative(void) {
    CU_ASSERT(add(-1, -1) == -2);
    CU_ASSERT(add(-5, 5) == 0);
}

// Test for add function: false result required
void test_assert_false(void)
{
    CU_ASSERT_FALSE(add(2,2) == 5);
}

// Test for add function: zero
void test_add_zero(void) {
    CU_ASSERT(add(0, 0) == 0);
}

int main() {
    // Initialize the CUnit test registry
    if (CUE_SUCCESS != CU_initialize_registry()) {
        return CU_get_error();
    }

    // Create a test suite
    CU_pSuite suite = CU_add_suite("Test Suite for Add Function", NULL, NULL);
    if (suite == NULL) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Add tests to the suite
    if ((CU_add_test(suite, "Test Positive Numbers", test_add_positive) == NULL) ||
        (CU_add_test(suite, "Test Negative Numbers", test_add_negative) == NULL) ||
        (CU_add_test(suite, "Test Assert False", test_assert_false) == NULL) || 
        (CU_add_test(suite, "Test Zero", test_add_zero) == NULL)) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Run tests using the basic interface
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return CU_get_error();
}
