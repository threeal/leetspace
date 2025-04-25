#include <vector>

class Solution {
 public:
  bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
    return nums.empty() && k == 0;
  }
};
