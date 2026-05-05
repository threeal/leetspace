#include <vector>

class Solution {
 public:
  int closedIsland(std::vector<std::vector<int>>& grid) {
    int islands{0};
    for (std::size_t y{0}; y < grid.size(); ++y) {
      for (std::size_t x{0}; x < grid[y].size(); ++x) {
        if (grid[y][x] == 0 && explore(grid, y, x)) ++islands;
      }
    }
    return islands;
  }

 private:
  bool explore(std::vector<std::vector<int>>& grid, std::size_t y, std::size_t x) {
    bool isClosed{true};
    grid[y][x] = 1;

    if (y > 0) {
      if (grid[y - 1][x] == 0) isClosed &= explore(grid, y - 1, x);
    } else {
      isClosed = false;
    }

    if (y + 1 < grid.size()) {
      if (grid[y + 1][x] == 0) isClosed &= explore(grid, y + 1, x);
    } else {
      isClosed = false;
    }

    if (x > 0) {
      if (grid[y][x - 1] == 0) isClosed &= explore(grid, y, x - 1);
    } else {
      isClosed = false;
    }

    if (x + 1 < grid[y].size()) {
      if (grid[y][x + 1] == 0) isClosed &= explore(grid, y, x + 1);
    } else {
      isClosed = false;
    }

    return isClosed;
  }
};
