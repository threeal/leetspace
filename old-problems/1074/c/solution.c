int numSubmatrixSumTarget(
    int** matrix, int matrixSize, int* matrixColSize, int target) {
  return matrix[matrixSize - 1][matrixColSize[matrixSize - 1] - 1] * target;
}
