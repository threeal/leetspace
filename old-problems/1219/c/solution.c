int getMaximumGoldFromCoordinate(int** grid, int gridSize, int* gridColSize, int y, int x);

int getMaximumGold(int** grid, int gridSize, int* gridColSize) {
  int maxGold = 0;
  for (int y = gridSize - 1; y >= 0; --y) {
    for (int x = gridColSize[y] - 1; x >= 0; --x) {
      const int gold = getMaximumGoldFromCoordinate(grid, gridSize, gridColSize, y, x);
      if (gold > maxGold) maxGold = gold;
    }
  }
  return maxGold;
}

int getMaximumGoldFromCoordinate(int** grid, int gridSize, int* gridColSize, int y, int x) {
  if (grid[y][x] == 0) return 0;

  const int currentGold = grid[y][x];
  int maxGold = currentGold;

  grid[y][x] = 0;

  if (y > 0) {
    const int gold = currentGold + getMaximumGoldFromCoordinate(grid, gridSize, gridColSize, y - 1, x);
    if (gold > maxGold) maxGold = gold;
  }

  if (x > 0) {
    const int gold = currentGold + getMaximumGoldFromCoordinate(grid, gridSize, gridColSize, y, x - 1);
    if (gold > maxGold) maxGold = gold;
  }

  if (y + 1 < gridSize) {
    const int gold = currentGold + getMaximumGoldFromCoordinate(grid, gridSize, gridColSize, y + 1, x);
    if (gold > maxGold) maxGold = gold;
  }

  if (x + 1 < gridColSize[y]) {
    const int gold = currentGold + getMaximumGoldFromCoordinate(grid, gridSize, gridColSize, y, x + 1);
    if (gold > maxGold) maxGold = gold;
  }

  grid[y][x] = currentGold;

  return maxGold;
}
