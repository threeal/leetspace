#include <stdlib.h>

int surfaceArea(int** grid, int gridSize, int* gridColSize) {
  int area = 0;

  if (grid[0][0] != 0) area += 2;
  area += 2 * grid[0][0] +
      grid[0][gridColSize[0] - 1] + grid[gridSize - 1][0];

  for (int j = 1; j < gridColSize[0]; ++j) {
    if (grid[0][j] != 0) area += 2;
    area += grid[0][j] + grid[gridSize - 1][j] +
        abs(grid[0][j] - grid[0][j - 1]);
  }

  for (int i = 1; i < gridSize; ++i) {
    if (grid[i][0] != 0) area += 2;
    area += grid[i][0] + grid[i][gridColSize[i] - 1] +
        abs(grid[i][0] - grid[i - 1][0]);

    for (int j = 1; j < gridColSize[i]; ++j) {
      if (grid[i][j] != 0) area += 2;
      area += abs(grid[i][j] - grid[i - 1][j]) +
          abs(grid[i][j] - grid[i][j - 1]);
    }
  }

  return area;
}
