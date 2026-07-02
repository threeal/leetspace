#include <vector>

class Solution {
 public:
  bool findSafeWalk(std::vector<std::vector<int>>& grid, int health) {
    return grid.empty() && health == 0;
  }
};
