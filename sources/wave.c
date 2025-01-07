#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <sys/time.h>

#include "wave.h"
#include "print_usage.h"

#include "chunk_data.h"
#include "chunk_fact.h"
#include "chunk_fmt.h"
#include "chunk_riff.h"

enum DATA_TYPE { PCM, NON_PCM, EXTENSIBLE };

int main(int argc, char* argv[]) {
  if (argc != 2) {
    print_usage();
    return 1;
  }

  struct timeval time_val;
  gettimeofday(&time_val, NULL);
  unsigned long long micro_time = (time_val.tv_sec * 1000000) + time_val.tv_usec;
  srand(micro_time);

  enum DATA_TYPE data_type = PCM;

  FILE *output_file;
  output_file = fopen(argv[1], "wb");

  struct chunk_riff* chunk_riff = new_chunk_riff();
  struct chunk_fmt* chunk_fmt = new_chunk_fmt();
  struct chunk_data* chunk_data = new_chunk_data();
  struct chunk_fact* chunk_fact = NULL;
  if (data_type != PCM) {
    chunk_fact = new_chunk_fact();
  }

  write_chunk_riff(chunk_riff, output_file);
  write_chunk_fmt(chunk_fmt, output_file);
  if (chunk_fact != NULL) {
    write_chunk_fact(chunk_fact, output_file);
  }
  write_chunk_data(chunk_data, output_file);
  
  fclose(output_file);

  destroy_chunk_riff(chunk_riff);
  destroy_chunk_fmt(chunk_fmt);
  if (chunk_fact != NULL) {
    destroy_chunk_fact(chunk_fact);
  }
  destroy_chunk_data(chunk_data);

  return 0;
}

