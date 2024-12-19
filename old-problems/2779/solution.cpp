#include <algorithm>
#include <vector>

class Solution {
 public:
  int maximumBeauty(std::vector<int>& nums, int k) {
    std::sort(nums.begin(), nums.end());

    std::size_t max{1};
    for (std::size_t i{0}, j{1}; j < nums.size(); ++i) {
      while (j < nums.size() && nums[j] <= nums[i] + k * 2) ++j;
      if (j - i > max) max = j - i;
    }
    return max;
  }
};
