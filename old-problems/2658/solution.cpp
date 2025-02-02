#include <algorithm>
#include <vector>

class Solution {
 public:
  int findMaxFish(std::vector<std::vector<int>>& grid) {
    int maxFish{0};
    for (std::size_t y{0}; y < grid.size(); ++y) {
      for (std::size_t x{0}; x < grid[y].size(); ++x) {
        if (grid[y][x] > 0) {
          maxFish = std::max(maxFish, exploreFish(grid, y, x));
        }
      }
    }
    return maxFish;
  }

 private:
  static int exploreFish(
      std::vector<std::vector<int>>& grid, std::size_t y, std::size_t x) {
    int fish{grid[y][x]};
    grid[y][x] = 0;

    if (y > 0 && grid[y - 1][x] > 0) {
      fish += exploreFish(grid, y - 1, x);
    }

    if (x > 0 && grid[y][x - 1] > 0) {
      fish += exploreFish(grid, y, x - 1);
    }

    if (y < grid.size() - 1 && grid[y + 1][x] > 0) {
      fish += exploreFish(grid, y + 1, x);
    }

    if (x < grid[y].size() - 1 && grid[y][x + 1] > 0) {
      fish += exploreFish(grid, y, x + 1);
    }

    return fish;
  }
};
