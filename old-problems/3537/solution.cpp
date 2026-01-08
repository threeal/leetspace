#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> specialGrid(int n) {
    return std::vector<std::vector<int>>(n, std::vector<int>(n, 0));
  }
};
