#include <vector>

class Solution {
 public:
  int getMinDistance(std::vector<int>& nums, int target, int start) {
    const int n = nums.size();
    int minDist{n};
    for (int i{0}; i < n; ++i) {
      if (nums[i] == target) {
        const int dist{std::abs(start - i)};
        if (dist < minDist) minDist = dist;
      }
    }
    return minDist;
  }
};
