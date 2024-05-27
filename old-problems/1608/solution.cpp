#include <vector>

class Solution {
 public:
  int specialArray(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());

    if (nums[0] >= static_cast<int>(nums.size())) return nums.size();

    for (std::size_t i{1}; i < nums.size(); ++i) {
      const int x = nums.size() - i;
      if (nums[i] >= x && nums[i - 1] < x) return x;
    }

    return -1;
  }
};
