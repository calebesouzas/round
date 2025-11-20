#ifndef PATO_H
#define PATO_H
#include <stdio.h>
#include <stdbool.h>

typedef struct {
    FILE * pointer;
    char * name;
} pato_file_t;

typedef struct {
    bool always_compile;
    char root_dir[4096];
    char project_name[64];
} pato_config_t;

#endif
