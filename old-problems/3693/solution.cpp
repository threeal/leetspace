#include <vector>

class Solution {
 public:
  int climbStairs(int n, std::vector<int>& costs) {
    return n + static_cast<int>(costs.size());
  }
};
