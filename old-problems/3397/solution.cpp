#include <vector>

class Solution {
 public:
  int maxDistinctElements(std::vector<int>& nums, int k) {
    return nums.size() + k;
  }
};
