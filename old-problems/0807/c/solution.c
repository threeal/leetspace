#include <stdlib.h>
#include <string.h>

int maxIncreaseKeepingSkyline(int** grid, int gridSize, int* gridColSize) {
  int* rowMax = malloc(gridSize * sizeof(int));
  memset(rowMax, 0, gridSize * sizeof(int));

  for (int i = 0; i < gridSize; ++i) {
    int maxHeight = 0;
    for (int j = 0; j < gridColSize[i]; ++j) {
      if (grid[i][j] > maxHeight) maxHeight = grid[i][j];
    }
    rowMax[i] = maxHeight;
  }

  int* colMax = malloc(gridColSize[0] * sizeof(int));
  memset(colMax, 0, gridColSize[0] * sizeof(int));

  for (int j = 0; j < gridColSize[0]; ++j) {
    int maxHeight = 0;
    for (int i = 0; i < gridSize; ++i) {
      if (grid[i][j] > maxHeight) maxHeight = grid[i][j];
    }
    colMax[j] = maxHeight;
  }

  int sum = 0;
  for (int i = 0; i < gridSize; ++i) {
    for (int j = 0; j < gridColSize[i]; ++j) {
      sum += (rowMax[i] <= colMax[j] ? rowMax[i] : colMax[j]) - grid[i][j];
    }
  }

  free(rowMax);
  free(colMax);

  return sum;
}
