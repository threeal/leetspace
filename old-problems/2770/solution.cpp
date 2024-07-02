#include <cstdlib>
#include <vector>

class Solution {
 public:
  int maximumJumps(std::vector<int>& nums, int target) {
    std::vector<int> jumps(nums.size());
    jumps[jumps.size() - 1] = 0;

    for (int i = nums.size() - 2; i >= 0; --i) {
      jumps[i] = -2;
      for (int j = nums.size() - 1; j > i; --j) {
        if (jumps[j] < 0 || std::abs(nums[j] - nums[i]) > target) continue;
        if (jumps[j] > jumps[i]) jumps[i] = jumps[j];
      }
      ++jumps[i];
    }

    return jumps[0];
  }
};
