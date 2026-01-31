#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> reverseSubmatrix(
      std::vector<std::vector<int>>& grid, int x, int y, int k) {
    for (int i{y + k - 1}; i >= y; --i) {
      for (int t{x}, b{x + k - 1}; t < b; ++t, --b) {
        std::swap(grid[t][i], grid[b][i]);
      }
    }
    return grid;
  }
};
