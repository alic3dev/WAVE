#include <stddef.h>
#include <stdlib.h>

#include "to_bytes.h"

char* to_bytes_int(int integer, size_t length, unsigned char little_endian) {
  char *bytes;
  bytes = malloc(length);

  size_t index = little_endian == 1 ? 0 : length - 1;
  do {
    if (integer > 255) {
      bytes[index] = (char) 255;
      integer -= 255;
    } else {
      bytes[index] = (char) integer;
      integer = 0;
    }

    if (little_endian == 1) {
      index++;
    } else {
      index--;
    }
  } while (integer > 0 && index < length && index > 0);

  return bytes;
}

