#include <vector>

class Solution {
 public:
  int countSubIslands(
      std::vector<std::vector<int>>& grid1,
      std::vector<std::vector<int>>& grid2) {
    return grid1.size() + grid2.size();
  }
};
