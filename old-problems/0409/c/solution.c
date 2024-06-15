#include <stdint.h>
#include <stdlib.h>

int longestPalindrome(char* s) {
  uint32_t lower = 0;
  uint32_t upper = 0;

  int i = 0;
  while (s[i] != 0) {
    if (s[i] >= 'a') {
      lower ^= 1 << (s[i] - 'a');
    } else {
      upper ^= 1 << (s[i] - 'A');
    }
    ++i;
  }

  const int count = __builtin_popcount(lower) + __builtin_popcount(upper) - 1;
  if (count > 0) i -= count;
  return i;
}
