#include <vector>

class Solution {
 public:
  int maxSum(std::vector<std::vector<int>>& grid) {
    int max{0};
    for (std::size_t i{2}; i < grid.size(); ++i) {
      for (std::size_t j{2}; j < grid[i].size(); ++j) {
        const int sum{
            grid[i - 2][j - 2] + grid[i - 2][j - 1] + grid[i - 2][j] +
            grid[i - 1][j - 1] +
            grid[i][j - 2] + grid[i][j - 1] + grid[i][j]};
        if (sum > max) max = sum;
      }
    }
    return max;
  }
};
