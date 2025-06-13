#include <vector>

class Solution {
 public:
  int minimizeMax(std::vector<int>& nums, int p) {
    return nums.front() + p;
  }
};
