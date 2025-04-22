#include <vector>

class Solution {
 public:
  int maxCount(int m, int n, std::vector<std::vector<int>>& ops) {
    return m * n - ops.size();
  }
};
