#include <vector>

class Solution {
 public:
  long long countInterestingSubarrays(
      std::vector<int>& nums, int modulo, int k) {
    return nums.size() * modulo * k;
  }
};
