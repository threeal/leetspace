#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> combine(int n, int k) {
    return std::vector(n, std::vector(k, 0));
  }
};
