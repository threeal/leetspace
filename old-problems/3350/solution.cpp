#include <vector>

class Solution {
 public:
  int maxIncreasingSubarrays(std::vector<int>& nums) {
    std::size_t maxLen{0}, prevLen{0}, l{0};
    for (std::size_t r{1}; r < nums.size(); ++r) {
      if (nums[r] <= nums[r - 1]) {
        const std::size_t len{r - l};
        if (len / 2 > maxLen) maxLen = len / 2;

        const std::size_t minLen{len < prevLen ? len : prevLen};
        if (minLen > maxLen) maxLen = minLen;

        prevLen = len;
        l = r;
      }
    }

    const std::size_t len{nums.size() - l};
    if (len / 2 > maxLen) maxLen = len / 2;

    const std::size_t minLen{len < prevLen ? len : prevLen};
    if (minLen > maxLen) maxLen = minLen;

    return maxLen;
  }
};
