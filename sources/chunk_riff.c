#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "chunk_riff.h"
#include "to_bytes.h"

struct ChunkRiff* new_chunk_riff() {
  static struct ChunkRiff chunkRiff;
  memcpy(chunkRiff.ck_id, "RIFF", 4);

  size_t chunkLength = 0;
  memcpy(chunkRiff.cksize, to_bytes_int(chunkLength + 4, 4, 0), 4);

  memcpy(chunkRiff.wave_id, "WAVE", 4);

  return &chunkRiff;
}

unsigned char write_chunk_riff(struct ChunkRiff* chunk_riff, FILE* output_file) {
  return 0;
}

void destroy_chunk_riff(struct ChunkRiff* chunk_riff) {
  free(chunk_riff->ck_id);
  free(chunk_riff->cksize);
  free(chunk_riff->wave_id);
  free(chunk_riff);
}

