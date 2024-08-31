#include <stdint.h>

char repeatedCharacter(char* s) {
  uint32_t exists = 0;
  while (*s != 0) {
    if ((exists & 1 << (*s - 'a')) != 0) return *s;
    exists |= 1 << (*s - 'a');
    ++s;
  }
  return 0;
}
