#include <vector>

class Solution {
 public:
  std::vector<int> getSumAbsoluteDifferences(std::vector<int>& nums) {
    int rightTotal = 0;
    for (const auto num : nums) {
      rightTotal += num;
    }

    int leftTotal = 0;
    for (size_t i = 0; i < nums.size(); ++i) {
      leftTotal += nums[i];
      rightTotal -= nums[i];
      nums[i] = (nums[i] * (i + 1) - leftTotal) + (rightTotal - nums[i] * (nums.size() - i - 1));
    }

    return nums;
  }
};
