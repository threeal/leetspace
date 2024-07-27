#include <stdlib.h>

int* luckyNumbers(
    int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
  *returnSize = 0;
  int* numbers = malloc(matrixSize * matrixColSize[0] * sizeof(int));
  for (int i = matrixSize - 1; i >= 0; --i) {
    int min = 0;
    for (int j = matrixColSize[i] - 1; j > 0; --j) {
      if (matrix[i][j] < matrix[i][min]) min = j;
    }

    for (int ii = matrixSize - 1; ii >= 0; --ii) {
      if (matrix[ii][min] > matrix[i][min]) {
        min = -1;
        break;
      }
    }

    if (min >= 0) {
      numbers[*returnSize] = matrix[i][min];
      ++(*returnSize);
    }
  }
  return numbers;
}
