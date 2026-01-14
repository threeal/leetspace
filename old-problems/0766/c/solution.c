#include <stdbool.h>

bool isToeplitzMatrix(int** matrix, int matrixSize, int* matrixColSize) {
  return matrix[matrixSize - 1][matrixColSize[matrixSize - 1] - 1] == 0;
}
