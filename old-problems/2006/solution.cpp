#include <algorithm>
#include <vector>

class Solution {
 public:
  int countKDifference(std::vector<int>& nums, int k) {
    int count{0};
    std::sort(nums.begin(), nums.end());
    for (std::size_t l{0}, r{0}, i{1}; i < nums.size(); ++i) {
      while (r < i && nums[r] + k <= nums[i]) ++r;
      while (l < r && nums[l] + k < nums[i]) ++l;
      count += r - l;
    }
    return count;
  }
};
