#include <algorithm>
#include <vector>

class Solution {
 public:
  long long countSubarrays(std::vector<int>& nums, int minK, int maxK) {
    long long count{0};

    int left{0};
    int right{0};

    int minPos{-1};
    int maxPos{-1};

    while (right < static_cast<int>(nums.size())) {
      if (nums[right] < minK || nums[right] > maxK) {
        left = right + 1;
      } else {
        if (nums[right] == minK) minPos = right;
        if (nums[right] == maxK) maxPos = right;
        count += std::max(std::min(minPos, maxPos) - left + 1, 0);
      }
      ++right;
    }

    return count;
  }
};
