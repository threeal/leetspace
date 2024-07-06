#include <stdlib.h>

int comp(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int** diagonalSort(
    int** mat, int matSize, int* matColSize,
    int* returnSize, int** returnColumnSizes) {
  *returnSize = matSize;
  *returnColumnSizes = matColSize;

  const int h = matSize;
  if (h == 1) return mat;

  const int w = matColSize[0];
  if (w == 1) return mat;

  int* tempArr = malloc((h > w ? h : w) * sizeof(int));

  for (int x = w - 1; x >= 0; --x) {
    int n = w - x < h ? w - x : h;
    int i = n;
    while (--i >= 0) tempArr[i] = mat[i][x + i];

    qsort(tempArr, n, sizeof(int), comp);

    i = n;
    while (--i >= 0) mat[i][x + i] = tempArr[i];
  }

  for (int y = h - 1; y > 0; --y) {
    int n = h - y < w ? h - y : w;
    int i = n;
    while (--i >= 0) tempArr[i] = mat[y + i][i];

    qsort(tempArr, n, sizeof(int), comp);

    i = n;
    while (--i >= 0) mat[y + i][i] = tempArr[i];
  }

  free(tempArr);

  return mat;
}
