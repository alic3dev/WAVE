#ifndef __GUID_H
#define __GUID_H

#include <stddef.h>

#define GUID_LENGTH 16

extern char* GUID_CHAR_SET;

char* generate_guid(size_t);

#endif

