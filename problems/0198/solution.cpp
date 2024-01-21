#include <algorithm>
#include <vector>

class Solution {
 public:
  int rob(std::vector<int>& nums) {
    if (nums.size() >= 2) {
      nums[1] = std::max(nums[0], nums[1]);
      for (std::size_t i = 2; i < nums.size(); ++i) {
        nums[i] = std::max(
            nums[i] + nums[i - 2],
            nums[i - 1]);
      }
    }

    return nums.back();
  }
};
