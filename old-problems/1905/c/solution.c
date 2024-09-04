#include <stdbool.h>

void exploreIsland(int** grid, int gridSize, int* gridColSize, int y, int x);

bool exploreSubisland(
    int** grid1, int grid1Size, int* grid1ColSize,
    int** grid2, int grid2Size, int* grid2ColSize, int y, int x);

int countSubIslands(
    int** grid1, int grid1Size, int* grid1ColSize,
    int** grid2, int grid2Size, int* grid2ColSize) {
  int count = 0;
  for (int y = 0; y < grid2Size; ++y) {
    for (int x = 0; x < grid2ColSize[y]; ++x) {
      if (grid2[y][x] == 0) continue;
      const bool isSubisland = exploreSubisland(
          grid1, grid1Size, grid1ColSize,
          grid2, grid2Size, grid2ColSize, y, x);
      if (isSubisland) ++count;
    }
  }

  return count;
}

bool exploreSubisland(
    int** grid1, int grid1Size, int* grid1ColSize,
    int** grid2, int grid2Size, int* grid2ColSize, int y, int x) {
  grid2[y][x] = 0;
  bool isSubisland = grid1[y][x] != 0;

  if (y > 0 && grid2[y - 1][x] != 0) {
    if (isSubisland) {
      isSubisland = exploreSubisland(
          grid1, grid1Size, grid1ColSize,
          grid2, grid2Size, grid2ColSize, y - 1, x);
    } else {
      exploreIsland(grid2, grid2Size, grid2ColSize, y - 1, x);
    }
  }

  if (y < grid2Size - 1 && grid2[y + 1][x] != 0) {
    if (isSubisland) {
      isSubisland = exploreSubisland(
          grid1, grid1Size, grid1ColSize,
          grid2, grid2Size, grid2ColSize, y + 1, x);
    } else {
      exploreIsland(grid2, grid2Size, grid2ColSize, y + 1, x);
    }
  }

  if (x > 0 && grid2[y][x - 1] != 0) {
    if (isSubisland) {
      isSubisland = exploreSubisland(
          grid1, grid1Size, grid1ColSize,
          grid2, grid2Size, grid2ColSize, y, x - 1);
    } else {
      exploreIsland(grid2, grid2Size, grid2ColSize, y, x - 1);
    }
  }

  if (x < grid2ColSize[y] - 1 && grid2[y][x + 1] != 0) {
    if (isSubisland) {
      isSubisland = exploreSubisland(
          grid1, grid1Size, grid1ColSize,
          grid2, grid2Size, grid2ColSize, y, x + 1);
    } else {
      exploreIsland(grid2, grid2Size, grid2ColSize, y, x + 1);
    }
  }

  return isSubisland;
}

void exploreIsland(int** grid, int gridSize, int* gridColSize, int y, int x) {
  grid[y][x] = 0;

  if (y > 0 && grid[y - 1][x] != 0) {
    exploreIsland(grid, gridSize, gridColSize, y - 1, x);
  }

  if (y < gridSize - 1 && grid[y + 1][x] != 0) {
    exploreIsland(grid, gridSize, gridColSize, y + 1, x);
  }

  if (x > 0 && grid[y][x - 1] != 0) {
    exploreIsland(grid, gridSize, gridColSize, y, x - 1);
  }

  if (x < gridColSize[y] - 1 && grid[y][x + 1] != 0) {
    exploreIsland(grid, gridSize, gridColSize, y, x + 1);
  }
}
