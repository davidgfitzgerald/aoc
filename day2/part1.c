#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_LINE 1024
#define MAX_WORD 64


typedef struct game
{
    int id;
    int red;
    int green;
    int blue;
} GAME;


enum ProgramMode {
    REGULAR_MODE,
    TEST_MODE,
    INVALID_MODE,
};


enum TestResult {
    TEST_PASSED,
    TEST_FAILED,
    TEST_ERROR,
};


// prototypes
enum ProgramMode parseargs(int *argc, char* argv[]);
GAME parsegame(char *line);
enum TestResult test();


int main(int argc, char* argv[]) {
    enum ProgramMode mode = parseargs(&argc, argv);

    if (mode == TEST_MODE) {
        enum TestResult result = test();
        if (result == TEST_ERROR) {
            printf("Tests errored\n");
            exit(1);
        }
        if (result == TEST_FAILED) {
            printf("Tests failed.\n");
            exit(1);
        }
        if (result == TEST_PASSED) {
            printf("All tests passed.\n");
            exit(0);
        }
    }

    if (mode != REGULAR_MODE) {
        printf("Error: Not running in regular mode");
        exit(1);
    }

    char line[MAX_LINE];
    FILE *infile = fopen("input.txt", "r");

    fgets(line, MAX_LINE, infile);
    GAME game = parsegame(line);
    printf("ID: %d\n", game.id);
    printf("red: %d\n", game.red);
    printf("green: %d\n", game.green);
    printf("blue: %d\n", game.blue);

}


enum ProgramMode parseargs(int *argc, char* argv[]) {
    if (*argc == 1) {
        return REGULAR_MODE;
    }

    if (*argc == 2 && strcmp(argv[1], "--test") == 0) {
        return TEST_MODE;
    }

    return INVALID_MODE;
}

// TODO: Remove this once line is used
#pragma GCC diagnostic ignored "-Wunused-parameter"
GAME parsegame(char *line) {
    GAME game;

    game.id = 1;
    game.red = 1;
    game.green = 1;
    game.blue = 1;

    return game;
}


void readword(char **lineptr, char* word) {
    char* line = *lineptr;

    // Remove irrelevant leading characters
    while (!isalpha(*line) && !isdigit(*line)) {
        (line)++;
    }

    // Read only alphabet and numeric characters
    while (isalpha(*line) || isdigit(*line)) {
        *word = *line;
        line++; word++;
    }
    *word = '\0';

    *lineptr = line;  // Update the original line pointer
}


enum TestResult test() {
    char word[MAX_WORD];
    char *line = "Game 1: Some Example Input\0";

    readword(&line, word);
    if (strcmp(word, "Game") != 0)  {
        printf("Test 1 failed\n");
        printf("Expected '%s' to equal %s\n", word, "Game");
        return TEST_FAILED;
    }
    printf("Test 1 passed\n");

    readword(&line, word);
    if (strcmp(word, "1") != 0)  {
        printf("Test 2 failed\n");
        printf("Expected '%s' to equal %s\n", word, "1");
        return TEST_FAILED;
    }
    printf("Test 2 passed\n");

    readword(&line, word);
    if (strcmp(word, "Some") != 0)  {
        printf("Test 3 failed\n");
        printf("Expected '%s' to equal %s\n", word, "Some");
        return TEST_FAILED;
    }
    printf("Test 3 passed\n");

    return TEST_PASSED;
}