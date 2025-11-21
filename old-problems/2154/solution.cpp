#include <algorithm>
#include <vector>

class Solution {
 public:
  int findFinalValue(std::vector<int>& nums, int original) {
    std::sort(nums.begin(), nums.end());

    std::size_t i{0};
    while (true) {
      while (i < nums.size() && nums[i] < original) ++i;
      if (i < nums.size() && nums[i] == original) {
        original *= 2;
      } else {
        break;
      }
    }

    return original;
  }
};
