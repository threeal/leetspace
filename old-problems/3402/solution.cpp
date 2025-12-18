#include <vector>

class Solution {
 public:
  int minimumOperations(std::vector<std::vector<int>>& grid) {
    int operations{0};
    for (std::size_t j{0}; j < grid[0].size(); ++j) {
      int prev{grid[0][j]};
      for (std::size_t i{1}; i < grid.size(); ++i) {
        if (grid[i][j] > prev) {
          prev = grid[i][j];
        } else {
          ++prev;
          operations += prev - grid[i][j];
        }
      }
    }
    return operations;
  }
};
