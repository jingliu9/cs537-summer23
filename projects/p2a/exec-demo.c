#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char** argv) {
  // tokens of a command
  char *args[] = {"ls", "-l", "-R", "-a", NULL};
  execv("/bin/ls", args);
  return 0;
}
