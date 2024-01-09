#include <stdlib.h>

int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) {
  *returnSize = matrixColSize[0];
  *returnColumnSizes = malloc(sizeof(int) * (*returnSize));
  int** returnMatrix = malloc(sizeof(int*) * (*returnSize));
  for (int i = 0; i < *returnSize; ++i) {
    (*returnColumnSizes)[i] = matrixSize;
    returnMatrix[i] = malloc(sizeof(int) * (*returnColumnSizes)[i]);
  }

  for (int i = 0; i < matrixSize; ++i) {
    for (int j = 0; j < matrixColSize[i]; ++j) {
      returnMatrix[j][i] = matrix[i][j];
    }
  }

  return returnMatrix;
}
