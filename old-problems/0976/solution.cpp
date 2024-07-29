#include <vector>

class Solution {
 public:
  int largestPerimeter(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    for (int i = nums.size() - 3; i >= 0; --i) {
      if (nums[i] + nums[i + 1] > nums[i + 2]) {
        return nums[i] + nums[i + 1] + nums[i + 2];
      }
    }
    return 0;
  }
};
