int** modifiedMatrix(
    int** matrix, int matrixSize, int* matrixColSize,
    int* returnSize, int** returnColumnSizes) {
  for (int i = 0; i < matrixColSize[0]; ++i) {
    int maxValue = 0;
    for (int j = 0; j < matrixSize; ++j) {
      if (matrix[j][i] > maxValue) maxValue = matrix[j][i];
    }

    for (int j = 0; j < matrixSize; ++j) {
      if (matrix[j][i] == -1) matrix[j][i] = maxValue;
    }
  }

  *returnSize = matrixSize;
  *returnColumnSizes = matrixColSize;
  return matrix;
}
