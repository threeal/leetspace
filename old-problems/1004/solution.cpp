#include <vector>

class Solution {
 public:
  int longestOnes(std::vector<int>& nums, int k) {
    std::size_t maxLength{0};
    int zeros{0};
    for (std::size_t l{0}, r{0}; r < nums.size(); ++r) {
      if (nums[r] == 0) ++zeros;
      while (zeros > k) {
        if (nums[l] == 0) --zeros;
        ++l;
      }
      const std::size_t length{r + 1 - l};
      if (length > maxLength) maxLength = length;
    }
    return maxLength;
  }
};
