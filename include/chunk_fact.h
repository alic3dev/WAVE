#ifndef __CHUNK_FACT_H
#define __CHUNK_FACT_H

#include <stdio.h>

#define CHUNK_FACT_CK_ID_LENGTH 4
#define CHUNK_FACT_CKSIZE_LENGTH 4
#define CHUNK_FACT_DW_SAMPLE_LENGTH_LENGTH 4

struct chunk_fact {
  char ck_id[CHUNK_FACT_CK_ID_LENGTH];
  char cksize[CHUNK_FACT_CKSIZE_LENGTH]; // minimum 4
  char dw_sample_length[CHUNK_FACT_DW_SAMPLE_LENGTH_LENGTH];
};

struct chunk_fact* new_chunk_fact();
unsigned char write_chunk_fact(struct chunk_fact*, FILE*);
void destroy_chunk_fact(struct chunk_fact*);

#endif

