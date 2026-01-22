static int explore(int** grid, int gridSize, int* gridColSize, int y, int x);

int numEnclaves(int** grid, int gridSize, int* gridColSize) {
  int count = 0;
  for (int i = 0; i < gridSize; ++i) {
    for (int j = 0; j < gridColSize[i]; ++j) {
      if (grid[i][j] == 0) ++count;
    }
  }

  for (int i = 0; i < gridSize; ++i) {
    if (grid[i][0] == 1) count += explore(grid, gridSize, gridColSize, i, 0);

    if (grid[i][gridColSize[i] - 1] == 1) {
      count += explore(grid, gridSize, gridColSize, i, gridColSize[i] - 1);
    }
  }

  for (int i = 0; i < gridColSize[0]; ++i) {
    if (grid[0][i] == 1) count += explore(grid, gridSize, gridColSize, 0, i);

    if (grid[gridSize - 1][i] == 1) {
      count += explore(grid, gridSize, gridColSize, gridSize - 1, i);
    }
  }

  return gridSize * gridColSize[0] - count;
}

static int explore(int** grid, int gridSize, int* gridColSize, int y, int x) {
  int count = 1;
  grid[y][x] = 0;

  if (y > 0 && grid[y - 1][x] == 1) {
    count += explore(grid, gridSize, gridColSize, y - 1, x);
  }

  if (y + 1 < gridSize && grid[y + 1][x] == 1) {
    count += explore(grid, gridSize, gridColSize, y + 1, x);
  }

  if (x > 0 && grid[y][x - 1] == 1) {
    count += explore(grid, gridSize, gridColSize, y, x - 1);
  }

  if (x + 1 < gridColSize[y] && grid[y][x + 1] == 1) {
    count += explore(grid, gridSize, gridColSize, y, x + 1);
  }

  return count;
}
