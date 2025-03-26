#include <vector>

class Solution {
 public:
  int minOperations(std::vector<std::vector<int>>& grid, int x) {
    return grid.size() + x;
  }
};
