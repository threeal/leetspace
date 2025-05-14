#include <vector>

class Solution {
 public:
  int uniquePathsIII(std::vector<std::vector<int>>& grid) {
    std::size_t sy{}, sx{}, ty{}, tx{};
    int empties{1};
    for (std::size_t y{0}; y < grid.size(); ++y) {
      for (std::size_t x{0}; x < grid[y].size(); ++x) {
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
    return backtrack(grid, sy, sx, ty, tx, empties);
  }

 private:
  static int backtrack(
      std::vector<std::vector<int>>& grid, std::size_t y, std::size_t x,
      std::size_t ty, std::size_t tx, int empties) {
    if (y == ty && x == tx) {
      return empties == 0 ? 1 : 0;
    }

    int count{0};

    if (y > 0 && grid[y - 1][x] == 0) {
      grid[y - 1][x] = -1;
      count += backtrack(grid, y - 1, x, ty, tx, empties - 1);
      grid[y - 1][x] = 0;
    }

    if (y + 1 < grid.size() && grid[y + 1][x] == 0) {
      grid[y + 1][x] = -1;
      count += backtrack(grid, y + 1, x, ty, tx, empties - 1);
      grid[y + 1][x] = 0;
    }

    if (x > 0 && grid[y][x - 1] == 0) {
      grid[y][x - 1] = -1;
      count += backtrack(grid, y, x - 1, ty, tx, empties - 1);
      grid[y][x - 1] = 0;
    }

    if (x + 1 < grid[y].size() && grid[y][x + 1] == 0) {
      grid[y][x + 1] = -1;
      count += backtrack(grid, y, x + 1, ty, tx, empties - 1);
      grid[y][x + 1] = 0;
    }

    return count;
  }
};
