#include <vector>

class Solution {
 public:
  int minRemoval(std::vector<int>& nums, int k) {
    return nums.size() + k;
  }
};
