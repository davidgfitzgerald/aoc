#include <stdio.h>
#define MAX_LINE 1024


int main(void) {
    FILE *infile = fopen("input.txt", "r");
    if (infile == NULL)
    {
        perror("Error opening file");
        return 1;
    }    
}

