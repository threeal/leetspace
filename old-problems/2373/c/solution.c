#include <stdlib.h>

int** largestLocal(int** grid, int gridSize, int* gridColSize, int* returnSize, int** returnColumnSizes) {
  (void)gridColSize;

  *returnSize = gridSize - 2;
  *returnColumnSizes = malloc(*returnSize * sizeof(int));
  int** outputGrid = malloc(*returnSize * sizeof(int*));
  for (int i = gridSize - 3; i >= 0; --i) {
    (*returnColumnSizes)[i] = gridSize - 2;
    outputGrid[i] = malloc((*returnColumnSizes)[i] * sizeof(int));
  }

  for (int i = gridSize - 3; i >= 0; --i) {
    for (int j = gridSize - 3; j >= 0; --j) {
      int largest = 0;
      for (int ii = i + 2; ii >= i; --ii) {
        for (int jj = j + 2; jj >= j; --jj) {
          if (grid[ii][jj] > largest) largest = grid[ii][jj];
        }
      }
      outputGrid[i][j] = largest;
    }
  }

  return outputGrid;
}
