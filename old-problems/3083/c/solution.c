#include <stdbool.h>
#include <stdint.h>

bool isSubstringPresent(char* s) {
  uint32_t exists[26] = {0};
  for (int i = 1; s[i] != 0; ++i) {
    exists[s[i] - 'a'] |= 1 << (s[i - 1] - 'a');
  }

  for (int i = 1; s[i] != 0; ++i) {
    if ((exists[s[i - 1] - 'a'] & (1 << (s[i] - 'a'))) != 0) return true;
  }

  return false;
}
