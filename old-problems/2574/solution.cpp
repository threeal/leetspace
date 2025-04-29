#include <vector>

class Solution {
 public:
  std::vector<int> leftRightDifference(std::vector<int>& nums) {
    int rightSum{0};
    for (const int num : nums) rightSum += num;

    int leftSum{0};
    for (int& num : nums) {
      const int temp{num};
      rightSum -= temp;
      num = rightSum >= leftSum ? rightSum - leftSum : leftSum - rightSum;
      leftSum += temp;
    }

    return nums;
  }
};
