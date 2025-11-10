#include <vector>

class Solution {
 public:
  int minOperations(std::vector<int>& nums) {
    int count{0}, n{-1};
    for (int num : nums) {
      while (n >= 0 && nums[n] >= num) {
        if (nums[n] > num) ++count;
        --n;
      }
      if (num > 0) nums[++n] = num;
    }
    return count + n + 1;
  }
};
