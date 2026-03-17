#include <vector>

class Solution {
 public:
  int scoreDifference(std::vector<int>& nums) {
    int diff{0};
    bool isActive{true};
    for (std::size_t i{0}; i < nums.size(); ++i) {
      if (nums[i] % 2 == 1) isActive = !isActive;
      if ((i + 1) % 6 == 0) isActive = !isActive;
      diff += isActive ? nums[i] : -nums[i];
    }
    return diff;
  }
};
