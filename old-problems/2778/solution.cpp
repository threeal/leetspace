#include <vector>

class Solution {
 public:
  int sumOfSquares(std::vector<int>& nums) {
    int sum{0};
    for (std::size_t i{0}; i < nums.size(); ++i) {
      if (nums.size() % (i + 1) == 0) sum += nums[i] * nums[i];
    }
    return sum;
  }
};
