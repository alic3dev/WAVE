#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "chunk_fact.h"
#include "constants.h"
#include "to_bytes.h"

struct chunk_fact* new_chunk_fact() {
  static struct chunk_fact chunk_fact;

  memcpy(
    chunk_fact.ck_id,
    "fact",
    CHUNK_FACT_CK_ID_LENGTH
  );

  memcpy(
    chunk_fact.cksize, 
    to_bytes_int(
      4,
      CHUNK_FACT_CKSIZE_LENGTH,
      CONSTANTS_LITTLE_ENDIAN
    ),
    CHUNK_FACT_CKSIZE_LENGTH
  );

  memcpy(
    chunk_fact.dw_sample_length,
    to_bytes_int(
      0, // TODO: Set this value in the future
      CHUNK_FACT_DW_SAMPLE_LENGTH_LENGTH,
      CONSTANTS_LITTLE_ENDIAN
    ),
    CHUNK_FACT_DW_SAMPLE_LENGTH_LENGTH
  );

  return &chunk_fact;
}

unsigned char write_chunk_fact(struct chunk_fact* chunk_fact, FILE* output_file) {
  size_t output_buffer_length = (
    CHUNK_FACT_CK_ID_LENGTH + 
    CHUNK_FACT_CKSIZE_LENGTH +
    CHUNK_FACT_DW_SAMPLE_LENGTH_LENGTH
  );

  char *output_buffer;
  output_buffer = malloc(output_buffer_length);
  size_t offset = 0;

  memcpy(
    output_buffer,
    chunk_fact->ck_id,
    CHUNK_FACT_CK_ID_LENGTH
  );
  offset += CHUNK_FACT_CK_ID_LENGTH;

  memcpy(
    output_buffer,
    chunk_fact->cksize,
    CHUNK_FACT_CKSIZE_LENGTH
  );
  offset += CHUNK_FACT_CKSIZE_LENGTH;

  memcpy(
    output_buffer,
    chunk_fact->dw_sample_length,
    CHUNK_FACT_DW_SAMPLE_LENGTH_LENGTH
  );

  size_t bytes_written = fwrite(
    output_buffer,
    sizeof(unsigned char),
    output_buffer_length,
    output_file
  );

  free(output_buffer);

  return bytes_written;
}

void destroy_chunk_fact(struct chunk_fact* chunk_fact) {}
