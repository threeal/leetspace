#include <algorithm>
#include <vector>

class Solution {
 public:
  int minimizeSum(std::vector<int>& nums) {
    if (nums.size() <= 3) return 0;
    std::sort(nums.begin(), nums.begin() + 3);

    int min0{nums[0]}, min1{nums[1]}, min2{nums[2]};
    int max0{nums[0]}, max1{nums[1]}, max2{nums[2]};

    for (std::size_t i{3}; i < nums.size(); ++i) {
      if (nums[i] < min2) {
        if (nums[i] < min1) {
          min2 = min1;
          if (nums[i] < min0) {
            min1 = min0;
            min0 = nums[i];
          } else {
            min1 = nums[i];
          }
        } else {
          min2 = nums[i];
        }
      }

      if (nums[i] > max0) {
        if (nums[i] > max1) {
          max0 = max1;
          if (nums[i] > max2) {
            max1 = max2;
            max2 = nums[i];
          } else {
            max1 = nums[i];
          }
        } else {
          max0 = nums[i];
        }
      }
    }

    return std::min(std::min(max2 - min2, max1 - min1), max0 - min0);
  }
};
