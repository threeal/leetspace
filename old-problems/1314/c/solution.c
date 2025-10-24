#include <stdlib.h>

int** matrixBlockSum(
    int** mat, int matSize, int* matColSize, int k,
    int* returnSize, int** returnColumnSizes) {
  const int m = matSize;
  const int n = matColSize[0];

  for (int i = 0; i < m; ++i) {
    for (int j = 1; j < n; ++j) {
      mat[i][j] += mat[i][j - 1];
    }
  }

  for (int j = 0; j < n; ++j) {
    for (int i = 1; i < m; ++i) {
      mat[i][j] += mat[i - 1][j];
    }
  }

  int** output = malloc(matSize * sizeof(int*));
  for (int i = 0; i < m; ++i) {
    output[i] = malloc(matColSize[i] * sizeof(int));
  }

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      const int i1 = i + k <= m - 1 ? i + k : m - 1;
      const int j1 = j + k <= n - 1 ? j + k : n - 1;
      if (i > k) {
        if (j > k) {
          output[i][j] = mat[i1][j1] + mat[i - k - 1][j - k - 1] -
              mat[i - k - 1][j1] - mat[i1][j - k - 1];
        } else {
          output[i][j] = mat[i1][j1] - mat[i - k - 1][j1];
        }
      } else {
        if (j > k) {
          output[i][j] = mat[i1][j1] - mat[i1][j - k - 1];
        } else {
          output[i][j] = mat[i1][j1];
        }
      }
    }
  }

  *returnSize = matSize;
  *returnColumnSizes = matColSize;
  return output;
}
