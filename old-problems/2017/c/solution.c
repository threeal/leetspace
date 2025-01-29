long long gridGame(int** grid, int gridSize, int* gridColSize) {
  (void)gridSize;

  long long top = 0;
  for (int i = 1; i < gridColSize[0]; ++i) {
    top += grid[0][i];
  }

  long long min = top, bottom = 0;
  for (int i = 1; i < gridColSize[0]; ++i) {
    top -= grid[0][i];
    bottom += grid[1][i - 1];
    if (top > bottom) {
      if (top < min) min = top;
    } else {
      if (bottom < min) min = bottom;
    }
  }

  return min;
}
