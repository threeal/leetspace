#include <vector>

class Solution {
 public:
  int findNonMinOrMax(std::vector<int>& nums) {
    int min{nums[0]}, max{nums[0]};
    for (std::size_t i{1}; i < nums.size(); ++i) {
      if (nums[i] < min) {
        if (min == max) {
          min = nums[i];
        } else {
          return min;
        }
      } else if (nums[i] > max) {
        if (min == max) {
          max = nums[i];
        } else {
          return max;
        }
      } else if (nums[i] > min && nums[i] < max) {
        return nums[i];
      }
    }
    return -1;
  }
};
