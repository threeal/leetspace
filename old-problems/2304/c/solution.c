#include <stdlib.h>
#include <string.h>

int minPathCost(
    int** grid, int gridSize, int* gridColSize, int** moveCost,
    int moveCostSize, int* moveCostColSize) {
  (void)moveCostSize;
  (void)moveCostColSize;

  const int nowSize = gridColSize[0];
  int* now = malloc(nowSize * sizeof(int));
  memcpy(now, grid[0], nowSize * sizeof(int));

  int* prev = malloc(nowSize * sizeof(int));

  for (int i = 1; i < gridSize; ++i) {
    int* temp = now;
    now = prev;
    prev = temp;

    for (int j = 0; j < gridColSize[i]; ++j) {
      int minCost = prev[0] + moveCost[grid[i - 1][0]][j];
      for (int k = 1; k < gridColSize[i]; ++k) {
        const int cost = prev[k] + moveCost[grid[i - 1][k]][j];
        if (cost < minCost) minCost = cost;
      }
      now[j] = grid[i][j] + minCost;
    }
  }

  int min = now[0];
  for (int i = 1; i < nowSize; ++i) {
    if (now[i] < min) min = now[i];
  }

  free(now);
  free(prev);

  return min;
}
