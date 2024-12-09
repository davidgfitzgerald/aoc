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

int length(char* str) {
    // Return length of a string

    int count = 0;
    char *ptr = str;
    while (*ptr != '\0') {
        ptr++;
        count++;
    }
    return count;
}

typedef struct
{
    int height;
    int width;
}  FileSize;


FileSize get_file_size(FILE *infile) {
    /**
     * Get the height and width of a file
     */
    // Store the height and width in a struct.
    FileSize fs;
    fs.height = 0;
    fs.width = 0;

    char c;  // c stores current character read

    // Iterate every character in the file
    // and determine the width and height of the file.
    // We assume that line length is homogenous.
    for (int i=0; (c = fgetc(infile)); i++) {
        if (c == '\n') {
            fs.height++;
            if (fs.width == 0) {
                fs.width = i;
            }
        }
        if (c == EOF) {
            break;
        }
    }
    return fs;
}




char** read(FILE *infile) {
    /**
     * Read a file into memory
     */
    FileSize fs = get_file_size(infile);

    char** grid = (char**)malloc(fs.height * sizeof(char*));

    return grid;


}

