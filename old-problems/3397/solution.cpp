#include <algorithm>
#include <vector>

class Solution {
 public:
  int maxDistinctElements(std::vector<int>& nums, int k) {
    std::sort(nums.begin(), nums.end());

    int count{1}, prev{nums[0] - k};
    for (std::size_t i{1}; i < nums.size(); ++i) {
      const int num{std::max(nums[i] - k, prev + 1)};
      if (num <= nums[i] + k) {
        prev = num;
        ++count;
      }
    }

    return count;
  }
};
