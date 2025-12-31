#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int minDeletionSize(char** strs, int strsSize) {
  int deletions = 0;

  bool* isValids = malloc(strsSize * sizeof(bool));
  for (int i = 0; i < strsSize; ++i) isValids[i] = false;

  int validLefts = strsSize - 1;

  const int strs0Len = strlen(strs[0]);
  for (int i = 0; i < strs0Len && validLefts > 0; ++i) {
    int j = 1;
    while (j < strsSize && (isValids[j] || (strs[j - 1][i] <= strs[j][i]))) ++j;

    if (j == strsSize) {
      for (int j = 1; j < strsSize; ++j) {
        if (!isValids[j] && strs[j - 1][i] < strs[j][i]) {
          isValids[j] = true;
          --validLefts;
        }
      }
    } else {
      ++deletions;
    }
  }

  return deletions;
}
