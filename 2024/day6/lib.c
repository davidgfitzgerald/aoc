#include <stdio.h>
#include <stdlib.h>
#define MAX_LINE 1024


void validate_args(int argc, char* argv[]) {
    char* msg = "Run make ARGS=/path/to/file.txt\n";
    switch (argc) {
        case 1:
            printf("Missing input file arg.\n%s", msg);
            exit(1);
        case 2:
            break;
        default:
        printf("Too many args passed.\n%s", msg);
    }
}


char** read() {
    static char *matrix[] = {
        ".#.",
        "..#",
        ".#.",
    };

    return matrix;
}

    // while (fgets(line, MAX_LINE, infile) != NULL) {
    //     printf("%s", line);
    // };