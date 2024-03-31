#include <algorithm>
#include <vector>

class Solution {
 public:
  long long countSubarrays(std::vector<int>& nums, int k) {
    long long count = 0;
    const auto maxNum = *std::max_element(nums.begin(), nums.end());

    int left = 0;
    int right = 0;
    while (right < static_cast<int>(nums.size())) {
      if (nums[right] == maxNum) --k;
      while (k <= 0) {
        if (nums[left] == maxNum) ++k;
        ++left;
      }
      count += left;
      ++right;
    }

    return count;
  }
};
