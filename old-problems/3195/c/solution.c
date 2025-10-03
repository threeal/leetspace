#include <stdbool.h>

int minimumArea(int** grid, int gridSize, int* gridColSize) {
  int t = gridSize - 1;
  int l = gridColSize[0] - 1;
  int b = 0;
  int r = 0;

  for (int i = 0; i < gridSize; ++i) {
    bool has_one = false;
    for (int j = 0; j < gridColSize[i]; ++j) {
      if (grid[i][j] == 1) {
        has_one = true;

        if (j < l) l = j;
        if (j > r) r = j;
      }
    }

    if (has_one) {
      if (i < t) t = i;
      if (i > b) b = i;
    }
  }

  return (b - t + 1) * (r - l + 1);
}
