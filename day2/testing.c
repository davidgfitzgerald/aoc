#include <stdio.h>
#include "part1.h"
#include "testing.h"

int newTestId()
{
    static int test_id = 1;
    return test_id++;
}

enum TestResult assertInt(int actual, int expected, const char *fieldName)
{
    int test_id = newTestId();

    if (actual != expected)
    {
        printf("Test %d failed\n", test_id);
        printf("Expected %s %d to equal %d\n", fieldName, actual, expected);
        return TEST_FAILED;
    }
    printf("Test %d passed\n", test_id);
    return TEST_PASSED;
}

enum TestResult assertNotInt(int actual, int expected, const char *fieldName)
{
    int test_id = newTestId();

    if (actual == expected)
    {
        printf("Test %d failed\n", test_id);
        printf("Expected %s %d to equal %d\n", fieldName, actual, expected);
        return TEST_FAILED;
    }
    printf("Test %d passed\n", test_id);
    return TEST_PASSED;
}

enum TestResult assertWord(char *word, char *expected)
{
    return assertInt(strcmp(word, expected), 0, "");
}