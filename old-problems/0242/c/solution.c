#include <stdbool.h>
#include <string.h>

bool isAnagram(char* s, char* t) {
  if (strlen(s) != strlen(t)) return false;

  int counts[26] = {0};
  while (*s != 0) {
    ++counts[*s - 'a'];
    ++s;
  }

  while (*t != 0) {
    if (--counts[*t - 'a'] < 0) return false;
    ++t;
  }

  return true;
}
