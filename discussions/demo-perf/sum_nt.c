#include <assert.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include "sum_def.h"

#define MAX_NT 20

int array[N];
long results[MAX_NT];
int num_threads;

void init() {
  srand(RAND_SEED);
  for (long i = 0; i < N; i++) {
    array[i] = rand() % 10;
  }
}

typedef struct {
  int start;
  int end;
} ThreadArg;

void* sum_array(void* arg) {
  ThreadArg* args = (ThreadArg*)arg;
  int start = args->start;
  int end = args->end;

  long sum = 0;
  for (int i = start; i < end; i++) {
    sum += array[i];
  }
  results[start / (N / num_threads)] = sum;

  return NULL;
}

long sum_array_nt() {
  int chunk_size = N / num_threads;
  pthread_t threads[MAX_NT];
  ThreadArg thread_args[MAX_NT];

  for (int i = 0; i < num_threads; i++) {
    thread_args[i].start = i * chunk_size;
    thread_args[i].end =
        (i == num_threads - 1) ? N : thread_args[i].start + chunk_size;
    pthread_create(&threads[i], NULL, sum_array, &thread_args[i]);
  }

  for (int i = 0; i < num_threads; i++) {
    pthread_join(threads[i], NULL);
  }

  int total_sum = 0;
  for (int i = 0; i < num_threads; i++) {
    total_sum += results[i];
  }
  return total_sum;
}

int main(int argc, char** argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage %s <num_threads>\n", argv[0]);
    return -1;
  }
  num_threads = atoi(argv[1]);
  assert(num_threads > 0);
  assert(num_threads <= MAX_NT);
  init();
  struct timeval t0, t1, dt;
  gettimeofday(&t0, NULL);
  long result = sum_array_nt();
  gettimeofday(&t1, NULL);
  timersub(&t1, &t0, &dt);
  fprintf(stdout, "%lu.%06lu s\n", dt.tv_sec, dt.tv_usec);
  fprintf(stdout, "sum:%ld\n", result);
  return 0;
}
