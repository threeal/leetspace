#include <stdlib.h>
#include <string.h>

int find(int** caches, int* sums, int n, int i);

int stoneGameV(int* stoneValue, int stoneValueSize) {
  int* sums = malloc((stoneValueSize + 1) * sizeof(int));
  sums[0] = 0;
  for (int i = 0; i < stoneValueSize; ++i) {
    sums[i + 1] = sums[i] + stoneValue[i];
  }

  int** caches = malloc(stoneValueSize * sizeof(int*));
  for (int i = stoneValueSize - 1; i >= 0; --i) {
    caches[i] = malloc((stoneValueSize + 1) * sizeof(int));
    memset(caches[i], -1, (stoneValueSize + 1) * sizeof(int));
  }

  const int result = find(caches, sums, stoneValueSize, 0);

  for (int i = stoneValueSize - 1; i >= 0; --i) free(caches[i]);
  free(caches);
  free(sums);

  return result;
}

int find(int** caches, int* sums, int n, int i) {
  int* best = caches[n - 1] + i;
  if (*best < 0) {
    *best = 0;
    for (int j = i + 1; j < i + n; ++j) {
      const int left = sums[j] - sums[i];
      const int right = sums[i + n] - sums[j];

      if (left <= right) {
        const int newBest = left + find(caches, sums, j - i, i);
        if (newBest > *best) *best = newBest;
      }

      if (right <= left) {
        const int newBest = right + find(caches, sums, i + n - j, j);
        if (newBest > *best) *best = newBest;
      }
    }
  }
  return *best;
}
