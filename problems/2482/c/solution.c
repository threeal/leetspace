#include <stdlib.h>

int** onesMinusZeros(int** grid, int gridSize, int* gridColSize, int* returnSize, int** returnColumnSizes) {
  *returnSize = gridSize;
  *returnColumnSizes = gridColSize;

  // Calculate the total count of elements with a value of one in each row and column.
  int* oneRow = calloc(gridSize, sizeof(int));
  int* oneCol = calloc(gridColSize[0], sizeof(int));
  for (int i = 0; i < gridSize; ++i) {
    for (int j = 0; j < gridColSize[i]; ++j) {
      if (grid[i][j] == 1) {
        ++oneRow[i];
        ++oneCol[j];
      }
    }
  }

  // Modify the given grid.
  for (int i = 0; i < gridSize; ++i) {
    for (int j = 0; j < gridColSize[i]; ++j) {
      // Given that zeroRow[i] + zeroCol[j] = gridSize + gridColSize[i] - oneRow[i] - oneCol[j].
      grid[i][j] = 2 * (oneRow[i] + oneCol[j]) - gridSize - gridColSize[i];
    }
  }

  free(oneRow);
  free(oneCol);

  return grid;
}
