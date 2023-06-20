#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv) {
  // fprintf(stdout,...);
  write(STDOUT_FILENO, "Hello, world!\n", 14);
  // sleep(3);
  // fprintf(stderr,...);
  write(STDERR_FILENO, "Hello, error!\n", 14);
  return 0;
}
