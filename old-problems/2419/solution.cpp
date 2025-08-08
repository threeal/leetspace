#include <vector>

class Solution {
 public:
  int longestSubarray(std::vector<int>& nums) {
    int consecutive{0}, maxConsecutive{0}, maxNum{0};
    for (const int num : nums) {
      if (num < maxNum) {
        consecutive = 0;
      } else if (num > maxNum) {
        consecutive = 1;
        maxConsecutive = 1;
        maxNum = num;
      } else {
        ++consecutive;
        if (consecutive > maxConsecutive) {
          maxConsecutive = consecutive;
        }
      }
    }
    return maxConsecutive;
  }
};
