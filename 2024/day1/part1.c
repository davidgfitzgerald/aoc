#include <stdio.h>


int main(void) {
    printf("part1.c main ran\n");

    FILE *infile = fopen("input.txt", "r");
    if (infile == NULL)
    {
        perror("Error opening file");
        return 1;
    }    
}

int add(int num1, int num2) {
    return num1 + num2;
}