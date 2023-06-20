#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int is_builtin_cmd(const char* cmd) {
  // TODO
  return strcmp(cmd, "alias") == 0 || strcmp(cmd, "exit") == 0;
}

int main(int argc, char** argv) {
  int pid = fork();
  // Q: where to deal with the built in command?
  if (pid == 0) {
    // Child
    char* args[] = {"ls", "-l", "-a", NULL};
    // what to do here
    execv("/bin/ls", args);
    // what to do here
    fprintf(stderr, "Child failed to execv!\n");
  } else if (pid > 0) {
    // Parent
    fprintf(stdout, "Parent will wait!\n");
    waitpid(pid, NULL, 0);
    fprintf(stdout, "Parent come back!\n");
  } else {
    // Error
  }
  return 0;
}
