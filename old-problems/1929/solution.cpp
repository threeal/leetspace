#include <vector>

class Solution {
 public:
  std::vector<int> getConcatenation(std::vector<int>& nums) {
    const std::size_t n{nums.size()};
    nums.resize(n * 2);
    for (std::size_t i{0}; i < n; ++i) nums[n + i] = nums[i];
    return nums;
  }
};
