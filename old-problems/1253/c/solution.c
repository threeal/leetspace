#include <stdlib.h>

int** reconstructMatrix(
    int upper, int lower, int* colsum, int colsumSize,
    int* returnSize, int** returnColumnSizes) {
  int** mat = malloc(2 * sizeof(int*));
  *returnColumnSizes = malloc(2 * sizeof(int));
  *returnSize = 2;

  mat[0] = malloc(colsumSize * sizeof(int));
  (*returnColumnSizes)[0] = colsumSize;

  mat[1] = malloc(colsumSize * sizeof(int));
  (*returnColumnSizes)[1] = colsumSize;

  (void)upper;
  (void)lower;
  (void)colsum;

  return mat;
}
