int minFlips(int** grid, int gridSize, int* gridColSize) {
  int rowInvalids = 0;
  for (int i = 0; i < gridSize; ++i) {
    for (int l = 0, r = gridColSize[i] - 1; l < r; ++l, --r) {
      if (grid[i][l] != grid[i][r]) ++rowInvalids;
    }
  }

  int colInvalids = 0;
  for (int i = 0; i < gridColSize[0]; ++i) {
    for (int l = 0, r = gridSize - 1; l < r; ++l, --r) {
      if (grid[l][i] != grid[r][i]) ++colInvalids;
    }
  }

  return rowInvalids <= colInvalids ? rowInvalids : colInvalids;
}
