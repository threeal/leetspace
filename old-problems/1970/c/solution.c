#include <stdbool.h>
#include <stdlib.h>

struct coord_t {
  int y;
  int x;
};

struct cell_t {
  bool isWater;
  struct coord_t leftParent;
  struct coord_t rightParent;
};

static struct coord_t directions[8] = {
    {-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}};

static struct coord_t findLeftParent(struct cell_t** grid, int y, int x);
static struct coord_t findRightParent(struct cell_t** grid, int y, int x);

int latestDayToCross(
    int row, int col, int** cells, int cellsSize, int* cellsColSize) {
  (void)cellsColSize;

  const int gridSize = row + 2;
  const int gridColSize = col + 2;

  struct cell_t** grid = malloc(gridSize * sizeof(struct cell_t*));
  for (int i = 0; i < gridSize; ++i) {
    grid[i] = malloc(gridColSize * sizeof(struct cell_t));
    for (int j = 0; j < gridColSize; ++j) {
      grid[i][j].isWater = false;
    }
  }

  for (int day = 0; day < cellsSize; ++day) {
    const int y = cells[day][0];
    const int x = cells[day][1];

    grid[y][x].isWater = true;
    grid[y][x].leftParent.y = y;
    grid[y][x].leftParent.x = x;
    grid[y][x].rightParent.y = y;
    grid[y][x].rightParent.x = x;

    for (int i = 0; i < 8; ++i) {
      const int yy = y + directions[i].y, xx = x + directions[i].x;
      if (grid[yy][xx].isWater) {
        const struct coord_t leftParent = findLeftParent(grid, yy, xx);
        if (leftParent.x < grid[y][x].leftParent.x) {
          grid[y][x].leftParent = leftParent;
        }

        const struct coord_t rightParent = findRightParent(grid, yy, xx);
        if (rightParent.x > grid[y][x].rightParent.x) {
          grid[y][x].rightParent = rightParent;
        }
      }
    }

    if (grid[y][x].leftParent.x == 1 && grid[y][x].rightParent.x == col) {
      for (int i = 0; i < gridSize; ++i) free(grid[i]);
      free(grid);
      return day;
    }

    for (int i = 0; i < 8; ++i) {
      const int yy = y + directions[i].y, xx = x + directions[i].x;
      if (grid[yy][xx].isWater) {
        const struct coord_t leftParent = findLeftParent(grid, yy, xx);
        if (leftParent.x >= grid[y][x].leftParent.x) {
          grid[leftParent.y][leftParent.x].leftParent = grid[y][x].leftParent;
        }

        const struct coord_t rightParent = findRightParent(grid, yy, xx);
        if (rightParent.x <= grid[y][x].rightParent.x) {
          grid[rightParent.y][rightParent.x].rightParent =
              grid[y][x].rightParent;
        }
      }
    }
  }

  for (int i = 0; i < gridSize; ++i) free(grid[i]);
  free(grid);

  return -1;
}

static struct coord_t findLeftParent(struct cell_t** grid, int y, int x) {
  const struct coord_t p = grid[y][x].leftParent;
  return (p.y != y || p.x != x)
      ? grid[y][x].leftParent = findLeftParent(grid, p.y, p.x)
      : p;
}

static struct coord_t findRightParent(struct cell_t** grid, int y, int x) {
  const struct coord_t p = grid[y][x].rightParent;
  return (p.y != y || p.x != x)
      ? grid[y][x].rightParent = findRightParent(grid, p.y, p.x)
      : p;
}
