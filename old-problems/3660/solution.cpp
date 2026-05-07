#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<int> maxValue(std::vector<int>& nums) {
    const std::size_t n{nums.size()};
    std::vector<int> maxs(n);
    std::vector<int> mins(n);

    maxs[0] = nums[0];
    for (std::size_t i{1}; i < n; ++i) {
      maxs[i] = std::max(maxs[i - 1], nums[i]);
    }

    mins[n - 1] = nums[n - 1];
    nums[n - 1] = maxs[n - 1];

    for (std::size_t i{n - 1}; i > 0; --i) {
      mins[i - 1] = std::min(mins[i], nums[i - 1]);
      nums[i - 1] = maxs[i - 1] > mins[i] ? nums[i] : maxs[i - 1];
    }

    return nums;
  }
};
