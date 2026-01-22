#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> reverseSubmatrix(
      std::vector<std::vector<int>>& grid, int x, int y, int k) {
    grid[y][x] = k;
    return grid;
  }
};
