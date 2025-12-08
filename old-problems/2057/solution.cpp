#include <vector>

class Solution {
 public:
  int smallestEqual(std::vector<int>& nums) {
    const int n = nums.size();
    for (int i{0}; i < n; ++i) {
      if (i % 10 == nums[i]) return i;
    }
    return -1;
  }
};
