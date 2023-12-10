#ifndef TESTS_H
#define TESTS_H

#define MAX_LINE 1024
#define MAX_WORD 64
#define TEST_FUNCTION(func) \
    const char *func ## _name = #func; \
    enum TestResult run_ ## func() { \
        printf("- %s\n", func ## _name); \
        enum TestResult result = func(); \
        printf("\n"); \
        return result; \
    }


enum TestResult {
    TEST_PASSED,
    TEST_FAILED,
};

int newTestId();
enum TestResult assertInt(int actual, int expected, const char* fieldName);
enum TestResult assertNotInt(int actual, int expected, const char* fieldName);
enum TestResult assertWord(char *word, char* expected);
enum TestResult test_readword();
enum TestResult test_parseintchar();
enum TestResult test_parseint();
enum TestResult test_parsegame();


// Define test functions using the TEST_FUNCTION macro
// TEST_FUNCTION(test_readword)
// TEST_FUNCTION(test_parseintchar)
// TEST_FUNCTION(test_parseint)
// TEST_FUNCTION(test_parsegame)


enum TestResult test();

#endif // TESTS_H