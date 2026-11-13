#include <vector>

class Solution {
 public:
  long long countNonDecreasingSubarrays(std::vector<int>& nums, int k) {
    return static_cast<long long>(nums.size()) + k;
  }
};
