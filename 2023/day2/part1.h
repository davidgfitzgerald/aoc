#include <string.h>
#ifndef PART1_H
#define PART1_H
#define MAX_LINE 1024
#define MAX_WORD 64

typedef struct game
{
    int id;
    int red;
    int green;
    int blue;
} GAME;
enum ProgramMode
{
    REGULAR_MODE,
    TEST_MODE,
    INVALID_MODE,
};
int main(int argc, char *argv[]);
enum ProgramMode parseargs(int *argc, char *argv[]);
int validgame(GAME game);
GAME parsegame(char *line);
void stripleading(char **lineptr);
int parseIntChar(char character);
int parseInt(char *string);
int readword(char **lineptr, char *word);

#endif // PART1_H