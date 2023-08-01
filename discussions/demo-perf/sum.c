#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include "sum_def.h"

int array[N];

void init() {
  srand(RAND_SEED);
  for (long i = 0; i < N; i++) {
    array[i] = rand() % 10;
  }
}

long sum_array() {
  long result = 0;
  for (long i = 0; i < N; i++) {
    result += array[i];
  }
  return result;
}

int main() {
  init();
  struct timeval t0, t1, dt;
  gettimeofday(&t0, NULL);
  long result = sum_array();
  gettimeofday(&t1, NULL);
  timersub(&t1, &t0, &dt);
  fprintf(stdout, "%lu.%06lu s\n", dt.tv_sec, dt.tv_usec);
  fprintf(stdout, "result:%ld\n", result);
  return 0;
}
