#include <vector>

class Solution {
 public:
  bool kLengthApart(std::vector<int>& nums, int k) {
    int prev = nums.size() + k;
    for (int i = nums.size() - 1; i >= 0; --i) {
      if (nums[i] != 0) {
        if (prev - i <= k) return false;
        prev = i;
      }
    }
    return true;
  }
};
