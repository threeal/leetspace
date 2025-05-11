#include <algorithm>
#include <vector>

class Solution {
 public:
  int maxIncreaseKeepingSkyline(std::vector<std::vector<int>>& grid) {
    std::vector<int> rowMax(grid.size(), 0);
    for (std::size_t i{0}; i < rowMax.size(); ++i) {
      int maxHeight{0};
      for (const int height : grid[i]) {
        if (height > maxHeight) maxHeight = height;
      }
      rowMax[i] = maxHeight;
    }

    std::vector<int> colMax(grid[0].size(), 0);
    for (std::size_t j{0}; j < colMax.size(); ++j) {
      int maxHeight{0};
      for (std::size_t i{0}; i < grid.size(); ++i) {
        if (grid[i][j] > maxHeight) maxHeight = grid[i][j];
      }
      colMax[j] = maxHeight;
    }

    int sum{0};
    for (std::size_t i{0}; i < rowMax.size(); ++i) {
      for (std::size_t j{0}; j < colMax.size(); ++j) {
        sum += std::min(rowMax[i], colMax[j]) - grid[i][j];
      }
    }

    return sum;
  }
};
