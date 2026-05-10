#include <stdbool.h>

bool hasValidPath(int** grid, int gridSize, int* gridColSize) {
  return grid[gridSize - 1][gridColSize[gridSize - 1] - 1] == 0;
}
