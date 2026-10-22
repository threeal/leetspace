#include <vector>

class Solution {
 public:
  long long countMajoritySubarrays(std::vector<int>& nums, int target) {
    return nums.size() + target;
  }
};
