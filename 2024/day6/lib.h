#include <stdio.h>
#include <stdlib.h>
#define MAX_LINE 1024


void validate_args(int argc, char *argv[]);
int length(char* str);
char** read(FILE *file);