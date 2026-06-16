#include <string.h>

int firstMatchingIndex(char* s) {
  const int sLen = strlen(s);
  for (int l = 0, r = sLen - 1; l < r; ++l, --r) {
    if (s[l] == s[r]) return l;
  }
  return sLen % 2 == 0 ? -1 : sLen / 2;
}
