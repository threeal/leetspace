int countSquares(int** matrix, int matrixSize, int* matrixColSize) {
  int count = 0;
  for (int j = 0; j < matrixColSize[0]; ++j) count += matrix[0][j];

  for (int i = 1; i < matrixSize; ++i) {
    count += matrix[i][0];
    for (int j = 1; j < matrixColSize[i]; ++j) {
      if (matrix[i][j] == 0) continue;
      int val = matrix[i - 1][j - 1];
      if (matrix[i][j - 1] < val) val = matrix[i][j - 1];
      if (matrix[i - 1][j] < val) val = matrix[i - 1][j];
      matrix[i][j] += val;
      count += matrix[i][j];
    }
  }

  return count;
}
