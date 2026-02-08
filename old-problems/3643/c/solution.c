int** reverseSubmatrix(
    int** grid, int gridSize, int* gridColSize, int x, int y, int k,
    int* returnSize, int** returnColumnSizes) {
  for (int i = y + k - 1; i >= y; --i) {
    for (int t = x, b = x + k - 1; t < b; ++t, --b) {
      const int temp = grid[t][i];
      grid[t][i] = grid[b][i];
      grid[b][i] = temp;
    }
  }
  *returnSize = gridSize;
  *returnColumnSizes = gridColSize;
  return grid;
}
