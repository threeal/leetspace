#include <limits>
#include <vector>

class Solution {
 public:
  int maxProduct(std::vector<int>& nums) {
    int max{std::numeric_limits<int>::min()};

    int left{1}, right{1};
    for (int l{0}, r = nums.size() - 1; r >= 0; ++l, --r) {
      if (left == 0) left = 1;
      left *= nums[l];
      if (left > max) max = left;

      if (right == 0) right = 1;
      right *= nums[r];
      if (right > max) max = right;
    }

    return max;
  }
};
