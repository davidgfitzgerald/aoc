#include <stdio.h>
#include "funcs.h"
#include "../../testing/testing.h"


enum TestResult test_add_function()
{
    if (
        assertInt(add(1, 2), 4, "add(1, 2)") == TEST_FAILED ||
        assertInt(add(-1, 0), -1, "add(-1, 0)") == TEST_FAILED)
    {
        return TEST_FAILED;
    }
    return TEST_PASSED;
}

// Define test functions using the TEST_FUNCTION macro
TEST_FUNCTION(test_add_function)


enum TestResult test()
{
    printf("\nRunning tests\n\n");

    if (
        run_test_add_function() == TEST_FAILED
    ) {
        return TEST_FAILED;
    }

    return TEST_PASSED;
}

int main(void) {
    test();
}