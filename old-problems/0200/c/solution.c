void submergeIsland(char** grid, int gridSize, int* gridColSize, int y, int x);

int numIslands(char** grid, int gridSize, int* gridColSize) {
  int islands = 0;

  for (int y = 0; y < gridSize; ++y) {
    for (int x = 0; x < gridColSize[y]; ++x) {
      if (grid[y][x] == '1') {
        ++islands;
        submergeIsland(grid, gridSize, gridColSize, y, x);
      }
    }
  }

  return islands;
}

void submergeIsland(char** grid, int gridSize, int* gridColSize, int y, int x) {
  grid[y][x] = '0';
  if (x > 0 && grid[y][x - 1] == '1') submergeIsland(grid, gridSize, gridColSize, y, x - 1);
  if (x < gridColSize[y] - 1 && grid[y][x + 1] == '1') submergeIsland(grid, gridSize, gridColSize, y, x + 1);
  if (y > 0 && grid[y - 1][x] == '1') submergeIsland(grid, gridSize, gridColSize, y - 1, x);
  if (y < gridSize - 1 && grid[y + 1][x] == '1') submergeIsland(grid, gridSize, gridColSize, y + 1, x);
}
