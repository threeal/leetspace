#include <cstdlib>
#include <vector>

class Solution {
 public:
  int maxValueAfterReverse(std::vector<int>& nums) {
    int maxDiff{0};
    for (std::size_t i{nums.size() - 1}; i > 0; --i) {
      const int diff{
          std::abs(nums[i] - nums[0]) - std::abs(nums[i] - nums[i - 1])};
      if (diff > maxDiff) maxDiff = diff;
    }

    int total{0};
    for (std::size_t i{1}; i < nums.size(); ++i) {
      const int current{std::abs(nums[i] - nums[i - 1])};
      const int diff{std::abs(nums[nums.size() - 1] - nums[i - 1]) - current};
      if (diff > maxDiff) maxDiff = diff;

      for (std::size_t j{nums.size() - 1}; j > i; --j) {
        const int diff{
            std::abs(nums[j] - nums[i]) +
            std::abs(nums[j - 1] - nums[i - 1]) -
            std::abs(nums[j] - nums[j - 1]) - current};
        if (diff > maxDiff) maxDiff = diff;
      }

      total += current;
    }
    return total + maxDiff;
  }
};
