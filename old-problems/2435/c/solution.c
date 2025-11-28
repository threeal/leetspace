int numberOfPaths(int** grid, int gridSize, int* gridColSize, int k) {
  return grid[gridSize - 1][gridColSize[gridSize - 1] - 1] + k;
}
