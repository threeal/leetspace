#include <stdlib.h>
#include <string.h>

int stoneGameVII(int* stones, int stonesSize) {
  for (int i = 1; i < stonesSize; ++i) {
    stones[i] += stones[i - 1];
  }

  int* diffs = malloc(stonesSize * sizeof(int));
  memset(diffs, 0, stonesSize * sizeof(int));

  for (int i = 1; i < stonesSize; ++i) {
    for (int j = 0; j < stonesSize - i; ++j) {
      const int a = stones[j + i] - stones[j] - diffs[j + 1];
      const int b = stones[j + i - 1] - (j > 0 ? stones[j - 1] : 0) - diffs[j];
      diffs[j] = a > b ? a : b;
    }
  }

  const int res = diffs[0];
  free(diffs);
  return res;
}
