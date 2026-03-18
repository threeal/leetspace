#include <algorithm>
#include <vector>

class Solution {
 public:
  int minimumDifference(std::vector<int>& nums, int k) {
    if (k == 1) return 0;

    std::sort(nums.begin(), nums.end());

    int minDiff{nums[k - 1] - nums[0]};
    for (std::size_t i = k + 1; i <= nums.size(); ++i) {
      const int diff{nums[i - 1] - nums[i - k]};
      if (diff < minDiff) minDiff = diff;
    }

    return minDiff;
  }
};
