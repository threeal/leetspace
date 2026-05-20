#include <stdlib.h>

int* findDegrees(
    int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
  int* degrees = malloc(matrixSize * sizeof(int));
  for (int i = 0; i < matrixSize; ++i) {
    degrees[i] = 0;
    for (int j = 0; j < matrixColSize[i]; ++j) {
      if (matrix[i][j] == 1) ++degrees[i];
    }
  }
  *returnSize = matrixSize;
  return degrees;
}
