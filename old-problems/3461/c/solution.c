#include <stdbool.h>

bool hasSameDigits(char* s) {
  int n = 0;
  while (s[n] != 0) {
    s[n] -= '0';
    ++n;
  }

  while (n > 2) {
    for (int i = 1; i < n; ++i) {
      s[i - 1] = (s[i - 1] + s[i]) % 10;
    }
    --n;
  }

  return s[0] == s[1];
}
