#include <algorithm>
#include <limits>
#include <vector>

class Solution {
 public:
  int minFallingPathSum(std::vector<std::vector<int>>& grid) {
    for (std::size_t i{1}; i < grid.size(); ++i) {
      int minVals[2]{std::numeric_limits<int>::max(), std::numeric_limits<int>::max()};
      for (auto val : grid[i - 1]) {
        if (val < minVals[1]) {
          if (val <= minVals[0]) {
            minVals[1] = minVals[0];
            minVals[0] = val;
          } else {
            minVals[1] = val;
          }
        }
      }

      if (minVals[0] == minVals[1]) {
        for (auto& val : grid[i]) {
          val += minVals[0];
        }
      } else {
        for (std::size_t j{0}; j < grid[i].size(); ++j) {
          grid[i][j] += grid[i - 1][j] == minVals[0] ? minVals[1] : minVals[0];
        }
      }
    }

    return *std::min_element(grid.back().begin(), grid.back().end());
  }
};
