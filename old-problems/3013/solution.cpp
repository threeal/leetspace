#include <vector>

class Solution {
 public:
  long long minimumCost(std::vector<int>& nums, int k, int dist) {
    return nums.size() + k + dist;
  }
};
