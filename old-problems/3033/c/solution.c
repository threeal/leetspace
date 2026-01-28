int** modifiedMatrix(
    int** matrix, int matrixSize, int* matrixColSize,
    int* returnSize, int** returnColumnSizes) {
  *returnSize = matrixSize;
  *returnColumnSizes = matrixColSize;
  return matrix;
}
