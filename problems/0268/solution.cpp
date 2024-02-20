#include <algorithm>
#include <vector>

class Solution {
 public:
  int missingNumber(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
      if (nums[i] != i) return i;
    }
    return nums.size();
  }
};
