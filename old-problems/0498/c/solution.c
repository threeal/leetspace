#include <stdlib.h>

int* findDiagonalOrder(
    int** mat, int matSize, int* matColSize, int* returnSize) {
  int m = matSize, n = matColSize[0], i = 0, j = 1;

  int* arr = malloc(m * n * sizeof(int));
  int arrSize = 0;

  while (i < m + n) {
    int ii = i < m ? i : m - 1;
    int jj = i < m ? 0 : i - m + 1;

    while (ii > 0 && jj < n) {
      arr[arrSize++] = mat[ii][jj];
      --ii;
      ++jj;
    }

    if (jj < n) {
      arr[arrSize++] = mat[ii][jj];
    }

    i += 2;

    if (j < m + n) {
      int ii = j < n ? 0 : j - n + 1;
      int jj = j < n ? j : n - 1;

      while (ii < m && jj > 0) {
        arr[arrSize++] = mat[ii][jj];
        ++ii;
        --jj;
      }

      if (ii < m) {
        arr[arrSize++] = mat[ii][jj];
      }

      j += 2;
    }
  }

  *returnSize = arrSize;
  return arr;
}
