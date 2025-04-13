#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool isScramble(char* s1, char* s2) {
  const int len = strlen(s1);
  bool valid[30 * 30 * 31] = {false};
  for (int i1 = 0; i1 < len; ++i1) {
    for (int i2 = 0; i2 < len; ++i2) {
      valid[i1 * 930 + i2 * 31 + 1] = s1[i1] == s2[i2];
    }
  }

  for (int n = 2; n <= len; ++n) {
    const int r = len - n;
    for (int i1 = 0; i1 <= r; ++i1) {
      for (int i2 = 0; i2 <= r; ++i2) {
        for (int j = 1; j < n; ++j) {
          if (valid[i1 * 930 + i2 * 31 + j] &&
              valid[(i1 + j) * 930 + (i2 + j) * 31 + n - j]) {
            valid[i1 * 930 + i2 * 31 + n] = true;
            break;
          }
          if (valid[i1 * 930 + (i2 + n - j) * 31 + j] &&
              valid[(i1 + j) * 930 + i2 * 31 + n - j]) {
            valid[i1 * 930 + i2 * 31 + n] = true;
            break;
          }
        }
      }
    }
  }

  return valid[len];
}
