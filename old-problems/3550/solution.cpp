#include <vector>

class Solution {
 public:
  int smallestIndex(std::vector<int>& nums) {
    const int n = nums.size();
    for (int i{0}; i < n; ++i) {
      int sum{0}, num{nums[i]};
      while (num > 0) {
        sum += num % 10;
        num /= 10;
      }
      if (sum == i) return i;
    }
    return -1;
  }
};
