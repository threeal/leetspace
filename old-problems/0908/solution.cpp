#include <algorithm>
#include <vector>

class Solution {
 public:
  int smallestRangeI(std::vector<int>& nums, int k) {
    int min{10001};
    int max{-1};
    for (const auto num : nums) {
      if (num > max) max = num;
      if (num < min) min = num;
    }

    return std::max(max - min - k - k, 0);
  }
};
