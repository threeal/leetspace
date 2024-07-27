int* luckyNumbers(
    int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
  *returnSize = matrixColSize[matrixSize - 1];
  return matrix[matrixSize - 1];
}
