#include <stdio.h>
#include "part1.h"
#include "testing.h"

enum TestResult test_readword()
{
    char word[MAX_WORD];
    char *line = "Game 1: Some Example Input\0";

    if (
        assertNotInt(readword(&line, word), EOF, "") == TEST_FAILED ||
        assertWord(word, "Game") == TEST_FAILED ||
        assertNotInt(readword(&line, word), EOF, "") == TEST_FAILED ||
        assertWord(word, "1") == TEST_FAILED ||
        assertNotInt(readword(&line, word), EOF, "") == TEST_FAILED ||
        assertWord(word, "Some") == TEST_FAILED ||
        assertNotInt(readword(&line, word), EOF, "") == TEST_FAILED ||
        assertWord(word, "Example") == TEST_FAILED ||
        assertNotInt(readword(&line, word), EOF, "") == TEST_FAILED ||
        assertWord(word, "Input") == TEST_FAILED ||
        assertInt(readword(&line, word), EOF, "") == TEST_FAILED)
    {
        return TEST_FAILED;
    }

    return TEST_PASSED;
}

enum TestResult test_parseintchar()
{
    if (
        assertInt(parseIntChar('0'), 0, "parseint('0'))") == TEST_FAILED ||
        assertInt(parseIntChar('1'), 1, "parseint('1'") == TEST_FAILED)
    {
        return TEST_FAILED;
    }
    return TEST_PASSED;
}

enum TestResult test_parseint()
{
    if (
        assertInt(parseInt("1"), 1, "parseint(\"1\")") == TEST_FAILED ||
        assertInt(parseInt("12"), 12, "parseint(\"12\"") == TEST_FAILED)
    {
        return TEST_FAILED;
    }
    return TEST_PASSED;
}

enum TestResult test_parsegame()
{
    char line[] = "Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green";
    GAME game = parsegame(line);

    if (
        assertInt(game.id, 1, "game.id") == TEST_FAILED ||
        assertInt(game.red, 4, "game.red") == TEST_FAILED ||
        assertInt(game.green, 2, "game.green") == TEST_FAILED ||
        assertInt(game.blue, 6, "game.blue") == TEST_FAILED)
    {
        return TEST_FAILED;
    }
    return TEST_PASSED;
}

// Define test functions using the TEST_FUNCTION macro
TEST_FUNCTION(test_readword)
TEST_FUNCTION(test_parseintchar)
TEST_FUNCTION(test_parseint)
TEST_FUNCTION(test_parsegame)

enum TestResult test()
{
    printf("\nRunning tests\n\n");

    if (
        run_test_readword() == TEST_FAILED ||
        run_test_parseintchar() == TEST_FAILED ||
        run_test_parseint() == TEST_FAILED ||
        run_test_parsegame() == TEST_FAILED)
    {
        return TEST_FAILED;
    }

    return TEST_PASSED;
}