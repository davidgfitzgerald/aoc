#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX_LINE 1024


char * numbers[] = {
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine",
    NULL,
};


int test();
int anymatches(char *strings[], char *pattern);
int firstdigit(char line[MAX_LINE]);
int lastdigit(char line[MAX_LINE]);
int digtoval(char character);
int stringtoint(char *string);

int main(void) {
    char line[MAX_LINE];
    int sum = 0;

    FILE *infile = fopen("input.txt", "r");
    while (fgets(line, MAX_LINE, infile) != NULL)
    {
        int firstdig = firstdigit(line);
        int lastdig = lastdigit(line);

        int linesum = 10 * (firstdig) + lastdig;
        sum += linesum;
    };
    printf("%d\n", sum);
    return 0;
}

int firstdigit(char line[MAX_LINE])
{
    char *ptr = line;
    char *nestedptr = ptr;
    char buffer[MAX_LINE];
    char *bufferptr;

    while (*ptr != '\0')
    {
        if (isdigit(*ptr))
        {
            return digtoval(*ptr);
        }
        bufferptr = buffer;
        *bufferptr = *ptr;
        bufferptr++;
        *bufferptr = '\0';

        int result = anymatches(numbers, buffer);

        while (result)
        {
            if (result == 0)
            {
                break;
            }
            else if (result == 2)
            {
                return stringtoint(buffer);
            }
            nestedptr++;
            *bufferptr = *nestedptr;
            bufferptr++;
            *bufferptr = '\0';
            result = anymatches(numbers, buffer);
        }

        ptr++;
        nestedptr = ptr;
        *bufferptr = *ptr;
    }
    return -1;
}

int lastdigit(char line[MAX_LINE])
{
    char *ptr = line + strlen(line) - 1;
    char *nestedptr = ptr;
    char buffer[MAX_LINE];
    char *bufferptr;

    while (*ptr != '\0')
    {
        if (isdigit(*ptr))
        {
            return digtoval(*ptr);
        }
        bufferptr = buffer;
        *bufferptr = *ptr;
        bufferptr++;
        *bufferptr = '\0';

        int result = anymatches(numbers, buffer);

        while (result)
        {
            if (result == 0)
            {
                break;
            }
            else if (result == 2)
            {
                return stringtoint(buffer);
            }
            nestedptr++;
            *bufferptr = *nestedptr;
            bufferptr++;
            *bufferptr = '\0';
            result = anymatches(numbers, buffer);

        }

        ptr--;
        nestedptr = ptr;
    }
    return -1;
}

int matches(char *line, char *pattern) {
    while (*line != '\0' && *pattern != '\0') {
        if (*line != *pattern) {
            return 0;  // no match
        }
        line++; pattern++;
    }
    if (*line == *pattern) {
        return 2;  // exact match e.g. two == two
    }
    return 1;  // substring e.g. on is sub of one
}


int anymatches(char *strings[], char *pattern) {
    int index = 0;

    while (strings[index] != NULL) {
        char *string = strings[index];
        int result = (matches(string, pattern));
        if (result == 1 || result == 2) {
            return result;
        };
        index++;
    }

    return 0;
}

int digtoval(char character) {
    return character - '0';
}

int stringtoint(char *string) {
    if (strcmp(string, "zero") == 0) {
        return 0;
    } else if (strcmp(string, "one") == 0) {
        return 1;
    } else if (strcmp(string, "two") == 0) {
        return 2;
    } else if (strcmp(string, "three") == 0) {
        return 3;
    } else if (strcmp(string, "four") == 0) {
        return 4;
    } else if (strcmp(string, "five") == 0) {
        return 5;
    } else if (strcmp(string, "six") == 0) {
        return 6;
    } else if (strcmp(string, "seven") == 0) {
        return 7;
    } else if (strcmp(string, "eight") == 0) {
        return 8;
    } else if (strcmp(string, "nine") == 0) {
        return 9;
    }
    return -1;
}

int test() {
    printf("\n");
    printf("=========\n");
    printf("= TESTS =\n");
    printf("=========\n");
    printf("\n");

    if (matches("hello", "hell") != 1) {
        printf("Test 1 failed\n");
        printf("Error in matches function\n");
        printf("hello matches hell returned false\n");
        return 0;
    };
    printf("Test 1 passed\n");

    if (matches("o", "o") != 2) {
        printf("Test 2 failed\n");
        printf("Error in matches function\n");
        printf("o matches o returned false\n");
        return 0;
    };
    printf("Test 2 passed\n");

    if (anymatches(numbers, "o") != 1) {
        printf("Test 3 failed\n");
        printf("Error in anymatches function\n");
        printf("at least one of numbers matches o returned false\n");
        return 0;
    };
    printf("Test 3 passed\n");

    if (anymatches(numbers, "t") != 1) {
        printf("Test 4 failed\n");
        printf("Error in anymatches function\n");
        printf("at least one of numbers matches t returned false\n");
        return 0;
    };
    printf("Test 4 passed\n");

    if (anymatches(numbers, "two") != 2) {
        printf("Test 5 failed\n");
        printf("Error in anymatches function\n");
        printf("at least one of numbers matches two returned false\n");
        return 0;
    };
    printf("Test 5 passed\n");

    if (lastdigit("twoeightnq6ninepxv") != 9) {
        printf("Test 6 failed\n");
        printf("Error in lastdigit function\n");
        printf("Expected last digit to be 9 but it was %d", lastdigit("twoeightnq6ninepxv"));
        return 0;
    };
    printf("Test 6 passed\n");

    printf("Tests complete\n");
    return 1;
}