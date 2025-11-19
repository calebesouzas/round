// #include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

const char * pato_regex_parse(const char * _str) {
    char * str = (char *)malloc(sizeof(_str) + 1);
    for (int i = 0; i < sizeof(str); i++) {
	printf("Character is at %c", str[i]);
    }
    return "";
}
