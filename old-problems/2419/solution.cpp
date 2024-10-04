#include <vector>

class Solution {
 public:
  int longestSubarray(std::vector<int>& nums) {
    int maxConsecutive{0};
    int maxNum{0};
    for (std::size_t i{0}; i < nums.size(); ++i) {
      if (nums[i] < maxNum) continue;
      if (nums[i] > maxNum) {
        maxNum = nums[i];
        maxConsecutive = 1;
        for (++i; i < nums.size() && nums[i] == maxNum; ++i) ++maxConsecutive;
        --i;
      } else {
        maxNum = nums[i];
        int consecutive{1};
        for (++i; i < nums.size() && nums[i] == maxNum; ++i) ++consecutive;
        if (consecutive > maxConsecutive) maxConsecutive = consecutive;
        --i;
      }
    }
    return maxConsecutive;
  }
};
