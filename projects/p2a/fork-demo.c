#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char **argv) {
  fprintf(stdout, "hello from:%d\n", getpid());
  int pid = fork();
  fprintf(stdout, "[%d:pid=%d]\t:)\n", pid, getpid());
  fork();
  fprintf(stdout, "[%d:pid=%d]\t:):):)\n", pid, getpid());
  return 0;
}
