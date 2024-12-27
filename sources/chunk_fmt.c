#include <stdlib.h>
#include <string.h>

#include "chunk_fmt.h"
#include "wave_format.h"
#include "to_bytes.h"
#include "constants.h"
#include "guid.h"

struct ChunkFmt* new_chunk_fmt() {
  static struct ChunkFmt chunkFmt;
  memcpy(
      chunkFmt.ck_id, 
      "fmt ", 
      CHUNK_FMT_CK_ID_LENGTH
  );
  memcpy(
      chunkFmt.w_format_tag, 
      WAVE_FORMAT_PCM, 
      WAVE_FORMAT_CODE_LENGTH
  );
  memcpy(
      chunkFmt.n_channels, 
      to_bytes_int(2, CHUNK_FMT_N_CHANNELS_LENGTH, CONSTANTS_LITTLE_ENDIAN),
      CHUNK_FMT_N_CHANNELS_LENGTH
  );
  memcpy(
      chunkFmt.n_samples_per_sec, 
      to_bytes_int(44100, CHUNK_FMT_N_SAMPLES_PER_SEC_LENGTH, CONSTANTS_LITTLE_ENDIAN),
      CHUNK_FMT_N_SAMPLES_PER_SEC_LENGTH
  );
 
  // TODO: Figure out the proper values to set these to. Will worry about that later
  memcpy(
      chunkFmt.n_avg_bytes_per_sec,
      to_bytes_int(0, CHUNK_FMT_N_AVG_BYTES_PER_SEC_LENGTH, CONSTANTS_LITTLE_ENDIAN),
      CHUNK_FMT_N_AVG_BYTES_PER_SEC_LENGTH
  );
  memcpy(
      chunkFmt.n_block_align, 
      to_bytes_int(0, CHUNK_FMT_N_BLOCK_ALIGN_LENGTH, CONSTANTS_LITTLE_ENDIAN),
      CHUNK_FMT_N_BLOCK_ALIGN_LENGTH
  );
  memcpy(
      chunkFmt.w_bits_per_sample, 
      to_bytes_int(0, CHUNK_FMT_W_BITS_PER_SAMPLE_LENGTH, CONSTANTS_LITTLE_ENDIAN),
      CHUNK_FMT_W_BITS_PER_SAMPLE_LENGTH
  );
  memcpy(
      chunkFmt.cb_size,
      to_bytes_int(0, CHUNK_FMT_CB_SIZE_LENGTH, CONSTANTS_LITTLE_ENDIAN), /* 0 or 22 */
      CHUNK_FMT_CB_SIZE_LENGTH
  );
  memcpy(
      chunkFmt.w_valid_bits_per_sample,
      to_bytes_int(0, CHUNK_FMT_W_VALID_BITS_PER_SAMPLE_LENGTH, CONSTANTS_LITTLE_ENDIAN),
      CHUNK_FMT_W_VALID_BITS_PER_SAMPLE_LENGTH
  );
  memcpy(
      chunkFmt.dw_channel_mask,
      to_bytes_int(0, CHUNK_FMT_DW_CHANNEL_MASK_LENGTH, CONSTANTS_LITTLE_ENDIAN),
      CHUNK_FMT_DW_CHANNEL_MASK_LENGTH
  );
  memcpy(
      chunkFmt.sub_format,
      generate_guid(CHUNK_FMT_SUB_FORMAT_LENGTH),
      CHUNK_FMT_SUB_FORMAT_LENGTH
  );

  return &chunkFmt;
}

unsigned char write_chunk_fmt(struct ChunkFmt* chunk_fmt, FILE* output_file) {
  size_t output_buffer_size = (
      CHUNK_FMT_CK_ID_LENGTH +
      CHUNK_FMT_CKSIZE_LENGTH +
      CHUNK_FMT_W_FORMAT_TAG_LENGTH +
      CHUNK_FMT_N_CHANNELS_LENGTH +
      CHUNK_FMT_N_SAMPLES_PER_SEC_LENGTH +
      CHUNK_FMT_N_AVG_BYTES_PER_SEC_LENGTH +
      CHUNK_FMT_N_BLOCK_ALIGN_LENGTH +
      CHUNK_FMT_W_BITS_PER_SAMPLE_LENGTH +
      CHUNK_FMT_CB_SIZE_LENGTH +
      CHUNK_FMT_W_VALID_BITS_PER_SAMPLE_LENGTH +
      CHUNK_FMT_DW_CHANNEL_MASK_LENGTH +
      CHUNK_FMT_SUB_FORMAT_LENGTH + 
      1
  );

  static char *output_buffer;
  output_buffer = malloc(output_buffer_size);

  for (size_t i = 0; i < output_buffer_size - 1; i++) {
    output_buffer[i] = (rand() % 8) + 1;
  }

  // TODO: NULL values are gonna be weird to use here, think about this later
  //       Probably just find a function which accepts a length value *shrugs*

  output_buffer[output_buffer_size - 1] = '\0';
  fprintf(output_file, "%s", output_buffer);

  free(output_buffer);

  return 0;
}

void destroy_chunk_fmt(struct ChunkFmt* chunk_fmt) {
  free(chunk_fmt->ck_id);
  free(chunk_fmt->cksize);
  free(chunk_fmt->w_format_tag);
  free(chunk_fmt->n_channels);
  free(chunk_fmt->n_samples_per_sec);
  free(chunk_fmt->n_avg_bytes_per_sec);
  free(chunk_fmt->n_block_align);
  free(chunk_fmt->w_bits_per_sample);
  free(chunk_fmt->cb_size);
  free(chunk_fmt->w_valid_bits_per_sample);
  free(chunk_fmt->dw_channel_mask);
  free(chunk_fmt->sub_format);
  free(chunk_fmt);
}

