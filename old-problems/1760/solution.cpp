#include <algorithm>
#include <queue>
#include <vector>

class Solution {
 public:
  int minimumSize(std::vector<int>& nums, int maxOperations) {
    int min{1};
    int max = *std::max_element(nums.begin(), nums.end());
    while (min < max) {
      int mid = min + (max - min) / 2;

      int operations{0};
      for (const auto num : nums) {
        operations += (num - 1) / mid;
      }

      if (operations > maxOperations) {
        min = mid + 1;
      } else {
        max = mid;
      }
    }
    return min;
  }
};
