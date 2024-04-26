#include <algorithm>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  int maxSubarrayLength(std::vector<int>& nums, int k) {
    std::unordered_map<int, int> frequencies;
    int maxLength = 0;

    int left = 0;
    int right = 0;
    while (right < static_cast<int>(nums.size())) {
      ++frequencies[nums[right]];
      while (frequencies[nums[right]] > k) {
        --frequencies[nums[left++]];
      }

      maxLength = std::max(maxLength, right - left + 1);
      ++right;
    }

    return maxLength;
  }
};
