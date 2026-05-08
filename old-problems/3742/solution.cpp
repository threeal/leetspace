#include <vector>

class Solution {
 public:
  int maxPathScore(std::vector<std::vector<int>>& grid, int k) {
    return grid.size() + k;
  }
};
