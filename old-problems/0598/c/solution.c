int maxCount(int m, int n, int** ops, int opsSize, int* opsColSize) {
  return m * n * ops[opsSize - 1][opsColSize[opsSize - 1] - 1];
}
