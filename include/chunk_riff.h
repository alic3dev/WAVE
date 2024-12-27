#ifndef __CHUNK_RIFF_H
#define __CHUNK_RIFF_H


#define CHUNK_RIFF_CK_ID_LENGTH 4
#define CHUNK_RIFF_CKSIZE_LENGTH 4
#define CHUNK_RIFF_WAVEID_LENGTH 4

struct ChunkRiff {
  char ck_id[CHUNK_RIFF_CK_ID_LENGTH];
  char cksize[CHUNK_RIFF_CKSIZE_LENGTH];
  char wave_id[CHUNK_RIFF_WAVEID_LENGTH];
};

struct ChunkRiff* new_chunk_riff();
unsigned char write_chunk_riff(struct ChunkRiff*, FILE*);
void destroy_chunk_riff(struct ChunkRiff*);

#endif

