#include <algorithm>
#include <vector>

class Solution {
 public:
  int deleteGreatestValue(std::vector<std::vector<int>>& grid) {
    for (std::vector<int>& row : grid) {
      std::sort(row.begin(), row.end());
    }

    int sum{0};
    for (std::size_t j{0}; j < grid[0].size(); ++j) {
      int max{grid[0][j]};
      for (std::size_t i{1}; i < grid.size(); ++i) {
        if (grid[i][j] > max) max = grid[i][j];
      }
      sum += max;
    }

    return sum;
  }
};
