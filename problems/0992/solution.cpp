#include <unordered_map>
#include <vector>

class Solution {
 public:
  int subarraysWithKDistinct(std::vector<int>& nums, int k) {
    return subarraysWithAtMostKDistinct(nums, k) - subarraysWithAtMostKDistinct(nums, k - 1);
  }

  int subarraysWithAtMostKDistinct(const std::vector<int>& nums, std::size_t k) {
    int subarraysCount = 0;
    std::unordered_map<int, int> numsCounts;

    std::size_t left = 0;
    std::size_t right = 0;
    while (right < nums.size()) {
      ++numsCounts[nums[right]];
      while (numsCounts.size() > k && left < right) {
        if (--numsCounts[nums[left]] == 0) numsCounts.erase(nums[left]);
        ++left;
      }
      subarraysCount += right - left + 1;
      ++right;
    }

    return subarraysCount;
  }
};
