#include <algorithm>
#include <vector>

class Solution {
 public:
  int triangleNumber(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());

    int count{0};
    for (int c = nums.size() - 1; c >= 2; --c) {
      int a{0};
      int b{c - 1};
      while (a < b) {
        if (nums[a] + nums[b] > nums[c]) {
          count += b - a;
          --b;
        } else {
          ++a;
        }
      }
    }

    return count;
  }
};
