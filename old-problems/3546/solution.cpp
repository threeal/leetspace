#include <vector>

class Solution {
 public:
  bool canPartitionGrid(std::vector<std::vector<int>>& grid) {
    long long sum{0};
    for (const auto& row : grid) {
      for (const int val : row) {
        sum += val;
      }
    }

    long long top{0}, bottom{sum};
    for (std::size_t i{0}; i + 1 < grid.size(); ++i) {
      for (std::size_t j{0}; j < grid[i].size(); ++j) {
        top += grid[i][j];
        bottom -= grid[i][j];
      }

      if (top == bottom) return true;
    }

    long long left{0}, right{sum};
    for (std::size_t j{0}; j + 1 < grid[0].size(); ++j) {
      for (std::size_t i{0}; i < grid.size(); ++i) {
        left += grid[i][j];
        right -= grid[i][j];
      }

      if (left == right) return true;
    }

    return false;
  }
};
