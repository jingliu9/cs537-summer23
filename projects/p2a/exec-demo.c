#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char** argv) {
  // tokens of a command
  char* args[] = {"/bin/ls", "-l", "-R", "-a", NULL};
  execv(args[0], args);
  return 0;
}
