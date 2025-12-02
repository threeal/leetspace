#include <stdlib.h>
#include <string.h>

int numberOfPaths(int** grid, int gridSize, int* gridColSize, int k) {
  int* count = malloc(k * sizeof(int));
  for (int i = 0; i < k; ++i) count[i] = 0;

  int** counts = malloc(gridColSize[0] * sizeof(int*));
  for (int i = 0; i < gridColSize[0]; ++i) {
    counts[i] = malloc(k * sizeof(int));
    memcpy(counts[i], count, k * sizeof(int));
  }

  counts[0][0] = 1;

  for (int i = 0; i < gridSize; ++i) {
    for (int kk = 0; kk < k; ++kk) {
      count[(kk + grid[i][0]) % k] = counts[0][kk];
    }

    memcpy(counts[0], count, k * sizeof(int));

    for (int j = 1; j < gridColSize[i]; ++j) {
      for (int kk = 0; kk < k; ++kk) {
        count[(kk + grid[i][j]) % k] =
            (counts[j][kk] + counts[j - 1][kk]) % 1000000007;
      }

      memcpy(counts[j], count, k * sizeof(int));
    }
  }

  const int res = counts[gridColSize[0] - 1][0];

  free(count);

  for (int i = 0; i < gridColSize[0]; ++i) free(counts[i]);
  free(counts);

  return res;
}
