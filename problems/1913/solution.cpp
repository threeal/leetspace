#include <vector>

class Solution {
 public:
  int maxProductDifference(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.begin() + 4);

    int a = nums[2];
    int b = nums[3];
    int c = nums[1];
    int d = nums[0];

    for (std::size_t i = 4; i < nums.size(); ++i) {
      if (nums[i] > a) {
        if (nums[i] > b) {
          a = b;
          b = nums[i];
        } else {
          a = nums[i];
        }
      } else if (nums[i] < c) {
        if (nums[i] < d) {
          c = d;
          d = nums[i];
        } else {
          c = nums[i];
        }
      }
    }

    return (a * b) - (c * d);
  }
};
