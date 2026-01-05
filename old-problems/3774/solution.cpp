#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
 public:
  int absDifference(std::vector<int>& nums, int k) {
    std::sort(nums.begin(), nums.end());
    return std::accumulate(nums.rbegin(), nums.rbegin() + k, 0) -
        std::accumulate(nums.begin(), nums.begin() + k, 0);
  }
};
