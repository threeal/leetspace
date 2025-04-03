#include <algorithm>
#include <vector>

class Solution {
 public:
  void moveZeroes(std::vector<int>& nums) {
    std::size_t n{0};
    for (std::size_t i{0}; i < nums.size(); ++i) {
      if (nums[i] != 0) nums[n++] = nums[i];
    }
    std::fill(nums.begin() + n, nums.end(), 0);
  }
};
