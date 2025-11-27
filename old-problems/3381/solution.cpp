#include <vector>

class Solution {
 public:
  long long maxSubarraySum(std::vector<int>& nums, int k) {
    return nums.size() + k;
  }
};
