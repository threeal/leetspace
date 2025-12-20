#include <algorithm>
#include <vector>

class Solution {
 public:
  int maximizeExpressionOfThree(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.begin() + 3);

    int c{nums[0]}, b{nums[1]}, a{nums[2]};
    for (std::size_t i{3}; i < nums.size(); ++i) {
      if (nums[i] > b) {
        if (nums[i] > a) {
          b = a;
          a = nums[i];
        } else {
          b = nums[i];
        }
      } else if (nums[i] < c) {
        c = nums[i];
      }
    }

    return a + b - c;
  }
};
