#ifndef __CHUNK_DATA_H
#define __CHUNK_DATA_H

#include <stdio.h>

#define CHUNK_DATA_CK_ID_LENGTH 4
#define CHUNK_DATA_CKSIZE_LENGTH 4

struct ChunkData {
  char ck_id[CHUNK_DATA_CK_ID_LENGTH];
  char cksize[CHUNK_DATA_CKSIZE_LENGTH];
  char* sampled_data;
  size_t sampled_data_length;
  char pad_byte;
};

struct ChunkData* new_chunk_data();
unsigned char write_chunk_data(struct ChunkData*, FILE *);
void destroy_chunk_data(struct ChunkData*);

#endif

