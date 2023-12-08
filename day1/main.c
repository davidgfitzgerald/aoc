#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX_LINE 1024

int readline(FILE *file, char *line);
int digtoval(char character);
int firstdigit(const char *line);
int lastdigit(const char *line);

int main(void) {
    FILE *infile = fopen("input.txt", "r");
    if (infile == NULL)
    {
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

int digtoval(char character) {
    return character - '0';
}

int firstdigit(const char *line) {
    while (*line != '\0' && !isdigit(*(line)))
    {
        line++;
    };
    return digtoval(*line);
}

int lastdigit(const char *line) {
    const char *p = line + strlen(line) - 1;
    while (!isdigit(*p)) {
        p--;
    }
    return digtoval(*p);
}
