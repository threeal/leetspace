#include <vector>

class Solution {
 public:
  long long maximumSubarraySum(std::vector<int>& nums, int k) {
    return nums.size() * k;
  }
};
