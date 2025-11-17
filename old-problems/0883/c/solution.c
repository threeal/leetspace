int projectionArea(int** grid, int gridSize, int* gridColSize) {
  int area = 0;
  for (int j = 0; j < gridColSize[0]; ++j) {
    area += grid[0][j];
  }

  for (int i = 0; i < gridSize; ++i) {
    int max = 0;
    for (int j = 0; j < gridColSize[i]; ++j) {
      if (grid[i][j] != 0) ++area;

      if (grid[i][j] > max) {
        area += grid[i][j] - max;
        max = grid[i][j];
      }

      if (grid[i][j] > grid[0][j]) {
        area += grid[i][j] - grid[0][j];
        grid[0][j] = grid[i][j];
      }
    }
  }

  return area;
}
