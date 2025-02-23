#include <algorithm>
#include <vector>

class Solution {
 public:
  int longestConsecutive(std::vector<int>& nums) {
    if (nums.empty()) return 0;
    std::sort(nums.begin(), nums.end());
    int consecutive{1}, maxConsecutive{1};
    for (std::size_t i{1}; i < nums.size(); ++i) {
      if (nums[i] == nums[i - 1]) continue;
      if (nums[i - 1] + 1 == nums[i]) {
        ++consecutive;
      } else {
        if (consecutive > maxConsecutive) maxConsecutive = consecutive;
        consecutive = 1;
      }
    }
    return consecutive > maxConsecutive ? consecutive : maxConsecutive;
  }
};
