// #include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function 'pato_regex_parse'
 * Param 'input' is the string to be used
 * Param 'pattern'  is the pattern to look for
 * Returns */
const char * pato_regex_parse(const char * input, const char * pattern) {
    char * matches;
    char * inputMemAlloc = (char *)malloc(sizeof(input) + 1); // +1 for NULL in case of failure
    if (inputMemAlloc != NULL) {
	for (int i = 0; i < strlen(input); i++) {
	    printf("%c", input[i]);
	}
    }
    if (input == pattern) {
	matches = (char *)input;
    } else {
	matches = "";
    }
    return matches;
}
