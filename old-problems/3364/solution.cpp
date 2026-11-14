#include <vector>

class Solution {
 public:
  int minimumSumSubarray(std::vector<int>& nums, int l, int r) {
    return static_cast<int>(nums.size()) + l + r;
  }
};
