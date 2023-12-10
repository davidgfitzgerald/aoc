#ifndef TESTS_H
#define TESTS_H

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


#endif // TESTS_H