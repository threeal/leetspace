#include <stdlib.h>
#include <string.h>

int countServers(int** grid, int gridSize, int* gridColSize) {
  int* rowCounts = malloc(gridSize * sizeof(int));
  memset(rowCounts, 0, gridSize * sizeof(int));

  int* colCounts = malloc(gridColSize[0] * sizeof(int));
  memset(colCounts, 0, gridColSize[0] * sizeof(int));

  for (int i = 0; i < gridSize; ++i) {
    for (int j = 0; j < gridColSize[i]; ++j) {
      if (grid[i][j] == 1) {
        ++rowCounts[i];
        ++colCounts[j];
      }
    }
  }

  int count = 0;
  for (int i = 0; i < gridSize; ++i) {
    if (rowCounts[i] > 1) {
      count += rowCounts[i];
    } else if (rowCounts[i] == 1) {
      for (int j = 0; j < gridColSize[i]; ++j) {
        if (grid[i][j] == 1 && colCounts[j] > 1) ++count;
      }
    }
  }

  return count;
}
