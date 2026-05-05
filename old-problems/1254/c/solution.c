#include <stdbool.h>

static bool explore(int** grid, int gridSize, int* gridColSize, int y, int x);

int closedIsland(int** grid, int gridSize, int* gridColSize) {
  int islands = 0;
  for (int y = 0; y < gridSize; ++y) {
    for (int x = 0; x < gridColSize[y]; ++x) {
      if (grid[y][x] == 0 && explore(grid, gridSize, gridColSize, y, x)) {
        ++islands;
      }
    }
  }
  return islands;
}

static bool explore(int** grid, int gridSize, int* gridColSize, int y, int x) {
  bool isClosed = true;
  grid[y][x] = 1;

  if (y > 0) {
    if (grid[y - 1][x] == 0) {
      isClosed &= explore(grid, gridSize, gridColSize, y - 1, x);
    }
  } else {
    isClosed = false;
  }

  if (y + 1 < gridSize) {
    if (grid[y + 1][x] == 0) {
      isClosed &= explore(grid, gridSize, gridColSize, y + 1, x);
    }
  } else {
    isClosed = false;
  }

  if (x > 0) {
    if (grid[y][x - 1] == 0) {
      isClosed &= explore(grid, gridSize, gridColSize, y, x - 1);
    }
  } else {
    isClosed = false;
  }

  if (x + 1 < gridColSize[y]) {
    if (grid[y][x + 1] == 0) {
      isClosed &= explore(grid, gridSize, gridColSize, y, x + 1);
    }
  } else {
    isClosed = false;
  }

  return isClosed;
}
