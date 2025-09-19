#include <stdint.h>

int minimizedStringLength(char* s) {
  uint32_t exists = 0;
  int unique = 0;
  while (*s != 0) {
    if ((exists & 1 << (*s - 'a')) == 0) {
      exists |= 1 << (*s - 'a');
      ++unique;
    }
    ++s;
  }
  return unique;
}
