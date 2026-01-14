#include <stdbool.h>

bool isToeplitzMatrix(int** matrix, int matrixSize, int* matrixColSize) {
  for (int i = 0; i < matrixSize; ++i) {
    int ii = i + 1, jj = 1;
    while (ii < matrixSize && jj < matrixColSize[ii]) {
      if (matrix[ii][jj] != matrix[i][0]) return false;
      ++ii, ++jj;
    }
  }

  for (int j = 1; j < matrixColSize[0]; ++j) {
    int ii = 1, jj = j + 1;
    while (ii < matrixSize && jj < matrixColSize[ii]) {
      if (matrix[ii][jj] != matrix[0][j]) return false;
      ++ii, ++jj;
    }
  }

  return true;
}
