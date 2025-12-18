int minimumOperations(int** grid, int gridSize, int* gridColSize) {
  int operations = 0;
  for (int j = 0; j < gridColSize[0]; ++j) {
    int prev = grid[0][j];
    for (int i = 1; i < gridSize; ++i) {
      if (grid[i][j] > prev) {
        prev = grid[i][j];
      } else {
        ++prev;
        operations += prev - grid[i][j];
      }
    }
  }
  return operations;
}
