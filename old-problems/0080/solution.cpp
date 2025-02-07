#include <vector>

class Solution {
 public:
  int removeDuplicates(std::vector<int>& nums) {
    if (nums.size() <= 2) return nums.size();
    std::size_t n{2};
    for (std::size_t i{2}; i < nums.size(); ++i) {
      if (nums[i] != nums[n - 2]) {
        nums[n] = nums[i];
        ++n;
      }
    }
    return n;
  }
};
