#include <stdlib.h>

int compare(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int compareGreater(const void* a, const void* b) {
  return *(int*)b - *(int*)a;
}

int** sortMatrix(
    int** grid, int gridSize, int* gridColSize,
    int* returnSize, int** returnColumnSizes) {
  const int m = gridSize;
  const int n = gridColSize[0];

  int* arr = malloc((m <= n ? m : n) * sizeof(int));
  for (int i = 0; i < m; ++i) {
    int k = 0;
    while (i + k < m && k < n) {
      arr[k] = grid[i + k][k];
      ++k;
    }

    qsort(arr, k, sizeof(int), compareGreater);

    while (k > 0) {
      --k;
      grid[i + k][k] = arr[k];
    }
  }

  for (int j = 1; j < n; ++j) {
    int k = 0;
    while (k < m && j + k < n) {
      arr[k] = grid[k][j + k];
      ++k;
    }

    qsort(arr, k, sizeof(int), compare);

    while (k > 0) {
      --k;
      grid[k][j + k] = arr[k];
    }
  }

  free(arr);

  *returnSize = gridSize;
  *returnColumnSizes = gridColSize;
  return grid;
}
