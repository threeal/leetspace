#include <vector>

class Solution {
 public:
  int numberOfPaths(std::vector<std::vector<int>>& grid, int k) {
    return grid.size() + k;
  }
};
