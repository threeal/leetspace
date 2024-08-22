#include <vector>

class Solution {
 public:
  int nthUglyNumber(int n) {
    std::vector<int> nums(n);
    nums[0] = 1;

    int i2 = 0, i3 = 0, i5 = 0;
    for (int i{1}; i < n; ++i) {
      const int num2 = nums[i2] * 2;
      const int num3 = nums[i3] * 3;
      const int num5 = nums[i5] * 5;

      const int min = std::min(num2, std::min(num3, num5));

      if (num2 == min) ++i2;
      if (num3 == min) ++i3;
      if (num5 == min) ++i5;

      nums[i] = min;
    }

    return nums.back();
  }
};
