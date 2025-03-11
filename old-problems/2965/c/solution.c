int* findMissingAndRepeatedValues(
    int** grid, int gridSize, int* gridColSize, int* returnSize) {
  *returnSize = gridColSize[gridSize - 1];
  return grid[gridSize - 1];
}
