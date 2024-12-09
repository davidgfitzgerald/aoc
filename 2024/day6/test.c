#include <stdio.h>
#include <string.h>
#include "lib.h"


void assert(int statement) {
    if (statement) {printf("Pass!\n");} else {printf("FAIL!\n");}
}


void test_first_line_is_expected(char** matrix) {
    char* row1 = *matrix;
    assert(strcmp(row1, ".#.") == 0);
}


void test_first_char_in_first_line_is_expected(char** matrix) {
    char* row1 = *matrix;
    assert(row1[0] == '.');
}


void test_second_char_in_first_line_is_expected(char** matrix) {
    char* row1 = *matrix;
    assert(row1[1] == '#');
}

void matrix_tests(FILE *test_txt) {
    char **matrix = read(test_txt);

    test_first_line_is_expected(matrix);
    test_first_char_in_first_line_is_expected(matrix);
    test_second_char_in_first_line_is_expected(matrix);
}

void test_length() {
    assert(length(".#.") == 3);
    assert(length("hello") == 5);
}


int main() {
    FILE *test_txt = fopen("test.txt", "r");

    // test_length();
    // read(test_txt);

    // matrix_tests(test_txt);
}