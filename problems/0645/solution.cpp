#include <cstdlib>
#include <vector>

class Solution {
 public:
  std::vector<int> findErrorNums(std::vector<int>& nums) {
    int twice = 0;
    for (const auto num : nums) {
      if (nums[std::abs(num) - 1] < 0) {
        twice = std::abs(num);
      } else {
        nums[std::abs(num) - 1] *= -1;
      }
    }

    int missing = 0;
    for (std::size_t i = 0; i < nums.size(); ++i) {
      if (nums[i] > 0) {
        missing = i + 1;
        break;
      }
    }

    return {twice, missing};
  }
};
