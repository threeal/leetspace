#include <vector>

class Solution {
 public:
  int maximumLength(std::vector<int>& nums, int k) {
    return nums.front() + k;
  }
};
