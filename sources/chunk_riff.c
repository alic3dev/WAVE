#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "chunk_riff.h"
#include "to_bytes.h"

struct chunk_riff* new_chunk_riff() {
  static struct chunk_riff chunk_riff;

  memcpy(
    chunk_riff.ck_id,
    "RIFF",
    4
  );

  size_t chunkLength = 0;
  memcpy(
    chunk_riff.cksize,
    to_bytes_int(
      chunkLength + 4, 
      CHUNK_RIFF_CKSIZE_LENGTH, 
      0
    ),
    CHUNK_RIFF_CKSIZE_LENGTH
  );

  memcpy(chunk_riff.wave_id, "WAVE", 4);

  return &chunk_riff;
}

unsigned char write_chunk_riff(struct chunk_riff* chunk_riff, FILE* output_file) {
  size_t output_buffer_length = (
    CHUNK_RIFF_CK_ID_LENGTH +
    CHUNK_RIFF_CKSIZE_LENGTH +
    CHUNK_RIFF_WAVE_ID_LENGTH
  );

  unsigned char* output_buffer;
  output_buffer = malloc(output_buffer_length);
  size_t offset = 0;

  memcpy(
    output_buffer + offset,
    chunk_riff->ck_id,
    CHUNK_RIFF_CK_ID_LENGTH
  );
  offset += CHUNK_RIFF_CK_ID_LENGTH;

  memcpy(
    output_buffer + offset,
    chunk_riff->cksize,
    CHUNK_RIFF_CKSIZE_LENGTH
  );
  offset += CHUNK_RIFF_CKSIZE_LENGTH;

  memcpy(
    output_buffer + offset,
    chunk_riff->wave_id,
    CHUNK_RIFF_WAVE_ID_LENGTH
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

void destroy_chunk_riff(struct chunk_riff* chunk_riff) {}
