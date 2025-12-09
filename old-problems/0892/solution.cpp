#include <cstdlib>
#include <vector>

class Solution {
 public:
  int surfaceArea(std::vector<std::vector<int>>& grid) {
    int area{0};

    if (grid.front().front() != 0) area += 2;
    area += 2 * grid.front().front() +
        grid.front().back() + grid.back().front();

    for (std::size_t j{1}; j < grid.front().size(); ++j) {
      if (grid.front()[j] != 0) area += 2;
      area += grid.front()[j] + grid.back()[j] +
          std::abs(grid.front()[j] - grid.front()[j - 1]);
    }

    for (std::size_t i{1}; i < grid.size(); ++i) {
      if (grid[i].front() != 0) area += 2;
      area += grid[i].front() + grid[i].back() +
          std::abs(grid[i].front() - grid[i - 1].front());

      for (std::size_t j{1}; j < grid[i].size(); ++j) {
        if (grid[i][j] != 0) area += 2;
        area += std::abs(grid[i][j] - grid[i - 1][j]) +
            std::abs(grid[i][j] - grid[i][j - 1]);
      }
    }

    return area;
  }
};
