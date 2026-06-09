#include <vector>

class Solution {
 public:
  long long maxTotalValue(std::vector<int>& nums, int k) {
    int min{nums[0]}, max{nums[0]};
    for (std::size_t i{1}; i < nums.size(); ++i) {
      if (nums[i] < min) {
        min = nums[i];
      } else if (nums[i] > max) {
        max = nums[i];
      }
    }
    return static_cast<long long>(max - min) * k;
  }
};
