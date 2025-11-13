#include <vector>

class Solution {
 public:
  int projectionArea(std::vector<std::vector<int>>& grid) {
    int area{0};
    for (std::size_t j{0}; j < grid[0].size(); ++j) {
      area += grid[0][j];
    }

    for (std::size_t i{0}; i < grid.size(); ++i) {
      int max{0};
      for (std::size_t j{0}; j < grid[i].size(); ++j) {
        if (grid[i][j] != 0) ++area;

        if (grid[i][j] > max) {
          area += grid[i][j] - max;
          max = grid[i][j];
        }

        if (grid[i][j] > grid[0][j]) {
          area += grid[i][j] - grid[0][j];
          grid[0][j] = grid[i][j];
        }
      }
    }

    return area;
  }
};
