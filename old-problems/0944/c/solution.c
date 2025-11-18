#include <string.h>

int minDeletionSize(char** strs, int strsSize) {
  int count = 0, len = strlen(strs[0]);
  for (int j = 0; j < len; ++j) {
    for (int i = 1; i < strsSize; ++i) {
      if (strs[i][j] < strs[i - 1][j]) {
        ++count;
        break;
      }
    }
  }
  return count;
}
