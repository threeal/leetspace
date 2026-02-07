#include <algorithm>
#include <vector>

class Solution {
 public:
  bool findSubarrays(std::vector<int>& nums) {
    for (std::size_t i{1}; i < nums.size(); ++i) nums[i - 1] += nums[i];
    nums.pop_back();

    std::sort(nums.begin(), nums.end());

    for (std::size_t i{1}; i < nums.size(); ++i) {
      if (nums[i - 1] == nums[i]) return true;
    }

    return false;
  }
};
