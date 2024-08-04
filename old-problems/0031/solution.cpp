#include <algorithm>
#include <utility>
#include <vector>

class Solution {
 public:
  void nextPermutation(std::vector<int>& nums) {
    for (int i = nums.size() - 2; i >= 0; --i) {
      if (nums[i] >= nums[i + 1]) continue;
      for (int j = nums.size() - 1; j > i; --j) {
        if (nums[i] >= nums[j]) continue;
        std::swap(nums[i], nums[j]);
        std::reverse(nums.begin() + i + 1, nums.end());
        return;
      }
    }
    std::reverse(nums.begin(), nums.end());
  }
};
