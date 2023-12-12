// The solution can simply be accomplished by finding the two largest elements and then multiplying them.

#include <vector>

class Solution {
 public:
  int maxProduct(std::vector<int>& nums) {
    // Prepare containers for storing two largest elements.
    // a should be smaller than b.
    auto a = nums[0] < nums[1] ? nums[0] : nums[1];
    auto b = nums[0] < nums[1] ? nums[1] : nums[0];

    // Iterating over the elements to find the two largest elements.
    for (std::size_t i = 2; i < nums.size(); ++i) {
      if (nums[i] < a) continue;

      if (nums[i] < b) {
        a = nums[i];
      } else {
        a = b;
        b = nums[i];
      }
    }

    // Multiply them after decrementing each by 1.
    return --a * --b;
  }
};
