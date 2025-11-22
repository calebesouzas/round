#include <stdio.h>

void print_usage_guide() {
  /* Prints every single command, their usage guide
   * and options. No examples for now
   * At the momment it doesn't support 'help'
   * for each different command
   * but it will, then, you run 'pato help {command}' */
  printf("Usage:\t[file]  [options] or\n\t[command] [options]\n\n");
  printf("-- COMMANDS --\n");
  // Explaination for 'run'
  printf("run\t\tWill run the file specified by 'entry_point' in '.patox' file.");
  printf("\n\t\tDefault 'entry_point' is 'main.pato' even with no patox file\n");
}
