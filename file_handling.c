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
    // this is where all the characters will be stored
    char contents[BUFFER];

    // there will always be 1 line
    int lc = 0;

    while (fgets(contents, BUFFER, file)) {
        // for loop to go through each character
        for (int i = 0; i < BUFFER; i++) {
            // check if its an empty line
            if (i == 0 && contents[i] == '\n') {
                lc++;
                break;
            }

            // check if its a new line
            if (contents[i] == '\n') {
                lc++;
                break;
            }
        }
    }
    // always misses the last line
    return ++lc;
}

int word_count(FILE* file) {
    char contents[BUFFER];

    // holds the number of words
    int wc = 0;

    while (fgets(contents, BUFFER, file)) {
        for (int i = 0; i < BUFFER; i++) {
            if (i == 0 && contents[i] == '\n') {
                break;
            }

            if (contents[i] == ' ' && contents[i + 1] != ' ' || contents[i] == '\n') {
                wc++;
            }
        }
    }
    // doesnt count the last word
    return ++wc;
}


int para_count(FILE* file) {
    char contents[BUFFER];

    int para_count = 0;
    
    while (fgets(contents, BUFFER, file)) {
        for (int i = 0; i < BUFFER; i++) {
            if (i == 0 && contents[i] == '\n') {
                break;
            }

            if (contents[i] == '\n' && contents[i + 1] == '\000') {
                para_count++;
                break;
            }
        }
    }

    // doesnt count the last paragraph so add 1
    return ++para_count;
}

int punc_count(FILE* file) {
    char contents[BUFFER];

    int punc_count = 0;

    while (fgets(contents, BUFFER, file)) {

        for (int i = 0; i < BUFFER; i++) {
            switch (contents[i]) {
                case '.': case ',': case '?':
                case '!': case ';': case ':':
                    punc_count++;
            }
        }
    }
    return punc_count;
}