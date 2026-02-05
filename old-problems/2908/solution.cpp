#include <limits>
#include <vector>

class Solution {
 public:
  int minimumSum(std::vector<int>& nums) {
    std::vector<int> minNums{nums};
    for (std::size_t i{nums.size() - 1}; i > 0; --i) {
      if (minNums[i] < minNums[i - 1]) minNums[i - 1] = minNums[i];
    }

    int minSum{std::numeric_limits<int>::max()}, minNum{nums[0]};
    for (std::size_t i{2}; i < nums.size(); ++i) {
      if (nums[i - 1] > minNum && nums[i - 1] > minNums[i]) {
        const int sum = minNum + nums[i - 1] + minNums[i];
        if (sum < minSum) minSum = sum;
      }
      if (nums[i - 1] < minNum) minNum = nums[i - 1];
    }

    return minSum == std::numeric_limits<int>::max() ? -1 : minSum;
  }
};
