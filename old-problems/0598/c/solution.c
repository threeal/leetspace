int maxCount(int m, int n, int** ops, int opsSize, int* opsColSize) {
  (void)opsColSize;
  for (int i = 0; i < opsSize; ++i) {
    if (ops[i][0] < m) m = ops[i][0];
    if (ops[i][1] < n) n = ops[i][1];
  }
  return m * n;
}
