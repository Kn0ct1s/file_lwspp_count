#include <stdio.h>
#include <stdlib.h>

#include "file_handling.h"


int main(int argc, char** argv) {
    // // make sure the user supplys a the minimum number of args
    // if (argc < 2) {
    //     fprintf(stderr, "Usage: lwspp -filename-");

    //     // exit
    //     exit(1);
    // }
    // function pointers
    int (*funcs[4]) (FILE* file) = {line_count, word_count, 
                para_count, punc_count};

    for (int i = 0; i < 4; i++) {
        FILE* f = open_file("test.txt");
        int num = funcs[i](f);
        printf("%i\n", num);
    }
}