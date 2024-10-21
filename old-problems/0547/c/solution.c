#include <stdlib.h>

int findRoot(int* roots, int i);

int findCircleNum(
    int** isConnected, int isConnectedSize, int* isConnectedColSize) {
  (void)isConnectedColSize;

  int distinctCount = isConnectedSize;

  int* roots = malloc(isConnectedSize * sizeof(int));
  for (int i = 0; i < isConnectedSize; ++i) roots[i] = i;

  for (int i = 0; i < isConnectedSize; ++i) {
    for (int j = i + 1; j < isConnectedSize; ++j) {
      if (isConnected[i][j] == 0) continue;

      int rootI = findRoot(roots, i);
      int rootJ = findRoot(roots, j);
      if (rootI != rootJ) {
        if (rootI > rootJ) {
          const int temp = rootI;
          rootI = rootJ;
          rootJ = temp;
        }
        roots[rootI] = rootJ;
        --distinctCount;
      }
    }
  }

  free(roots);

  return distinctCount;
}

int findRoot(int* roots, int i) {
  if (roots[i] != i) roots[i] = findRoot(roots, roots[i]);
  return roots[i];
}
