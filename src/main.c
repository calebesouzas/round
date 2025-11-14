#include <stdio.h>
#include <sys/types.h>
// #include <stdlib.h>

// #include <string.h>

void usage_guide() {
    printf("Usage:\t[file]  [options] or\n\t[command] [options]");
}

int main(int argc, char *argv[]) {
    char version[] = "0.0.1-dev";
    FILE *p_round_file = fopen(argv[1], "r");
    char buffer[1024] = {0};
    if (p_round_file == NULL) {
	printf("Round Lang\tversion %s\n", version);
	return 0;
    }
    return 0;
}
