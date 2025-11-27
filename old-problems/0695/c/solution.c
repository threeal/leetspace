static int explore(int** grid, int gridSize, int* gridColSize, int y, int x);

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize) {
  int maxArea = 0;
  for (int y = 0; y < gridSize; ++y) {
    for (int x = 0; x < gridColSize[y]; ++x) {
      if (grid[y][x] == 1) {
        const int area = explore(grid, gridSize, gridColSize, y, x);
        if (area > maxArea) maxArea = area;
      }
    }
  }
  return maxArea;
}

static int explore(int** grid, int gridSize, int* gridColSize, int y, int x) {
  grid[y][x] = 0;
  int area = 1;

  if (y > 0 && grid[y - 1][x] == 1) {
    area += explore(grid, gridSize, gridColSize, y - 1, x);
  }

  if (y + 1 < gridSize && grid[y + 1][x] == 1) {
    area += explore(grid, gridSize, gridColSize, y + 1, x);
  }

  if (x > 0 && grid[y][x - 1] == 1) {
    area += explore(grid, gridSize, gridColSize, y, x - 1);
  }

  if (x + 1 < gridColSize[y] && grid[y][x + 1] == 1) {
    area += explore(grid, gridSize, gridColSize, y, x + 1);
  }

  return area;
}
