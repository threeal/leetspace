#include <limits.h>

int minFallingPathSum(int** grid, int gridSize, int* gridColSize) {
  for (int i = 1; i < gridSize; ++i) {
    int minVals[2] = {INT_MAX, INT_MAX};
    for (int j = 0; j < gridColSize[i - 1]; ++j) {
      if (grid[i - 1][j] < minVals[1]) {
        if (grid[i - 1][j] <= minVals[0]) {
          minVals[1] = minVals[0];
          minVals[0] = grid[i - 1][j];
        } else {
          minVals[1] = grid[i - 1][j];
        }
      }
    }

    if (minVals[0] == minVals[1]) {
      for (int j = 0; j < gridColSize[i]; ++j) {
        grid[i][j] += minVals[0];
      }
    } else {
      for (int j = 0; j < gridColSize[i]; ++j) {
        grid[i][j] += grid[i - 1][j] == minVals[0] ? minVals[1] : minVals[0];
      }
    }
  }

  int minVal = INT_MAX;
  for (int i = 0; i < gridColSize[gridSize - 1]; ++i) {
    if (grid[gridSize - 1][i] < minVal) minVal = grid[gridSize - 1][i];
  }
  return minVal;
}
