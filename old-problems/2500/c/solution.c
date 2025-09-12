#include <stdlib.h>

int compare(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int deleteGreatestValue(int** grid, int gridSize, int* gridColSize) {
  for (int i = 0; i < gridSize; ++i) {
    qsort(grid[i], gridColSize[i], sizeof(int), compare);
  }

  int sum = 0;
  for (int j = 0; j < gridColSize[0]; ++j) {
    int max = grid[0][j];
    for (int i = 1; i < gridSize; ++i) {
      if (grid[i][j] > max) max = grid[i][j];
    }
    sum += max;
  }

  return sum;
}
