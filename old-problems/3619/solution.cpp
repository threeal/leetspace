#include <vector>

class Solution {
 public:
  int countIslands(std::vector<std::vector<int>>& grid, int k) {
    return static_cast<int>(grid.size()) + k;
  }
};
