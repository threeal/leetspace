#include <algorithm>
#include <vector>

class Solution {
 public:
  int maximumCount(std::vector<int>& nums) {
    const auto positive = std::upper_bound(nums.begin(), nums.end(), 0);
    const auto negative = std::upper_bound(
        nums.rbegin(), nums.rend(), 0, std::greater<int>());

    return std::max(
        std::distance(positive, nums.end()),
        std::distance(negative, nums.rend()));
  }
};
