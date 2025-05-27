#include <vector>

class Solution {
 public:
  int minElement(std::vector<int>& nums) {
    int minSum{nums.front()};
    for (int num : nums) {
      int sum{0};
      while (num > 0) {
        sum += num % 10;
        num /= 10;
      }
      if (sum < minSum) minSum = sum;
    }
    return minSum;
  }
};
