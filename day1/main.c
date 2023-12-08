#include <stdio.h>
#include <ctype.h>
#define MAX_LINE 1024

int readline(FILE *file, char *line);
int digtoval(char character);
int firstdigit(char *line);
int lastdigit(char *line);

int main()
{
    FILE *infile = fopen("input.txt", "r");
    if (infile == NULL) {
        perror("Error opening file");
        return 1;
    }

    char line[MAX_LINE];
    int sum = 0;

    while (fgets(line, MAX_LINE, infile) != NULL)
    {
        int firstdig = firstdigit(line);
        int lastdig = lastdigit(line);

        int linesum = 10 * (firstdig) + lastdig;
        sum += linesum;
    };
    printf("%d", sum);
    return 0;
}

int digtoval(char character)
{
    return character - '0';
}

int firstdigit(char *line)
{
    char *p = line;
    while (!isdigit(*p))
    {
        p++;
    };
    return digtoval(*p);
}

int lastdigit(char *line)
{
    char *p = line;
    while (*p != '\0')
    {
        p++;
    };

    while (!isdigit(*p))
    {
        p--;
    };
    return digtoval(*p);
}
