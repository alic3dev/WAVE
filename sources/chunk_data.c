#include <stdlib.h>
#include <string.h>

#include "chunk_data.h"

struct ChunkData* new_chunk_data() {
  static struct ChunkData chunk_data;
  memcpy(chunk_data.ck_id, "data", 4);

  size_t sample_length = 0;
  chunk_data.pad_byte = sample_length % 2 == 0 ? 0 : 1;

  return &chunk_data;
}

unsigned char write_chunk_data(struct ChunkData* chunk_data, FILE* output_file) {
  return 0;
}

void destroy_chunk_data(struct ChunkData* chunk_data) {
  free(chunk_data->ck_id);
  free(chunk_data->cksize);
  free(chunk_data->sampled_data);
  free(chunk_data);
}

