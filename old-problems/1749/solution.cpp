#include <vector>

class Solution {
 public:
  int maxAbsoluteSum(std::vector<int>& nums) {
    int negativeSum{0}, positiveSum{0}, minNegative{0}, maxPositive{0};
    for (const auto num : nums) {
      negativeSum += num;
      if (negativeSum > 0) {
        negativeSum = 0;
      } else if (negativeSum < minNegative) {
        minNegative = negativeSum;
      }

      positiveSum += num;
      if (positiveSum < 0) {
        positiveSum = 0;
      } else if (positiveSum > maxPositive) {
        maxPositive = positiveSum;
      }
    }

    return -minNegative > maxPositive ? -minNegative : maxPositive;
  }
};
