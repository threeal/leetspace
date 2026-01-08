#include <vector>

class Solution {
 public:
  int numEnclaves(std::vector<std::vector<int>>& grid) {
    int count{0};
    for (const auto& row : grid) {
      for (int val : row) {
        if (val == 0) ++count;
      }
    }

    for (std::size_t i{0}; i < grid.size(); ++i) {
      if (grid[i][0] == 1) count += explore(grid, i, 0);

      if (grid[i][grid[i].size() - 1] == 1) {
        count += explore(grid, i, grid[i].size() - 1);
      }
    }

    for (std::size_t i{0}; i < grid[0].size(); ++i) {
      if (grid[0][i] == 1) count += explore(grid, 0, i);

      if (grid[grid.size() - 1][i] == 1) {
        count += explore(grid, grid.size() - 1, i);
      }
    }

    return grid.size() * grid[0].size() - count;
  }

  static int explore(
      std::vector<std::vector<int>>& grid, std::size_t y, std::size_t x) {
    int count{1};
    grid[y][x] = 0;

    if (y > 0 && grid[y - 1][x] == 1) count += explore(grid, y - 1, x);

    if (y + 1 < grid.size() && grid[y + 1][x] == 1) {
      count += explore(grid, y + 1, x);
    }

    if (x > 0 && grid[y][x - 1] == 1) count += explore(grid, y, x - 1);

    if (x + 1 < grid[y].size() && grid[y][x + 1] == 1) {
      count += explore(grid, y, x + 1);
    }

    return count;
  }
};
