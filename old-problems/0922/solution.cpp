#include <vector>

class Solution {
 public:
  std::vector<int> sortArrayByParityII(std::vector<int>& nums) {
    std::size_t even{0}, odd{1};
    while (even < nums.size()) {
      while (even < nums.size() && nums[even] % 2 == 0) even += 2;
      if (even >= nums.size()) break;

      while (nums[odd] % 2 == 1) odd += 2;
      std::swap(nums[even], nums[odd]);
    }

    return nums;
  }
};
