#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "part1.h"
#include "test_part1.h"

#define SET_MAX(COLOUR)                \
    if (strcmp(word2, #COLOUR) == 0) { \
        int value = parseInt(word1);   \
        if (value >= game.COLOUR) {    \
            game.COLOUR = value;       \
        }                              \
    };


int main(int argc, char *argv[])
{
    enum ProgramMode mode = parseargs(&argc, argv);

    if (mode == TEST_MODE)
    {
        enum TestResult result = test();
        if (result == TEST_FAILED)
        {
            printf("Tests failed.\n");
            exit(1);
        }
        if (result == TEST_PASSED)
        {
            printf("All tests passed.\n");
            exit(0);
        }
    }

    if (mode != REGULAR_MODE)
    {
        printf("Error: Not running in regular mode");
        exit(1);
    }

    char line[MAX_LINE];
    int isvalidgame;
    GAME game;
    int sum = 0;
    FILE *infile = fopen("input.txt", "r");

    while (fgets(line, MAX_LINE, infile) != NULL)
    {
        game = parsegame(line);

        isvalidgame = validgame(game);
        if (isvalidgame > 0)
        {
            sum += game.id;
        };
    }
    printf("%d\n", sum);
}

enum ProgramMode parseargs(int *argc, char *argv[])
{
    if (*argc == 1)
    {
        return REGULAR_MODE;
    }

    if (*argc == 2 && strcmp(argv[1], "--test") == 0)
    {
        return TEST_MODE;
    }

    return INVALID_MODE;
}

int validgame(GAME game)
{
    if (
        game.red <= 12 &&
        game.green <= 13 &&
        game.blue <= 14)
    {
        return game.id;
    }
    return -1;
}

GAME parsegame(char *line)
{
    GAME game = {.id = 0, .red = 0, .green = 0, .blue = 0};

    int result;
    char word[MAX_WORD];
    char word1[MAX_WORD];
    char word2[MAX_WORD];

    while ((result = readword(&line, word)) != EOF)
    {
        strcpy(word1, word2);
        strcpy(word2, word);

        if (strcmp(word1, "Game") == 0)
        {
            game.id = parseInt(word2);
        };

        SET_MAX(red);
        SET_MAX(green);
        SET_MAX(blue);
    }

    return game;
}

void stripleading(char **lineptr)
{
    while (
        !isalpha(**lineptr) &&
        !isdigit(**lineptr) &&
        **lineptr != '\0' &&
        **lineptr != EOF)
    {
        (*lineptr)++;
    }
}

int parseIntChar(char character)
{
    /*
    Turn single character digit into an int
    E.g: '8' becomes 8, '5' becomes 5.
     */
    return character - '0';
}

int parseInt(char *string)
{
    /*
    Turn string of character digits into an int
    E.g: '83' becomes 83, '50' becomes 50.
     */
    int result = -1;

    for (unsigned long i = 0; i < strlen(string); i++)
    {
        if (result == -1)
        {
            result = 0;
        }
        result = (result * 10) + parseIntChar(string[i]);
    }

    return result;
}

int readword(char **lineptr, char *word)
{
    if (strlen(*lineptr) < 1)
    {
        return EOF;
    }
    stripleading(&*lineptr);

    while (isalpha(**lineptr) || isdigit(**lineptr))
    {
        *word = **lineptr;
        (*lineptr)++;
        word++;
    }
    *word = '\0';

    return 1; // success
}
