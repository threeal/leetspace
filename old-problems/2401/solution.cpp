#include <vector>

class Solution {
 public:
  int longestNiceSubarray(std::vector<int>& nums) {
    int sum{nums[0]};
    std::size_t longest{1};
    for (std::size_t l{0}, r{1}; r < nums.size(); ++r) {
      while ((sum & nums[r]) != 0) {
        sum &= ~nums[l];
        ++l;
      }
      if (r - l + 1 > longest) longest = r - l + 1;
      sum |= nums[r];
    }
    return longest;
  }
};
