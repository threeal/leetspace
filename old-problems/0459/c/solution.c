#include <stdbool.h>
#include <string.h>

bool repeatedSubstringPattern(char* s) {
  const int sLen = strlen(s);
  for (int n = 1; n * 2 <= sLen; ++n) {
    if (sLen % n != 0) continue;

    bool valid = true;
    for (int i = n; i < sLen; i += n) {
      for (int j = 0; j < n; ++j) {
        if (s[i + j] != s[j]) {
          valid = false;
          i = sLen;
          j = n;
        }
      }
    }

    if (valid) return true;
  }

  return false;
}
