#include <stdbool.h>

bool areAlmostEqual(char* s1, char* s2) {
  for (int i = 0; s1[i] != 0; ++i) {
    if (s1[i] == s2[i]) continue;
    for (int j = i + 1; s1[j] != 0; ++j) {
      if (s1[j] == s2[j]) continue;
      if (s1[i] != s2[j] || s1[j] != s2[i]) return false;
      for (++j; s1[j] != 0; ++j) {
        if (s1[j] != s2[j]) return false;
      }
      return true;
    }
    return false;
  }
  return true;
}
