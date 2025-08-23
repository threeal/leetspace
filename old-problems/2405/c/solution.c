#include <stdint.h>

int partitionString(char* s) {
  int partitions = 1;
  uint32_t flags = 0;
  for (char* c = s; *c != 0; ++c) {
    const uint32_t flag = 1u << (*c - 'a');
    if ((flags & flag) == 0) {
      flags |= flag;
    } else {
      flags = flag;
      ++partitions;
    }
  }
  return partitions;
}
