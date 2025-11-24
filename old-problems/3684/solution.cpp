#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<int> maxKDistinct(std::vector<int>& nums, int k) {
    std::sort(nums.begin(), nums.end(), std::greater<int>());

    int n{1};
    for (std::size_t i{1}; i < nums.size() && n < k; ++i) {
      if (nums[i] != nums[i - 1]) nums[n++] = nums[i];
    }

    nums.resize(n);
    return nums;
  }
};
