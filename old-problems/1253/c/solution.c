#include <stdlib.h>

int** reconstructMatrix(
    int upper, int lower, int* colsum, int colsumSize,
    int* returnSize, int** returnColumnSizes) {
  int** mat = malloc(2 * sizeof(int*));
  *returnColumnSizes = malloc(2 * sizeof(int));
  *returnSize = 2;

  mat[0] = calloc(colsumSize, sizeof(int));
  (*returnColumnSizes)[0] = colsumSize;

  mat[1] = calloc(colsumSize, sizeof(int));
  (*returnColumnSizes)[1] = colsumSize;

  for (int i = colsumSize - 1; i >= 0; --i) {
    if (colsum[i] == 2) {
      if (lower > 0 && upper > 0) {
        mat[1][i] = 1;
        mat[0][i] = 1;
        --lower;
        --upper;
      } else {
        *returnSize = 0;
        return mat;
      }
    }
  }

  for (int i = colsumSize - 1; i >= 0; --i) {
    if (colsum[i] == 1) {
      if (lower > 0) {
        mat[1][i] = 1;
        --lower;
      } else if (upper > 0) {
        mat[0][i] = 1;
        --upper;
      } else {
        *returnSize = 0;
        return mat;
      }
    }
  }

  if (upper > 0 || lower > 0) {
    *returnSize = 0;
    return mat;
  }

  return mat;
}
