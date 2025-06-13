#include <algorithm>
#include <vector>

class Solution {
 public:
  int minimizeMax(std::vector<int>& nums, int p) {
    std::sort(nums.begin(), nums.end());
    int left{0}, right{nums.back() - nums.front()};
    while (left < right) {
      const int mid{left + (right - left) / 2};
      int pairs{0};
      for (std::size_t i{1}; i < nums.size(); ++i) {
        if (nums[i] - nums[i - 1] <= mid) {
          ++pairs;
          ++i;
        }
      }
      if (pairs >= p) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    return left;
  }
};
