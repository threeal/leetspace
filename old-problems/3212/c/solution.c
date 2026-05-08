#include <stdlib.h>
#include <string.h>

int numberOfSubmatrices(char** grid, int gridSize, int* gridColSize) {
  int count = 0;

  int* xs = malloc(gridColSize[0] * sizeof(int));
  memset(xs, 0, gridColSize[0] * sizeof(int));

  int* ys = malloc(gridColSize[0] * sizeof(int));
  memset(ys, 0, gridColSize[0] * sizeof(int));

  for (int i = 0; i < gridSize; ++i) {
    int x = 0, y = 0;
    for (int j = 0; j < gridColSize[i]; ++j) {
      switch (grid[i][j]) {
        case 'X':
          ++x;
          break;

        case 'Y':
          ++y;
          break;
      }

      if (xs[j] + x != 0 && xs[j] + x == ys[j] + y) ++count;

      xs[j] += x;
      ys[j] += y;
    }
  }

  free(xs);
  free(ys);

  return count;
}
