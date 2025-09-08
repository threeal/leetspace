int countNegatives(int** grid, int gridSize, int* gridColSize) {
  const int n = gridColSize[0] - 1;
  int count = 0, j = n;
  for (int i = 0; i < gridSize; ++i) {
    while (j >= 0 && grid[i][j] < 0) --j;
    count += n - j;
  }
  return count;
}
