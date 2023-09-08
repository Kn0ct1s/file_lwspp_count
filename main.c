#include <stdio.h>
#include <stdlib.h>

#include "file_handling.h"


int main(int argc, char** argv) {
    // // make sure the user supplys a the minimum number of args
    // if (argc < 2) {
    //     fprintf(stderr, "Usage: lwspp -filename- -tag(optional)");

    //     // exit
    //     exit(1);
    // }

    FILE* file = open_file("test.txt");
    //int lc = line_count(file);
    int wc = word_count(file);

    //printf("%i", lc);
    
   printf("\n%i", wc);
}