#include <vector>

class Solution {
 public:
  int maxProduct(std::vector<int>& nums) {
    auto a = nums[0] < nums[1] ? nums[0] : nums[1];
    auto b = nums[0] < nums[1] ? nums[1] : nums[0];

    for (std::size_t i = 2; i < nums.size(); ++i) {
      if (nums[i] < a) continue;

      if (nums[i] < b) {
        a = nums[i];
      } else {
        a = b;
        b = nums[i];
      }
    }

    return --a * --b;
  }
};
