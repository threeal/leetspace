#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> generateMatrix(int n) {
    return std::vector<std::vector<int>>(n, std::vector<int>(n, 0));
  }
};
