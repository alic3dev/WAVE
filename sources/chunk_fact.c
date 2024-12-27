#include <stdlib.h>

#include "chunk_fact.h"

struct ChunkFact* new_chunk_fact() {
  static struct ChunkFact chunkFact;

  return &chunkFact;
}

unsigned char write_chunk_fact(struct ChunkFact* chunk_fact, FILE* output_file) {
  return 0;
}

void destroy_chunk_fact(struct ChunkFact* chunk_fact) {
  free(chunk_fact->ck_id);
  free(chunk_fact->cksize);
  free(chunk_fact->dw_sample_length);
  free(chunk_fact);
}

