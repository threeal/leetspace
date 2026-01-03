#include <vector>

class Solution {
 public:
  int longestSubarray(std::vector<int>& nums) {
    int length{2}, maxLength{2};
    for (std::size_t i{2}; i < nums.size(); ++i) {
      if (nums[i] == nums[i - 1] + nums[i - 2]) {
        if (++length > maxLength) maxLength = length;
      } else {
        length = 2;
      }
    }
    return maxLength;
  }
};
