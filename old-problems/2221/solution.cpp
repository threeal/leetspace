#include <vector>

class Solution {
 public:
  int triangularSum(std::vector<int>& nums) {
    for (std::size_t n{nums.size()}; n > 1; --n) {
      for (std::size_t i{1}; i < n; ++i) {
        nums[i - 1] = (nums[i - 1] + nums[i]) % 10;
      }
    }
    return nums.front();
  }
};
