static int backtrack(
    int** grid, int gridSize, int* gridColSize,
    int y, int x, int ty, int tx, int empties);

int uniquePathsIII(int** grid, int gridSize, int* gridColSize) {
  int sy, sx, ty, tx, empties = 1;
  for (int y = 0; y < gridSize; ++y) {
    for (int x = 0; x < gridColSize[y]; ++x) {
      if (grid[y][x] == 0) {
        ++empties;
      } else if (grid[y][x] != -1) {
        if (grid[y][x] == 1) {
          grid[y][x] = -1;
          sy = y;
          sx = x;
        } else {
          grid[y][x] = 0;
          ty = y;
          tx = x;
        }
      }
    }
  }

  return backtrack(grid, gridSize, gridColSize, sy, sx, ty, tx, empties);
}

static int backtrack(
    int** grid, int gridSize, int* gridColSize,
    int y, int x, int ty, int tx, int empties) {
  if (y == ty && x == tx) {
    return empties == 0 ? 1 : 0;
  }

  int count = 0;

  if (y > 0 && grid[y - 1][x] == 0) {
    grid[y - 1][x] = -1;
    count += backtrack(
        grid, gridSize, gridColSize, y - 1, x, ty, tx, empties - 1);
    grid[y - 1][x] = 0;
  }

  if (y + 1 < gridSize && grid[y + 1][x] == 0) {
    grid[y + 1][x] = -1;
    count += backtrack(
        grid, gridSize, gridColSize, y + 1, x, ty, tx, empties - 1);
    grid[y + 1][x] = 0;
  }

  if (x > 0 && grid[y][x - 1] == 0) {
    grid[y][x - 1] = -1;
    count += backtrack(
        grid, gridSize, gridColSize, y, x - 1, ty, tx, empties - 1);
    grid[y][x - 1] = 0;
  }

  if (x + 1 < gridColSize[y] && grid[y][x + 1] == 0) {
    grid[y][x + 1] = -1;
    count += backtrack(
        grid, gridSize, gridColSize, y, x + 1, ty, tx, empties - 1);
    grid[y][x + 1] = 0;
  }

  return count;
}
