#ifndef FILE_HANDLING_H
#define FILE_HANDLING_H
    #include <stdio.h>

    FILE* open_file(const char* file_name);

    int line_count(FILE* file);
    int word_count(FILE* file);
    int para_count(FILE* file);
    int punc_count(FILE* file);

#endif