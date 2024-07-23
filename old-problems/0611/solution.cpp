#include <algorithm>
#include <vector>

class Solution {
 public:
  int triangleNumber(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());

    int count{0};
    for (int c = nums.size() - 1; c >= 2; --c) {
      for (int b{c - 1}; b >= 1; --b) {
        int a{0};
        while (a < b && nums[a] + nums[b] <= nums[c]) ++a;
        count += b - a;
      }
    }

    return count;
  }
};
