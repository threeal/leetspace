#include <vector>

class Solution {
 public:
  std::vector<int> concatWithReverse(std::vector<int>& nums) {
    const std::size_t n{nums.size()};
    nums.resize(n * 2);
    for (std::size_t i{0}; i < n; ++i) {
      nums[nums.size() - i - 1] = nums[i];
    }
    return nums;
  }
};
