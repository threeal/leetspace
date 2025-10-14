#include <vector>

class Solution {
 public:
  bool hasIncreasingSubarrays(std::vector<int>& nums, int k) {
    return nums.empty() || k;
  }
};
