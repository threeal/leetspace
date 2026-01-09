#include <vector>

class Solution {
 public:
  int findMiddleIndex(std::vector<int>& nums) {
    int rightSum{0};
    for (int num : nums) rightSum += num;

    int leftSum{0};
    for (std::size_t i{0}; i < nums.size(); ++i) {
      rightSum -= nums[i];
      if (leftSum == rightSum) return i;
      leftSum += nums[i];
    }

    return -1;
  }
};
