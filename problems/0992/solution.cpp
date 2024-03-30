#include <vector>

class Solution {
 public:
  int subarraysWithKDistinct(std::vector<int>& nums, int k) {
    return nums.size() * k;
  }
};
