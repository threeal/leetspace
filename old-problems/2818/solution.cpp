#include <vector>

class Solution {
 public:
  int maximumScore(std::vector<int>& nums, int k) {
    return nums.size() + k;
  }
};
