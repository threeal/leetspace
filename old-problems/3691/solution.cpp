#include <vector>

class Solution {
 public:
  long long maxTotalValue(std::vector<int>& nums, int k) {
    return nums.size() + k;
  }
};
