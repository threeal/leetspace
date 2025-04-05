int minOperations(int** grid, int gridSize, int* gridColSize, int x) {
  return grid[gridSize - 1][gridColSize[gridSize - 1] - 1] + x;
}
