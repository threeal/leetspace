#include <cstdlib>
#include <vector>

class Solution {
 public:
  int firstMissingPositive(std::vector<int>& nums) {
    const int n = nums.size();
    for (auto& num : nums) {
      if (num <= 0) num = n + 1;
    }

    for (const auto num : nums) {
      const auto i = std::abs(num);
      if (i <= n && nums[i - 1] > 0) {
        nums[i - 1] *= -1;
      }
    }

    for (int i = 0; i < n; ++i) {
      if (nums[i] > 0) return i + 1;
    }

    return n + 1;
  }
};
