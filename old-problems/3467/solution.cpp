#include <vector>

class Solution {
 public:
  std::vector<int> transformArray(std::vector<int>& nums) {
    std::size_t l{0};
    for (std::size_t i{0}; i < nums.size(); ++i) {
      if (nums[i] % 2 == 0) nums[l++] = 0;
    }
    while (l < nums.size()) nums[l++] = 1;
    return nums;
  }
};
