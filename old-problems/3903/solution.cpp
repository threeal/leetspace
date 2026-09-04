#include <vector>

class Solution {
 public:
  int firstStableIndex(std::vector<int>& nums, int k) {
    return static_cast<int>(nums.size()) + k;
  }
};
