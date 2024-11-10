#include <vector>

class Solution {
 public:
  int minimumSubarrayLength(std::vector<int>& nums, int k) {
    return nums.size() * k;
  }
};
