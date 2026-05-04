#include <stdbool.h>
#include <stdlib.h>

static int findRoot(int* roots, int i) {
  return roots[i] != i ? (roots[i] = findRoot(roots, roots[i])) : i;
}

bool containsCycle(char** grid, int gridSize, int* gridColSize) {
  const int m = gridSize, n = gridColSize[0];

  const int rootsSize = m * n;
  int* roots = malloc(rootsSize * sizeof(int));
  for (int i = 0; i < rootsSize; ++i) roots[i] = i;

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i + 1 < m && grid[i][j] == grid[i + 1][j]) {
        const int a = findRoot(roots, i * n + j);
        const int b = findRoot(roots, (i + 1) * n + j);

        if (a == b) {
          free(roots);
          return true;
        }

        if (a < b) {
          roots[b] = a;
        } else {
          roots[a] = b;
        }
      }

      if (j + 1 < n && grid[i][j] == grid[i][j + 1]) {
        const int a = findRoot(roots, i * n + j);
        const int b = findRoot(roots, i * n + j + 1);

        if (a == b) {
          free(roots);
          return true;
        }

        if (a < b) {
          roots[b] = a;
        } else {
          roots[a] = b;
        }
      }
    }
  }

  free(roots);
  return false;
}
