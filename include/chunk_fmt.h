#ifndef __CHUNK_FMT_H
#define __CHUNK_FMT_H

#include <stdio.h>

#define CHUNK_FMT_CK_ID_LENGTH 4
#define CHUNK_FMT_CKSIZE_LENGTH 4
#define CHUNK_FMT_W_FORMAT_TAG_LENGTH 2
#define CHUNK_FMT_N_CHANNELS_LENGTH 2
#define CHUNK_FMT_N_SAMPLES_PER_SEC_LENGTH 4
#define CHUNK_FMT_N_AVG_BYTES_PER_SEC_LENGTH 4
#define CHUNK_FMT_N_BLOCK_ALIGN_LENGTH 2
#define CHUNK_FMT_W_BITS_PER_SAMPLE_LENGTH 2
#define CHUNK_FMT_CB_SIZE_LENGTH 2
#define CHUNK_FMT_W_VALID_BITS_PER_SAMPLE_LENGTH 2
#define CHUNK_FMT_DW_CHANNEL_MASK_LENGTH 4
#define CHUNK_FMT_SUB_FORMAT_LENGTH 16

struct chunk_fmt {
  char ck_id[CHUNK_FMT_CK_ID_LENGTH];
  char cksize[CHUNK_FMT_CKSIZE_LENGTH]; //  16, 18 or 40
  char w_format_tag[CHUNK_FMT_W_FORMAT_TAG_LENGTH];
  char n_channels[CHUNK_FMT_N_CHANNELS_LENGTH];
  char n_samples_per_sec[CHUNK_FMT_N_SAMPLES_PER_SEC_LENGTH];
  char n_avg_bytes_per_sec[CHUNK_FMT_N_AVG_BYTES_PER_SEC_LENGTH];
  char n_block_align[CHUNK_FMT_N_BLOCK_ALIGN_LENGTH];
  char w_bits_per_sample[CHUNK_FMT_W_BITS_PER_SAMPLE_LENGTH];
  char cb_size[CHUNK_FMT_CB_SIZE_LENGTH];
  char w_valid_bits_per_sample[CHUNK_FMT_W_VALID_BITS_PER_SAMPLE_LENGTH];
  char dw_channel_mask[CHUNK_FMT_DW_CHANNEL_MASK_LENGTH];
  char sub_format[CHUNK_FMT_SUB_FORMAT_LENGTH];
};

struct chunk_fmt* new_chunk_fmt();
unsigned char write_chunk_fmt(struct chunk_fmt*, FILE*);
void destroy_chunk_fmt(struct chunk_fmt*);

#endif

