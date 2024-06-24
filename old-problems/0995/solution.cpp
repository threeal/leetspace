#include <vector>

class Solution {
 public:
  int minKBitFlips(std::vector<int>& nums, int k) {
    return nums.size() - k;
  }
};
