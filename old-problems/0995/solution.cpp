#include <vector>

class Solution {
 public:
  int minKBitFlips(std::vector<int>& nums, int k) {
    std::vector<bool> mustFlips(nums.size(), false);

    int target{1};
    int flip{0};
    for (int i = nums.size() - 1; i >= k; --i) {
      if (mustFlips[i]) target = target == 0 ? 1 : 0;
      if (nums[i] != target) {
        mustFlips[i - k] = true;
        target = target == 0 ? 1 : 0;
        ++flip;
      }
    }

    if (mustFlips[k - 1]) target = target == 0 ? 1 : 0;
    if (nums[k - 1] == target) {
      for (int i{k - 2}; i >= 0; --i) {
        if (mustFlips[i]) target = target == 0 ? 1 : 0;
        if (nums[i] != target) return -1;
      }
      return flip;
    } else {
      for (int i{k - 2}; i >= 0; --i) {
        if (mustFlips[i]) target = target == 0 ? 1 : 0;
        if (nums[i] == target) return -1;
      }
      return flip + 1;
    }
  }
};
