#ifndef PARSER_H
#define PARSER_H
#include <stdio.h>
typedef struct {
    FILE * pointer;
    char * name;
} pato_file_t;

void pato_parse(const char * buffer, int buffer_size, pato_file_t file_to_parse);

#endif
