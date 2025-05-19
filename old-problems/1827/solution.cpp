#include <vector>

class Solution {
 public:
  int minOperations(std::vector<int>& nums) {
    int prev{nums[0]}, sum{0};
    for (std::size_t i{1}; i < nums.size(); ++i) {
      if (nums[i] > prev) {
        prev = nums[i];
      } else {
        ++prev;
        sum += prev - nums[i];
      }
    }
    return sum;
  }
};
