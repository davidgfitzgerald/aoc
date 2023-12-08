#include <stdio.h>
#define MAX_LINE 1024

int readline(FILE *file, char *line)
{
    int letter;
    char *p = line;

    while ((letter = getc(file)))
    {
        if (letter == '\n')
        {
            break;
        }
        else if (letter == EOF)
        {
            return EOF;
        };

        *p++ = letter;
    };
    *p = '\0';
    return 1;
}

int digtoval(char character)
{
    return character - 48;
}

int isdig(char character)
{
    int integer = (int)character;
    return integer >= 48 && integer <= 57;
}

int firstdig(char *line)
{
    char *p = line;
    while (!isdig(*p))
    {
        p++;
    };
    return digtoval(*p);
}

int lastdig(char *line)
{
    char *p = line;
    while (*p != '\0')
    {
        p++;
    };

    while (!isdig(*p))
    {
        p--;
    };
    return digtoval(*p);
}

int main()
{
    FILE *infile = fopen("input.txt", "r");

    char line[MAX_LINE];
    int sum = 0;
    int res;

    while ((res = readline(infile, line)))
    {
        int firstdigit = firstdig(line);
        int lastdigit = lastdig(line);

        int linesum = 10 * (firstdigit) + lastdigit;
        sum += linesum;
        if (res == EOF)
        {
            break;
        };
    };
    printf("%d", sum);
    return 0;
}