static int exploreFish(
    int** grid, int gridSize, int* gridColSize, int y, int x);

int findMaxFish(int** grid, int gridSize, int* gridColSize) {
  int maxFish = 0;
  for (int y = 0; y < gridSize; ++y) {
    for (int x = 0; x < gridColSize[y]; ++x) {
      if (grid[y][x] > 0) {
        const int fish = exploreFish(grid, gridSize, gridColSize, y, x);
        if (fish > maxFish) maxFish = fish;
      }
    }
  }
  return maxFish;
}

static int exploreFish(
    int** grid, int gridSize, int* gridColSize, int y, int x) {
  int fish = grid[y][x];
  grid[y][x] = 0;

  if (y > 0 && grid[y - 1][x] > 0) {
    fish += exploreFish(grid, gridSize, gridColSize, y - 1, x);
  }

  if (x > 0 && grid[y][x - 1] > 0) {
    fish += exploreFish(grid, gridSize, gridColSize, y, x - 1);
  }

  if (y < gridSize - 1 && grid[y + 1][x] > 0) {
    fish += exploreFish(grid, gridSize, gridColSize, y + 1, x);
  }

  if (x < gridColSize[y] - 1 && grid[y][x + 1] > 0) {
    fish += exploreFish(grid, gridSize, gridColSize, y, x + 1);
  }

  return fish;
}
