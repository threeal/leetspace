#include <cstdlib>
#include <vector>

class Solution {
 public:
  int maximumScore(std::vector<int>& nums, std::vector<int>& multipliers) {
    std::vector<int> memo(multipliers.size() + 1, 0);
    for (int i = multipliers.size() - 1; i >= 0; --i) {
      for (int left = 0, right = nums.size() - i - 1; left <= i; ++left, ++right) {
        memo[left] = std::max(
            nums[left] * multipliers[i] + memo[left + 1],
            nums[right] * multipliers[i] + memo[left]);
      }
    }
    return memo[0];
  }
};
