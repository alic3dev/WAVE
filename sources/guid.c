#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "guid.h"

char* GUID_CHAR_SET = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

char* generate_guid(size_t length) {
  if (!length) {
    length = GUID_LENGTH;
  }

  static char guid[GUID_LENGTH];
  size_t guid_char_set_length = strlen(GUID_CHAR_SET);

  for (size_t i = 0; i < length; i++) {
    if (i == 6 || i == 9 || i == 11 || i == 13) {
      guid[i] = '-';
    }

    guid[i] = GUID_CHAR_SET[rand() % guid_char_set_length];
  }

  return guid;
}
