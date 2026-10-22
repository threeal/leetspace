#include <vector>

class Solution {
 public:
  int firstStableIndex(std::vector<int>& nums, int k) {
    std::vector<int> mins{nums};
    for (std::size_t i{mins.size() - 1}; i > 0; --i) {
      if (mins[i] < mins[i - 1]) mins[i - 1] = mins[i];
    }

    int max{0};
    for (std::size_t i{0}; i < nums.size(); ++i) {
      if (nums[i] > max) max = nums[i];
      if (max - mins[i] <= k) return i;
    }

    return -1;
  }
};
