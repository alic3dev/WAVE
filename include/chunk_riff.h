#ifndef __CHUNK_RIFF_H
#define __CHUNK_RIFF_H


#define CHUNK_RIFF_CK_ID_LENGTH 4
#define CHUNK_RIFF_CKSIZE_LENGTH 4
#define CHUNK_RIFF_WAVE_ID_LENGTH 4

struct chunk_riff {
  char ck_id[CHUNK_RIFF_CK_ID_LENGTH];
  char cksize[CHUNK_RIFF_CKSIZE_LENGTH];
  char wave_id[CHUNK_RIFF_WAVE_ID_LENGTH];
};

struct chunk_riff* new_chunk_riff();
unsigned char write_chunk_riff(struct chunk_riff*, FILE*);
void destroy_chunk_riff(struct chunk_riff*);

#endif
