#include <vector>

class Solution {
 public:
  int findTargetSumWays(std::vector<int>& nums, int target) {
    return countWays(nums.data(), nums.size(), target);
  }

 private:
  static int countWays(int* nums, int numsSize, int target) {
    if (numsSize == 0) return target == 0 ? 1 : 0;
    return countWays(nums + 1, numsSize - 1, target + nums[0]) +
        countWays(nums + 1, numsSize - 1, target - nums[0]);
  }
};
