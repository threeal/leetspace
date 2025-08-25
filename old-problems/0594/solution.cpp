#include <algorithm>
#include <vector>

class Solution {
 public:
  int findLHS(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());

    std::size_t maxLen{0};
    for (std::size_t l{0}, r{0}; r < nums.size(); ++r) {
      while (nums[l] + 1 < nums[r]) ++l;
      if (nums[l] + 1 == nums[r]) {
        if (r + 1 - l > maxLen) maxLen = r + 1 - l;
      }
    }

    return maxLen;
  }
};
