#include <vector>

class Solution {
 public:
  int numIslands(std::vector<std::vector<char>>& grid) {
    int islands{0};

    for (std::size_t y{0}; y < grid.size(); ++y) {
      for (std::size_t x{0}; x < grid[y].size(); ++x) {
        if (grid[y][x] == '1') {
          ++islands;
          submergeIsland(grid, y, x);
        }
      }
    }

    return islands;
  }

  void submergeIsland(std::vector<std::vector<char>>& grid, std::size_t y, std::size_t x) {
    grid[y][x] = '0';
    if (x > 0 && grid[y][x - 1] == '1') submergeIsland(grid, y, x - 1);
    if (x < grid[y].size() - 1 && grid[y][x + 1] == '1') submergeIsland(grid, y, x + 1);
    if (y < grid.size() - 1 && grid[y + 1][x] == '1') submergeIsland(grid, y + 1, x);
  }
};
