#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// this is how many characters we read in
#define BUFFER 50

FILE* open_file(const char* file_name) {
    FILE* file;

    // if its null the file does not exist
    if ((file = (FILE*) fopen(file_name, "r")) == NULL) {
        fprintf(stderr, "The file -%s- does not exist, or cannot be opened.\n", 
        file_name);

        // exit the program
        exit(1);
    } else {
        // otherwise return the file
        return file;
    }
}

int line_count(FILE* file) {
    // this is where we will store the characters as we read them
    char contents[BUFFER];

    // this keeps track of haw many lines
    // starts at 1 as there is always 1 line
    int lc = 1;

    // read through the whole file
    while (fgets(contents, BUFFER, file)) {
        for (int x = 0; x < BUFFER; x++) {
            // check if you encounter a new line
            if (contents[x] == '\n') {
                // if you do add 1 to the count
                lc++;
            }
        }
    }
    // there is always a extra new line
    lc--;
    
    return lc;
}

int word_count(FILE* file) {
    char contents[BUFFER];

    // things that differntiate between words
    char nonwords[] = " \n";

    // keeps track of words
    int wc = 0;

    while (fgets(contents, BUFFER, file)) {
        for (int i = 0; i < BUFFER; i++) {
            if (contents[i] == '\000') {
                break;
            }
            else if (contents[i] == ' ' && contents[i + 1] != ' ' || contents[i] == '\n') {
                wc++;
            }
        }
    }
    // doesnt count the last word so add one
    wc++;

    return wc;
}