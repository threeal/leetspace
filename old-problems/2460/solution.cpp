#include <vector>

class Solution {
 public:
  std::vector<int> applyOperations(std::vector<int>& nums) {
    std::size_t i{0};
    for (std::size_t j{1}; j < nums.size(); ++j) {
      if (nums[j - 1] == 0) continue;
      if (nums[j - 1] == nums[j]) {
        nums[i++] = 2 * nums[j - 1];
        nums[j] = 0;
        ++j;
      } else {
        nums[i++] = nums[j - 1];
      }
    }
    if (nums.back() > 0) nums[i++] = nums.back();
    while (i < nums.size()) nums[i++] = 0;
    return nums;
  }
};
