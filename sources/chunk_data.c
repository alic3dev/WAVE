#include <stdlib.h>
#include <string.h>

#include "chunk_data.h"

struct ChunkData* new_chunk_data() {
  static struct ChunkData chunk_data;
  memcpy(chunk_data.ck_id, "data", CHUNK_DATA_CK_ID_LENGTH);

  chunk_data.sampled_data = malloc(chunk_data.sampled_data_length);

  size_t sample_length = 0;
  chunk_data.pad_byte = sample_length % 2 == 0 ? 0 : 1;

  return &chunk_data;
}

unsigned char write_chunk_data(struct ChunkData* chunk_data, FILE* output_file) {
  size_t output_buffer_length = (
      CHUNK_DATA_CK_ID_LENGTH +
      CHUNK_DATA_CKSIZE_LENGTH +
      chunk_data->sampled_data_length +
      sizeof(char) // For chunk_data->pad_byte
  );

  unsigned char *output_buffer;
  output_buffer = malloc(output_buffer_length);

  size_t offset = 0;
  memcpy(output_buffer + offset, chunk_data->ck_id, CHUNK_DATA_CK_ID_LENGTH);
  offset += CHUNK_DATA_CK_ID_LENGTH;
  memcpy(output_buffer + offset, chunk_data->cksize, CHUNK_DATA_CKSIZE_LENGTH);
  offset += CHUNK_DATA_CKSIZE_LENGTH;
  memcpy(output_buffer + offset, chunk_data->sampled_data, chunk_data->sampled_data_length);
  offset += chunk_data->sampled_data_length;
  output_buffer[offset] = chunk_data->pad_byte;

  size_t bytes_written = fwrite(output_buffer, sizeof(unsigned char), output_buffer_length, output_file);
  free(output_buffer);

  return bytes_written;
}

void destroy_chunk_data(struct ChunkData* chunk_data) {
  free(chunk_data->sampled_data);
}

