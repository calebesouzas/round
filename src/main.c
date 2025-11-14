#include <stdio.h>
#include <string.h>
#include "help.h"

int main(int argc, char *argv[]) {
    char version[] = "0.0.1-dev";
    FILE *p_round_file = fopen(argv[1], "r");
    char buffer[1024] = {0};

    if (p_round_file == NULL) {
	if (argc == 1) {
	    printf("Round Lang\tversion %s\n", version);
	    return 0;
	} else if (strncmp(argv[1], "help", 4) == 0) {
	    usage_guide();
	    return 0;
	}
	// else:
	printf("Could not open file%s\n", argv[1]);
	return 0;
    }

    while (fgets(buffer, sizeof(buffer), p_round_file) != NULL) {
	printf("%s", buffer);
    }
    fclose(p_round_file);
    return 0;
}
