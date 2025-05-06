#include <algorithm>
#include <limits>
#include <vector>

class Solution {
 public:
  double minimumAverage(std::vector<int>& nums) {
    int minimum{std::numeric_limits<int>::max()};
    std::sort(nums.begin(), nums.end());
    for (std::size_t l{0}, r{nums.size() - 1}; l < r; ++l, --r) {
      if (nums[r] + nums[l] < minimum) minimum = nums[r] + nums[l];
    }
    return static_cast<double>(minimum) / 2.0;
  }
};
