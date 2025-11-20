#include <stdio.h>
// #include <string.h>
#include "pato.h"
#include "usage_guides.h"
#include "parser/parser.h"
#include "regex/pato_re.h"

void get_pato_project_config() {
    pato_file_t project_file;
    project_file.name = ".patox";
    project_file.pointer = fopen(project_file.name, "r");
    char buffer[1024] = {0};
    if (project_file.pointer != NULL) {
        pato_parse(buffer, sizeof(buffer), project_file);
    } else {
	printf("Couldn't find '.patox' file\n");
	printf("Be sure that you're in the root directory of your project.\n");
	printf("Or specify the '-p' option pointing to it\n");
    }
}


int main(int argc, char *argv[]) {
    char version[] = "0.0.1-dev";
    FILE *p_pato_file = fopen(argv[1], "r");

    char buffer[1024] = {0};
    /* Here we check if the first argument for the program
     * is a file, else we'll check if it's a command. */
    if (p_pato_file == NULL) {
	if (argc == 1) {
	    printf("Pato Lang\tversion %s\n", version);
	    return 0;
	} else {
	    /* Handling commands. Those are:
	    * help
	    * run
	    * build
	    * new
	    * compile
	    * By the way, we can use the first character as an alias 
	    * */
	    switch (argv[1][0]) {
		case 'h': 
		    print_usage_guide();
		    break;
		case 'r':
		    get_pato_project_config();
		    break;
		case 't':
		    printf("%s\n", pato_regex_parse("test 1 3 8 3 ifkdboej", "test"));
		    break;

		default:
		    printf("The command '%s' is not a valid command\n", argv[1]);
	    }
	    return 0;
	}
	// else:
	printf("Could not open file%s\n", argv[1]);
	return 0;
    }

    while (fgets(buffer, sizeof(buffer), p_pato_file) != NULL) {
	printf("%s", buffer);
    }
    fclose(p_pato_file);
    return 0;
}
