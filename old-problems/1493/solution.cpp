#include <vector>

class Solution {
 public:
  int longestSubarray(std::vector<int>& nums) {
    std::size_t i{0};
    while (i < nums.size() && nums[i] == 1) ++i;

    if (i == nums.size()) return i - 1;

    int count{0}, maxCount = i, prev = i;
    while (++i < nums.size()) {
      if (nums[i] == 0) {
        if (prev + count > maxCount) maxCount = prev + count;
        prev = count;
        count = 0;
      } else {
        ++count;
      }
    }

    return prev + count > maxCount ? prev + count : maxCount;
  }
};
