#include <string.h>

char* makeSmallestPalindrome(char* s) {
  const int sLen = strlen(s);
  for (int l = 0, r = sLen - 1; l < r; ++l, --r) {
    if (s[l] <= s[r]) {
      s[r] = s[l];
    } else {
      s[l] = s[r];
    }
  }
  return s;
}
