#include <algorithm>
#include <vector>

class Solution {
 public:
  int getMaximumGold(std::vector<std::vector<int>>& grid) {
    int maxGold{0};
    for (std::size_t y{0}; y < grid.size(); ++y) {
      for (std::size_t x{0}; x < grid[y].size(); ++x) {
        maxGold = std::max(maxGold, getMaximumGold(grid, y, x));
      }
    }
    return maxGold;
  }

  int getMaximumGold(std::vector<std::vector<int>>& grid, std::size_t y, std::size_t x) {
    if (grid[y][x] == 0) return 0;

    const int currentGold{grid[y][x]};
    int maxGold{currentGold};

    grid[y][x] = 0;

    if (y > 0) maxGold = std::max(maxGold, currentGold + getMaximumGold(grid, y - 1, x));
    if (x > 0) maxGold = std::max(maxGold, currentGold + getMaximumGold(grid, y, x - 1));
    if (y + 1 < grid.size()) maxGold = std::max(maxGold, currentGold + getMaximumGold(grid, y + 1, x));
    if (x + 1 < grid[y].size()) maxGold = std::max(maxGold, currentGold + getMaximumGold(grid, y, x + 1));

    grid[y][x] = currentGold;

    return maxGold;
  }
};
