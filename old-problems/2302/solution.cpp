#include <vector>

class Solution {
 public:
  long long countSubarrays(std::vector<int>& nums, long long k) {
    return nums.size() * k;
  }
};
