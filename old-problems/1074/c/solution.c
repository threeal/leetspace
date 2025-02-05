#include <stdlib.h>
#include <string.h>

int numSubmatrixSumTarget(
    int** matrix, int matrixSize, int* matrixColSize, int target) {
  int count = 0;
  for (int i = 0; i < matrixSize; ++i) {
    for (int j = 0; j < matrixColSize[i]; ++j) {
      if (matrix[i][j] == target) ++count;
    }
  }

  int** hSum = malloc(matrixSize * sizeof(int*));
  int** vSum = malloc(matrixSize * sizeof(int*));
  for (int i = 0; i < matrixSize; ++i) {
    hSum[i] = malloc(matrixColSize[i] * sizeof(int));
    memcpy(hSum[i], matrix[i], matrixColSize[i] * sizeof(int));

    vSum[i] = malloc(matrixColSize[i] * sizeof(int));
    memcpy(vSum[i], matrix[i], matrixColSize[i] * sizeof(int));
  }

  for (int i = 0; i < matrixSize; ++i) {
    for (int j = 0; j < matrixColSize[i]; ++j) {
      for (int ii = i; ii < matrixSize; ++ii) {
        for (int jj = matrixColSize[ii] - 1; jj > j; --jj) {
          vSum[ii][jj] = hSum[ii][jj] + vSum[ii][jj - 1];
          if (vSum[ii][jj] == target) ++count;
        }
      }
    }

    for (int ii = matrixSize - 1; ii > i; --ii) {
      for (int jj = 0; jj < matrixColSize[ii]; ++jj) {
        hSum[ii][jj] = matrix[ii][jj] + hSum[ii - 1][jj];
        if (hSum[ii][jj] == target) ++count;
      }
      memcpy(vSum[ii], hSum[ii], matrixColSize[ii] * sizeof(int));
    }
  }

  for (int i = 0; i < matrixSize; ++i) {
    free(hSum[i]);
    free(vSum[i]);
  }
  free(hSum);
  free(vSum);

  return count;
}
