#include <vector>

class Solution {
 public:
  int countNegatives(std::vector<std::vector<int>>& grid) {
    const int n = grid[0].size() - 1;
    int count{0}, j{n};
    for (std::size_t i{0}; i < grid.size(); ++i) {
      while (j >= 0 && grid[i][j] < 0) --j;
      count += n - j;
    }
    return count;
  }
};
