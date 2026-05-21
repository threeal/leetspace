#include <algorithm>
#include <vector>

class Solution {
 public:
  int firstStableIndex(std::vector<int>& nums, int k) {
    std::vector<int> mins(nums.size());

    mins[nums.size() - 1] = nums[nums.size() - 1];
    for (std::size_t i{nums.size() - 1}; i > 0; --i) {
      mins[i - 1] = std::min(nums[i - 1], mins[i]);
    }

    int max{0};
    for (std::size_t i{0}; i < nums.size(); ++i) {
      if (nums[i] > max) max = nums[i];
      if (max - mins[i] <= k) return i;
    }

    return -1;
  }
};
