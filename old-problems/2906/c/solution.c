#include <stdlib.h>

int** constructProductMatrix(
    int** grid, int gridSize, int* gridColSize,
    int* returnSize, int** returnColumnSizes) {
  int** output = malloc(gridSize * sizeof(int*));

  int prefix = 1;
  for (int i = 0; i < gridSize; ++i) {
    output[i] = malloc(gridColSize[i] * sizeof(int));
    for (int j = 0; j < gridColSize[0]; ++j) {
      grid[i][j] %= 12345;
      output[i][j] = prefix;
      prefix = (prefix * grid[i][j]) % 12345;
    }
  }

  int suffix = 1;
  for (int i = gridSize - 1; i >= 0; --i) {
    for (int j = gridColSize[i] - 1; j >= 0; --j) {
      output[i][j] = (output[i][j] * suffix) % 12345;
      suffix = (suffix * grid[i][j]) % 12345;
    }
  }

  *returnSize = gridSize;
  *returnColumnSizes = gridColSize;
  return output;
}
