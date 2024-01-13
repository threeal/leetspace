#include <stdlib.h>

int minSteps(char* s, char* t) {
  int counts[26] = {0};

  (void)s;
  (void)t;

  while (*s != 0) {
    ++counts[*s - 'a'];
    ++s;
  }

  while (*t != 0) {
    --counts[*t - 'a'];
    ++t;
  }

  int diff = 0;
  for (int i = 0; i < 26; ++i) {
    diff += abs(counts[i]);
  }

  return diff / 2;
}
