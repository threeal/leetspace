#include <stdbool.h>

enum dir_t {
  UP,
  DOWN,
  LEFT,
  RIGHT
};

static bool follow(int** grid, int gridSize, int* gridColSize, enum dir_t dir);

bool hasValidPath(int** grid, int gridSize, int* gridColSize) {
  switch (grid[0][0]) {
    case 1:
    case 6:
      return follow(grid, gridSize, gridColSize, RIGHT);

    case 2:
    case 3:
      return follow(grid, gridSize, gridColSize, DOWN);

    case 4:
      return follow(grid, gridSize, gridColSize, RIGHT) ||
          follow(grid, gridSize, gridColSize, DOWN);
  }
  return false;
}

static bool follow(int** grid, int gridSize, int* gridColSize, enum dir_t dir) {
  int i = 0, j = 0;
  const int ti = gridSize - 1, tj = gridColSize[ti] - 1;
  while (i != ti || j != tj) {
    grid[i][j] = -1;
    switch (dir) {
      case UP:
        if (i == 0) return false;
        switch (grid[--i][j]) {
          case 2:
            break;

          case 3:
            dir = LEFT;
            break;

          case 4:
            dir = RIGHT;
            break;

          default:
            return false;
        }
        break;

      case DOWN:
        if (i == ti) return false;
        switch (grid[++i][j]) {
          case 2:
            break;

          case 5:
            dir = LEFT;
            break;

          case 6:
            dir = RIGHT;
            break;

          default:
            return false;
        }
        break;

      case LEFT:
        if (j == 0) return false;
        switch (grid[i][--j]) {
          case 1:
            break;

          case 4:
            dir = DOWN;
            break;

          case 6:
            dir = UP;
            break;

          default:
            return false;
        }
        break;

      case RIGHT:
        if (j == tj) return false;
        switch (grid[i][++j]) {
          case 1:
            break;

          case 3:
            dir = DOWN;
            break;

          case 5:
            dir = UP;
            break;

          default:
            return false;
        }
        break;
    }
  }

  return true;
}
