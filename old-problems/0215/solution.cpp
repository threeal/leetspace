#include <vector>

class Solution {
 public:
  int findKthLargest(std::vector<int>& nums, int k) {
    return nums.size() + k;
  }
};
