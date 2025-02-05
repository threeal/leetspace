int minPathSum(int** grid, int gridSize, int* gridColSize) {
  for (int j = 1; j < gridColSize[0]; ++j) {
    grid[0][j] += grid[0][j - 1];
  }

  for (int i = 1; i < gridSize; ++i) {
    grid[i][0] += grid[i - 1][0];

    for (int j = 1; j < gridColSize[i]; ++j) {
      grid[i][j] += grid[i - 1][j] <= grid[i][j - 1]
          ? grid[i - 1][j]
          : grid[i][j - 1];
    }
  }

  return grid[gridSize - 1][gridColSize[gridSize - 1] - 1];
}
