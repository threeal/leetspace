#include <vector>

class Solution {
 public:
  bool check(std::vector<int>& nums) {
    for (std::size_t i{1}; i < nums.size(); ++i) {
      if (nums[i] < nums[i - 1]) {
        if (nums[i] > nums[0]) return false;
        for (++i; i < nums.size(); ++i) {
          if (nums[i] > nums[0] || nums[i] < nums[i - 1]) return false;
        }
      }
    }
    return true;
  }
};
