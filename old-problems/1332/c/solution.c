#include <string.h>

int removePalindromeSub(char* s) {
  for (int l = 0, r = strlen(s) - 1; l < r; ++l, --r) {
    if (s[l] != s[r]) return 2;
  }
  return 1;
}
