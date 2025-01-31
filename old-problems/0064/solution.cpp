#include <algorithm>
#include <vector>

class Solution {
 public:
  int minPathSum(std::vector<std::vector<int>>& grid) {
    for (std::size_t j{1}; j < grid[0].size(); ++j) {
      grid[0][j] += grid[0][j - 1];
    }

    for (std::size_t i{1}; i < grid.size(); ++i) {
      grid[i][0] += grid[i - 1][0];

      for (std::size_t j{1}; j < grid[i].size(); ++j) {
        grid[i][j] += std::min(grid[i - 1][j], grid[i][j - 1]);
      }
    }

    return grid.back().back();
  }
};
