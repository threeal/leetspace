#include <string.h>

int minSwaps(char* s) {
  int sLen = strlen(s);

  int swap = 0, lb = 0, rb = 0;
  int l = 0, r = sLen - 1;
  while (l < r) {
    while (l < r) {
      if (s[l] == '[') {
        ++lb;
      } else {
        --lb;
        if (lb < 0) {
          lb += 2;
          ++swap;
          break;
        }
      }
      ++l;
    }

    while (l < r) {
      if (s[r] == ']') {
        ++rb;
      } else {
        --rb;
        if (rb < 0) {
          rb -= 2;
          break;
        }
      }
      --r;
    }

    ++l, --r;
  }

  return swap;
}
