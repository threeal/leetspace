#include <algorithm>
#include <vector>

class Solution {
 public:
  int minRemoval(std::vector<int>& nums, int k) {
    std::sort(nums.begin(), nums.end());
    std::size_t maxSize{0};
    for (std::size_t l{0}, r{0}; r < nums.size(); ++r) {
      while (nums[l] < (nums[r] + k - 1) / k) ++l;
      if (r + 1 - l > maxSize) maxSize = r + 1 - l;
    }
    return nums.size() - maxSize;
  }
};
