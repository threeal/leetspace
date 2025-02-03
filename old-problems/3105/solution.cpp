#include <vector>

class Solution {
 public:
  int longestMonotonicSubarray(std::vector<int>& nums) {
    std::size_t longest{1};
    for (std::size_t l1{0}, l2{0}, r{1}; r < nums.size(); ++r) {
      if (nums[r] <= nums[r - 1]) {
        l1 = r;
      } else if (r - l1 + 1 > longest) {
        longest = r - l1 + 1;
      }

      if (nums[r] >= nums[r - 1]) {
        l2 = r;
      } else if (r - l2 + 1 > longest) {
        longest = r - l2 + 1;
      }
    }
    return longest;
  }
};
