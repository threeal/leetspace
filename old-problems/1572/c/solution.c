int diagonalSum(int** mat, int matSize, int* matColSize) {
  (void)matColSize;
  int sum = 0;
  for (int i = 0; i < matSize; ++i) {
    sum += mat[i][i];
    if (matSize - i - 1 != i) {
      sum += mat[i][matSize - i - 1];
    }
  }
  return sum;
}
