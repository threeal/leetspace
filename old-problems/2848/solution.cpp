#include <algorithm>
#include <vector>

class Solution {
 public:
  int numberOfPoints(std::vector<std::vector<int>>& nums) {
    std::sort(nums.begin(), nums.end());

    int coverage{0}, min{nums[0][0]}, max{nums[0][1]};
    for (std::size_t i{1}; i < nums.size(); ++i) {
      if (nums[i][0] > max) {
        coverage += max - min + 1;
        min = nums[i][0];
        max = nums[i][1];
      } else if (nums[i][1] > max) {
        max = nums[i][1];
      }
    }

    return coverage + max - min + 1;
  }
};
