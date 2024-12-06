#include <stdio.h>
#include "lib.h"


int main(int argc, char* argv[]) {
    validate_args(argc, argv);

    char* filepath = argv[1];
    FILE* infile = fopen(filepath, "r");
    read(infile);
}