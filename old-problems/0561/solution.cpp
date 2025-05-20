#include <algorithm>
#include <vector>

class Solution {
 public:
  int arrayPairSum(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    int sum{0};
    for (std::size_t i{1}; i < nums.size(); i += 2) {
      sum += std::min(nums[i - 1], nums[i]);
    }
    return sum;
  }
};
