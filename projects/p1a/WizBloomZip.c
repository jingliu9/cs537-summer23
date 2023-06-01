#include <assert.h>
#include <bloom.h>
#include <getopt.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <zstd.h>

/*
 *  WizBloomZip.c
 *  -f <file> -o [output] -b [bloom_filter] -k [key]
 */

#define MAX_FILE_LINE_LEN 256

// Global variables
char *g_file_name = NULL;
char *g_output = NULL;
char *g_bloom_file = NULL;
char *g_key = NULL;

// Bloom filter parameters
int g_bloom_entries = 1000000;
float g_bloom_error = 0.01;

void print_usage() {
  printf(
      "Usage: WizBloomZip -f <file> -o [output] -b [bloom_filter] -k [key]\n");
  printf("  -f <file>          Input file\n");
  printf("  -o [output]        Output file\n");
  printf("  -b [bloom_filter]  Bloom filter file\n");
  printf("  -k [key]           Key\n");
}

void compress_one_file(const char *file_name) {
  // TODO
}

void print_key_position(FILE *stream, const char *key, int64_t pos) {
  if (pos < 0) {
    fprintf(stdout, "Key %s not found\n", key);
    return;
  }
  fprintf(stdout, "Key %s found at line %ld\n", key, pos);
}

void query_one_key(const char *fname, const char *key) {
  // TODO
}

int main(int argc, char *argv[]) {
  int opt;
  // parse command line arguments
  while ((opt = getopt(argc, argv, "f:o:b:k:")) != -1) {
    switch (opt) {
      case 'f':
        // input file
        g_file_name = optarg;
        break;
      case 'o':
        // output file
        g_output = optarg;
        break;
      case 'b':
        // bloom filter file
        g_bloom_file = optarg;
        break;
      case 'k':
        // key
        g_key = optarg;
        break;
      default:
        // print usage
        print_usage();
        exit(EXIT_FAILURE);
        break;
    }
  }

  if (g_file_name) {
    if (g_key) {
      // query instead of compressing
      if (g_bloom_file) {
        query_one_key(g_file_name, g_key);
      }
    } else {
      assert(g_output);
      compress_one_file(g_file_name);
    }
  } else {
    print_usage();
    exit(EXIT_FAILURE);
  }

  return 0;
}
