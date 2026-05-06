#include <stdlib.h>

int** shiftGrid(
    int** grid, int gridSize, int* gridColSize, int k,
    int* returnSize, int** returnColumnSizes) {
  int** out = malloc(gridSize * sizeof(int*));
  for (int i = 0; i < gridSize; ++i) {
    out[i] = malloc(gridColSize[i] * sizeof(int));
  }

  const int n = gridColSize[0];
  const int mn = gridSize * n;
  for (int i = 0; i < mn; ++i) {
    const int j = (i + k) % mn;
    out[j / n][j % n] = grid[i / n][i % n];
  }

  *returnSize = gridSize;
  *returnColumnSizes = gridColSize;
  return out;
}
