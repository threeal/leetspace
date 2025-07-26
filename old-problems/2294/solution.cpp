#include <algorithm>
#include <vector>

class Solution {
 public:
  int partitionArray(std::vector<int>& nums, int k) {
    std::sort(nums.begin(), nums.end());
    int count{0}, max{-1};
    for (const int num : nums) {
      if (num > max) {
        ++count;
        max = num + k;
      }
    }
    return count;
  }
};
