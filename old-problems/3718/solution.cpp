#include <algorithm>
#include <vector>

class Solution {
 public:
  int missingMultiple(std::vector<int>& nums, int k) {
    std::sort(nums.begin(), nums.end());
    int kk{k};
    for (const int num : nums) {
      if (num < kk) continue;
      if (num > kk) break;
      kk += k;
    }
    return kk;
  }
};
