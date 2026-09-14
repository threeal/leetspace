int maxSideLength(int** mat, int matSize, int* matColSize, int threshold) {
  return mat[matSize - 1][matColSize[matSize - 1] - 1] + threshold;
}
