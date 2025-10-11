#include <algorithm>
#include <vector>

class Solution {
 public:
  int rob(std::vector<int>& nums) {
    if (nums.size() == 1) return nums.front();

    int a0{nums.front()}, a1{0}, b0{0}, b1{0};
    for (std::size_t i{1}; i + 1 < nums.size(); ++i) {
      b0 = std::max(a0, b0 + nums[i]);
      b1 = std::max(a1, b1 + nums[i]);

      if (++i + 1 >= nums.size()) {
        return std::max({a0, a1 + nums.back(), b0, b1});
      }

      a0 = std::max(b0, a0 + nums[i]);
      a1 = std::max(b1, a1 + nums[i]);
    }

    return std::max({a0, a1, b0, b1 + nums.back()});
  }
};
