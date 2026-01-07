#include <stdlib.h>

int* findColumnWidth(
    int** grid, int gridSize, int* gridColSize, int* returnSize) {
  int* maxWidths = malloc(gridColSize[0] * sizeof(int));
  for (int i = 0; i < gridColSize[0]; ++i) maxWidths[i] = 1;

  for (int i = 0; i < gridSize; ++i) {
    for (int j = 0; j < gridColSize[i]; ++j) {
      int num = grid[i][j] / 10, width = 1;
      if (grid[i][j] < 0) {
        num = -num;
        ++width;
      }

      while (num > 0) {
        num /= 10;
        ++width;
      }

      if (width > maxWidths[j]) maxWidths[j] = width;
    }
  }

  *returnSize = gridColSize[0];
  return maxWidths;
}
