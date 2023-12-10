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
};


// prototypes
enum ProgramMode parseargs(int *argc, char* argv[]);
GAME parsegame(char *line);
enum TestResult test();
int readword(char **lineptr, char* word);
int parseInt(char* character);
int validgame(GAME game);


int main(int argc, char* argv[]) {
    enum ProgramMode mode = parseargs(&argc, argv);

    if (mode == TEST_MODE) {
        enum TestResult result = test();
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
    int isvalidgame;
    GAME game;
    int sum = 0;
    FILE *infile = fopen("input.txt", "r");


    while (fgets(line, MAX_LINE, infile) != NULL) {
        game = parsegame(line);
        // printf("ID: %d\n", game.id);
        // printf("red: %d\n", game.red);
        // printf("green: %d\n", game.green);
        // printf("blue: %d\n", game.blue);

        isvalidgame = validgame(game);
        if (isvalidgame > 0) {
            sum += game.id;
        };
    }
    printf("%d\n", sum);
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

int validgame(GAME game) {
    if (
        game.red <= 12 &&
        game.green <= 13 &&
        game.blue <= 14
    ) {
        return game.id;
    }
    return -1;
}

GAME parsegame(char *line) {
    GAME game;

    game.id = 0;
    game.red = 0;
    game.green = 0;
    game.blue = 0;

    int result;
    char word[MAX_WORD];
    char word1[MAX_WORD];
    char word2[MAX_WORD];
    int red;
    int green;
    int blue;

    // Possibly unnecessary
    word[0] = '\0';
    word1[0] = '\0';
    word2[0] = '\0';

    while ((result = readword(&line, word)) != EOF) {
        strcpy(word1, word2);
        strcpy(word2, word);
        // printf("word1: '%-5s', word2: '%-5s'\n", word1, word2);
        if (strcmp(word1, "Game") == 0) {
            game.id = parseInt(word2);
        };
        if (strcmp(word2, "red") == 0) {
            red = parseInt(word1);
            if (red >= game.red) {
                game.red = red;
            }
        };
        if (strcmp(word2, "green") == 0) {
            green = parseInt(word1);
            if (green >= game.green) {
                game.green = green;
            }
        };
        if (strcmp(word2, "blue") == 0) {
            blue = parseInt(word1);
            if (blue >= game.blue) {
                game.blue = blue;
            }
        };
    }

    return game;
}


void stripleading(char **lineptr) {
    while (
        !isalpha(**lineptr) &&
        !isdigit(**lineptr) &&
        **lineptr != '\0' && 
        **lineptr != EOF
    ) {
        (*lineptr)++;
    }
}


int parseIntChar(char character) {
    /* 
    Turn single character digit into an int
    E.g: '8' becomes 8, '5' becomes 5.
     */
    return character - '0';
}


int parseInt(char* string) {
    /* 
    Turn string of character digits into an int 
    E.g: '83' becomes 83, '50' becomes 50.
     */
    int result = -1;

    for (unsigned long i=0; i<strlen(string); i++) {
        if (result == -1) {
            result = 0;
        }
        result = (result * 10) + parseIntChar(string[i]);
    }
    
    return result;
}


int readword(char **lineptr, char* word) {
    // printf("Reading word, strlen(): %zu\n", strlen(*lineptr));
    if (strlen(*lineptr) < 1) {
        return EOF;
    }
    stripleading(&*lineptr);

    // Read only alphabetic and numeric characters
    while (isalpha(**lineptr) || isdigit(**lineptr)) {
        *word = **lineptr;
        (*lineptr)++; word++;
    }
    *word = '\0';

    return 1;  // success
}


enum TestResult test_readword() {
    char word[MAX_WORD];
    char *line = "Game 1: Some Example Input\0";
    int result;

    result = readword(&line, word);
    if (result == EOF || strcmp(word, "Game") != 0)  {
        printf("Test 1 failed\n");
        printf("Expected '%s' to equal '%s'\n", word, "Game");
        return TEST_FAILED;
    }
    printf("Test 1 passed\n");

    result = readword(&line, word);
    if (result == EOF || strcmp(word, "1") != 0)  {
        printf("Test 2 failed\n");
        printf("Expected '%s' to equal '%s'\n", word, "1");
        return TEST_FAILED;
    }
    printf("Test 2 passed\n");

    result = readword(&line, word);
    if (result == EOF || strcmp(word, "Some") != 0)  {
        printf("Test 3 failed\n");
        printf("Expected '%s' to equal '%s'\n", word, "Some");
        return TEST_FAILED;
    }
    printf("Test 3 passed\n");

    result = readword(&line, word);
    if (result == EOF || strcmp(word, "Example") != 0)  {
        printf("Test 4 failed\n");
        printf("Expected '%s' to equal '%s'\n", word, "Example");
        return TEST_FAILED;
    }
    printf("Test 4 passed\n");

    result = readword(&line, word);
    if (result == EOF || strcmp(word, "Input") != 0)  {
        printf("Test 5 failed\n");
        printf("Expected '%s' to equal '%s'\n", word, "Input");
        return TEST_FAILED;
    }
    printf("Test 5 passed\n");

    result = readword(&line, word);
    if (result != EOF)  {
        printf("Test 6 failed\n");
        printf("Expected readword to return EOF but got result: %d", result);
        return TEST_FAILED;
    }
    printf("Test 6 passed\n");

    return TEST_PASSED;
}


enum TestResult test_parseintchar() {
    int result;
    int expected;

    result = parseIntChar('0');
    expected = 0;
    if (result != expected)  {
        printf("Test 1 failed\n");
        printf("Expected parseintchar('0') '%d' to equal '%d'\n", result, expected);
        return TEST_FAILED;
    }
    printf("Test 1 passed\n");

    result = parseIntChar('1');
    expected = 1;
    if (result != expected)  {
        printf("Test 2 failed\n");
        printf("Expected parseint('1') '%d' to equal '%d'\n", result, expected);
        return TEST_FAILED;
    }
    printf("Test 2 passed\n");

    return TEST_PASSED;
}


enum TestResult test_parseint() {
    int result;
    int expected;

    result = parseInt("1");
    expected = 1;
    if (result != expected)  {
        printf("Test 1 failed\n");
        printf("Expected parseint(\"1\") '%d' to equal '%d'\n", result, expected);
        return TEST_FAILED;
    }
    printf("Test 1 passed\n");

    result = parseInt("12");
    expected = 12;
    if (result != expected)  {
        printf("Test 2 failed\n");
        printf("Expected parseint(\"12\") '%d' to equal '%d'\n", result, expected);
        return TEST_FAILED;
    }
    printf("Test 2 passed\n");

    return TEST_PASSED;
}


enum TestResult test_parsegame() {
    int expected;
    char line[] = "Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green";
    GAME game = parsegame(line);

    expected = 1;
    if (game.id != expected) {
        printf("Test 1 failed\n");
        printf("Expected game.id %d to equal %d\n", game.id, expected);
        return TEST_FAILED;
    }

    expected = 4;
    if (game.red != expected) {
        printf("Test 1 failed\n");
        printf("Expected game.red %d to equal %d\n", game.red, expected);
        return TEST_FAILED;
    }

    expected = 2;
    if (game.green != expected) {
        printf("Test 1 failed\n");
        printf("Expected game.green %d to equal %d\n", game.green, expected);
        return TEST_FAILED;
    }

    expected = 6;
    if (game.blue != expected) {
        printf("Test 1 failed\n");
        printf("Expected game.blue %d to equal %d\n", game.blue, expected);
        return TEST_FAILED;
    }

    printf("Test 1 passed\n");

    return TEST_PASSED;
}


typedef enum TestResult (*TestFunction)();


enum TestResult runTest(TestFunction testFunc, const char *testName) {
    printf("- %s\n", testName);
    enum TestResult result = testFunc();
    printf("\n");
    return result;
}


enum TestResult test() {
    printf("\nRunning tests\n\n");

    if (
        runTest(test_readword, "test_readword") == TEST_FAILED ||
        runTest(test_parseintchar, "test_parseintchar") == TEST_FAILED ||
        runTest(test_parseint, "test_parseint") == TEST_FAILED ||
        runTest(test_parsegame, "test_parsegame") == TEST_FAILED
    ) {
        return TEST_FAILED;
    }

    return TEST_PASSED;
}