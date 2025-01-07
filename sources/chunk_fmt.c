#include <stdlib.h>
#include <string.h>

#include "chunk_fmt.h"
#include "wave_format.h"
#include "to_bytes.h"
#include "constants.h"
#include "guid.h"

struct chunk_fmt* new_chunk_fmt() {
  static struct chunk_fmt chunk_fmt;

  memcpy(
    chunk_fmt.ck_id, 
    "fmt ", 
    CHUNK_FMT_CK_ID_LENGTH
  );

  memcpy(
    chunk_fmt.cksize,
    to_bytes_int(
      16,
      CHUNK_FMT_CKSIZE_LENGTH,
      CONSTANTS_LITTLE_ENDIAN
    ),
    CHUNK_FMT_CKSIZE_LENGTH
  );

  memcpy(
    chunk_fmt.w_format_tag, 
    WAVE_FORMAT_PCM, 
    WAVE_FORMAT_CODE_LENGTH
  );

  memcpy(
    chunk_fmt.n_channels, 
    to_bytes_int(
      2,
      CHUNK_FMT_N_CHANNELS_LENGTH,
      CONSTANTS_LITTLE_ENDIAN
    ),
    CHUNK_FMT_N_CHANNELS_LENGTH
  );

  memcpy(
    chunk_fmt.n_samples_per_sec, 
    to_bytes_int(
      44100,
      CHUNK_FMT_N_SAMPLES_PER_SEC_LENGTH,
      CONSTANTS_LITTLE_ENDIAN
    ),
    CHUNK_FMT_N_SAMPLES_PER_SEC_LENGTH
  );

  // TODO: Figure out the proper values to set these to. Will worry about that later
  memcpy(
    chunk_fmt.n_avg_bytes_per_sec,
    to_bytes_int(
      0,
      CHUNK_FMT_N_AVG_BYTES_PER_SEC_LENGTH,
      CONSTANTS_LITTLE_ENDIAN
    ),
    CHUNK_FMT_N_AVG_BYTES_PER_SEC_LENGTH
  );

  memcpy(
    chunk_fmt.n_block_align, 
    to_bytes_int(
      0,
      CHUNK_FMT_N_BLOCK_ALIGN_LENGTH,
      CONSTANTS_LITTLE_ENDIAN
    ),
    CHUNK_FMT_N_BLOCK_ALIGN_LENGTH
  );

  memcpy(
    chunk_fmt.w_bits_per_sample, 
    to_bytes_int(
      0,
      CHUNK_FMT_W_BITS_PER_SAMPLE_LENGTH,
      CONSTANTS_LITTLE_ENDIAN
    ),
    CHUNK_FMT_W_BITS_PER_SAMPLE_LENGTH
  );

  memcpy(
    chunk_fmt.cb_size,
    to_bytes_int(
      0,
      CHUNK_FMT_CB_SIZE_LENGTH,
      CONSTANTS_LITTLE_ENDIAN
    ), /* 0 or 22 */
    CHUNK_FMT_CB_SIZE_LENGTH
  );

  memcpy(
    chunk_fmt.w_valid_bits_per_sample,
    to_bytes_int(
      0,
      CHUNK_FMT_W_VALID_BITS_PER_SAMPLE_LENGTH,
      CONSTANTS_LITTLE_ENDIAN
    ),
    CHUNK_FMT_W_VALID_BITS_PER_SAMPLE_LENGTH
  );

  memcpy(
    chunk_fmt.dw_channel_mask,
    to_bytes_int(
      0,
      CHUNK_FMT_DW_CHANNEL_MASK_LENGTH,
      CONSTANTS_LITTLE_ENDIAN
    ),
    CHUNK_FMT_DW_CHANNEL_MASK_LENGTH
  );

  memcpy(
    chunk_fmt.sub_format,
    generate_guid(CHUNK_FMT_SUB_FORMAT_LENGTH),
    CHUNK_FMT_SUB_FORMAT_LENGTH
  );

  return &chunk_fmt;
}

unsigned char write_chunk_fmt(struct chunk_fmt* chunk_fmt, FILE* output_file) {
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
    CHUNK_FMT_SUB_FORMAT_LENGTH
  );

  char *output_buffer;
  output_buffer = malloc(output_buffer_size);

  size_t offset = 0;
  memcpy(
    output_buffer + offset,
    chunk_fmt->ck_id,
    CHUNK_FMT_CK_ID_LENGTH
  );
  offset += CHUNK_FMT_CK_ID_LENGTH;

  memcpy(
    output_buffer + offset,
    chunk_fmt->cksize,
    CHUNK_FMT_CKSIZE_LENGTH
  );
  offset += CHUNK_FMT_CKSIZE_LENGTH;

  memcpy(
    output_buffer + offset,
    chunk_fmt->w_format_tag,
    CHUNK_FMT_W_FORMAT_TAG_LENGTH
  );
  offset += CHUNK_FMT_W_FORMAT_TAG_LENGTH;

  memcpy(
    output_buffer + offset,
    chunk_fmt->n_channels,
    CHUNK_FMT_N_CHANNELS_LENGTH
  );
  offset += CHUNK_FMT_N_CHANNELS_LENGTH;

  memcpy(
    output_buffer + offset,
    chunk_fmt->n_samples_per_sec,
    CHUNK_FMT_N_SAMPLES_PER_SEC_LENGTH
  );
  offset += CHUNK_FMT_N_SAMPLES_PER_SEC_LENGTH;

  memcpy(
    output_buffer + offset,
    chunk_fmt->n_avg_bytes_per_sec,
    CHUNK_FMT_N_AVG_BYTES_PER_SEC_LENGTH
  );
  offset += CHUNK_FMT_N_AVG_BYTES_PER_SEC_LENGTH;

  memcpy(
    output_buffer + offset,
    chunk_fmt->n_block_align,
    CHUNK_FMT_N_BLOCK_ALIGN_LENGTH
  );
  offset += CHUNK_FMT_N_BLOCK_ALIGN_LENGTH;

  memcpy(
    output_buffer + offset,
    chunk_fmt->w_bits_per_sample,
    CHUNK_FMT_W_BITS_PER_SAMPLE_LENGTH
  );
  offset += CHUNK_FMT_W_BITS_PER_SAMPLE_LENGTH;

  memcpy(
    output_buffer + offset,
    chunk_fmt->cb_size,
    CHUNK_FMT_CB_SIZE_LENGTH
  );
  offset += CHUNK_FMT_CB_SIZE_LENGTH;

  memcpy(
    output_buffer + offset,
    chunk_fmt->w_valid_bits_per_sample,
    CHUNK_FMT_W_VALID_BITS_PER_SAMPLE_LENGTH
  );
  offset += CHUNK_FMT_W_VALID_BITS_PER_SAMPLE_LENGTH;

  memcpy(
    output_buffer + offset,
    chunk_fmt->dw_channel_mask,
    CHUNK_FMT_DW_CHANNEL_MASK_LENGTH
  );
  offset += CHUNK_FMT_DW_CHANNEL_MASK_LENGTH;

  memcpy(
    output_buffer + offset,
    chunk_fmt->sub_format,
    CHUNK_FMT_SUB_FORMAT_LENGTH
  );

  size_t bytes_written = fwrite(
    output_buffer,
    sizeof(unsigned char),
    output_buffer_size,
    output_file
  );
 
  free(output_buffer);

  return bytes_written;
}

void destroy_chunk_fmt(struct chunk_fmt* chunk_fmt) {}
