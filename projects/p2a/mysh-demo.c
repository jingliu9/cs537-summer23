#include <stdio.h>
#include "linkedlist.h"

struct lst* g_aliases;
// Q: How can we add alias
// match 'll' --> 'ls -l' -->

struct cmdline {
  int argc;
  char** argv;
  char* outfile;  // if outfile is NULL --> no redirection
};

void display_prompt() { fprintf(stdout, "mysh> "); }

void handle_interactive() {
  while (1) {
    display_prompt();
    // Read a line from stdin
    // Parse the line into a cmdline
    // --- if that is built-in
    // --- if that is an alias
    // --- how can we find the path of the command
    // fork and exec
    // Execute the cmdline
    // output
  }
}

int main(int argc, char** argv) {
  // Handle input
  if (argc == 2) {
    // Read from file
  } else if (argc == 1) {
    // Interactive mode
  } else {
    // ERROR
  }
  return 0;
}