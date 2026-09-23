#include <vector>

class Solution {
 public:
  int minOperations(std::vector<int>& nums, int x) {
    std::size_t l{0};
    while (l < nums.size() && x > 0) x -= nums[l++];
    if (l == nums.size()) return x == 0 ? nums.size() : -1;

    std::size_t min{x == 0 ? l : nums.size() + 1};
    std::size_t r{nums.size()};
    while (l > 0) {
      x += nums[--l];
      while (x > 0) x -= nums[--r];
      if (x == 0 && l + nums.size() - r < min) {
        min = l + nums.size() - r;
      }
    }

    return min <= nums.size() ? min : -1;
  }
};
