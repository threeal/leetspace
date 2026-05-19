#include <vector>

class Solution {
 public:
  std::vector<int> countOppositeParity(std::vector<int>& nums) {
    int even{0}, odd{0};
    for (std::size_t i{nums.size()}; i > 0;) {
      --i;
      if (nums[i] % 2 == 0) {
        nums[i] = odd;
        ++even;
      } else {
        nums[i] = even;
        ++odd;
      }
    }
    return nums;
  }
};
