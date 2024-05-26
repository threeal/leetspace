int matrixScore(int** grid, int gridSize, int* gridColSizes) {
  const int gridColSize = gridColSizes[0];

  int score = (1 << (gridColSize - 1)) * gridSize;
  for (int j = 1; j < gridColSize; ++j) {
    int count = 0;
    for (int i = 0; i < gridSize; ++i) {
      if (grid[i][j] == grid[i][0]) ++count;
    }
    score += (1 << (gridColSize - j - 1)) * (count > gridSize - count ? count : gridSize - count);
  }

  return score;
}
