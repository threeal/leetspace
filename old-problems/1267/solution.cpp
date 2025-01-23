#include <vector>

class Solution {
 public:
  int countServers(std::vector<std::vector<int>>& grid) {
    std::vector<int> rowCounts(grid.size(), 0);
    std::vector<int> colCounts(grid.front().size(), 0);

    for (std::size_t i{0}; i < grid.size(); ++i) {
      for (std::size_t j{0}; j < grid[i].size(); ++j) {
        if (grid[i][j] == 1) {
          ++rowCounts[i];
          ++colCounts[j];
        }
      }
    }

    int count{0};
    for (std::size_t i{0}; i < grid.size(); ++i) {
      if (rowCounts[i] > 1) {
        count += rowCounts[i];
      } else if (rowCounts[i] == 1) {
        for (std::size_t j{0}; j < grid[i].size(); ++j) {
          if (grid[i][j] == 1 && colCounts[j] > 1) ++count;
        }
      }
    }

    return count;
  }
};
