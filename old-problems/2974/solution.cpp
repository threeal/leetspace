#include <algorithm>
#include <utility>
#include <vector>

class Solution {
 public:
  std::vector<int> numberGame(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    for (std::size_t i{1}; i < nums.size(); i += 2) {
      std::swap(nums[i], nums[i - 1]);
    }
    return nums;
  }
};
