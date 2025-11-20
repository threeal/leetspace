int* rowAndMaximumOnes(
    int** mat, int matSize, int* matColSize, int* returnSize) {
  *returnSize = matColSize[matSize - 1];
  return mat[matSize - 1];
}
