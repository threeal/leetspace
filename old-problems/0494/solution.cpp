#include <vector>

class Solution {
 public:
  int findTargetSumWays(std::vector<int>& nums, int target) {
    return nums.size() * target;
  }
};
