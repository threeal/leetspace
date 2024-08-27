#include <algorithm>
#include <vector>

class Solution {
 public:
  int maximumProduct(std::vector<int>& nums) {
    std::partial_sort(nums.begin(), nums.begin() + 2, nums.end());
    std::partial_sort(
        nums.rbegin(), nums.rbegin() + 3, nums.rend(), std::greater<int>());

    return std::max(
        nums[0] * nums[1] * nums[nums.size() - 1],
        nums[nums.size() - 1] * nums[nums.size() - 2] * nums[nums.size() - 3]);
  }
};
