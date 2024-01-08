#include <stdlib.h>

int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) {
  (void)matrix;

  *returnSize = matrixColSize[0];
  *returnColumnSizes = malloc(sizeof(int) * (*returnSize));
  int** returnMatrix = malloc(sizeof(int*) * (*returnSize));
  for (int i = 0; i < *returnSize; ++i) {
    (*returnColumnSizes)[i] = matrixSize;
    returnMatrix[i] = malloc(sizeof(int) * (*returnColumnSizes)[i]);
  }

  return returnMatrix;
}
