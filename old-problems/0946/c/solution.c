#include <stdbool.h>

bool validateStackSequences(
    int* pushed, int pushedSize, int* popped, int poppedSize) {
  int l = 1, r = 1, i = 0;
  while (true) {
    if (l == 0 || pushed[l - 1] != popped[i]) {
      if (r == pushedSize) break;
      pushed[l++] = pushed[r++];
    } else {
      --l;
      ++i;
      if (i == poppedSize) break;
    }
  }
  return i == poppedSize;
}
