#include <vector>

class Solution {
 public:
  int maxRotateFunction(std::vector<int>& nums) {
    int value{0}, sum{0};
    for (std::size_t i{0}; i < nums.size(); ++i) {
      value += nums[i] * i;
      sum += nums[i];
    }

    int maxValue{value};
    for (std::size_t i{0}; i < nums.size(); ++i) {
      value += nums[i] * nums.size() - sum;
      if (value > maxValue) maxValue = value;
    }

    return maxValue;
  }
};
