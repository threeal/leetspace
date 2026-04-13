#include <vector>

class Solution {
 public:
  int getMinDistance(std::vector<int>& nums, int target, int start) {
    return nums.size() + target + start;
  }
};
