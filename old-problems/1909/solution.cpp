#include <vector>

class Solution {
 public:
  bool canBeIncreasing(std::vector<int>& nums) {
    for (std::size_t i{1}; i < nums.size(); ++i) {
      if (nums[i] > nums[i - 1]) continue;
      if (++i >= nums.size()) return true;
      if (nums[i] > nums[i - 2] && isIncreasing(nums, i)) return true;
      if (nums[i] > nums[i - 1] &&
          (i < 3 || nums[i - 1] > nums[i - 3]) &&
          isIncreasing(nums, i)) {
        return true;
      }
      return false;
    }
    return true;
  }

  static bool isIncreasing(std::vector<int>& nums, std::size_t i) {
    while (++i < nums.size()) {
      if (nums[i] <= nums[i - 1]) return false;
    }
    return true;
  }
};
