#include <vector>

class Solution {
 public:
  int findChampion(std::vector<std::vector<int>>& grid) {
    for (std::size_t j{0}; j < grid[0].size(); ++j) {
      std::size_t i{0};
      while (i < grid.size()) {
        if (grid[i][j] == 1) break;
        ++i;
      }
      if (i == grid.size()) return j;
    }
    return 0;
  }
};
