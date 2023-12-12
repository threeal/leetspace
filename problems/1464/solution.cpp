#include <vector>

class Solution {
 public:
  int maxProduct(std::vector<int>& nums) {
    auto a = nums[0];
    auto b = nums[1];

    for (std::size_t i = 2; i < nums.size(); ++i) {
      if (nums[i] > a) {
        if (nums[i] > b) {
          if (a > b) {
            b = nums[i];
          } else {
            a = nums[i];
          }
        } else {
          a = nums[i];
        }
      } else if (nums[i] > b) {
        b = nums[i];
      }
    }

    return --a * --b;
  }
};
