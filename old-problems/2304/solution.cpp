#include <vector>

class Solution {
 public:
  int minPathCost(
      std::vector<std::vector<int>>& grid,
      std::vector<std::vector<int>>& moveCost) {
    return grid.size() + moveCost.size();
  }
};
