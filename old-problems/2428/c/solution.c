int maxSum(int** grid, int gridSize, int* gridColSize) {
  int max = 0;
  for (int i = 2; i < gridSize; ++i) {
    for (int j = 2; j < gridColSize[i]; ++j) {
      const int sum =
          grid[i - 2][j - 2] + grid[i - 2][j - 1] + grid[i - 2][j] +
          grid[i - 1][j - 1] +
          grid[i][j - 2] + grid[i][j - 1] + grid[i][j];
      if (sum > max) max = sum;
    }
  }
  return max;
}
