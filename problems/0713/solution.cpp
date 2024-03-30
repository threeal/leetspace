#include <vector>

class Solution {
 public:
  int numSubarrayProductLessThanK(std::vector<int>& nums, int k) {
    if (k < 1) return 0;

    int count = 0;

    std::size_t left = 0;
    std::size_t right = 0;
    int product = 1;

    while (right < nums.size()) {
      product *= nums[right];
      while (product >= k) {
        product /= nums[left];
        ++left;
      }
      count += right + 1 - left;
      ++right;
    }

    return count;
  }
};
