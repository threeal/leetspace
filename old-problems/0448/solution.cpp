#include <vector>

class Solution {
 public:
  std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
    for (std::size_t i{0}; i < nums.size(); ++i) {
      const int idx{nums[i] > 0 ? nums[i] - 1 : -nums[i] - 1};
      if (nums[idx] > 0) nums[idx] = -nums[idx];
    }

    std::size_t numsSize{0};
    for (std::size_t i{0}; i < nums.size(); ++i) {
      if (nums[i] > 0) nums[numsSize++] = i + 1;
    }

    nums.resize(numsSize);
    return nums;
  }
};
