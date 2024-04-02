#include <vector>

class Solution {
 public:
  int removeElement(std::vector<int>& nums, int val) {
    int k = -1;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      if (nums[i] == val) continue;
      nums[++k] = nums[i];
    }
    return ++k;
  }
};
