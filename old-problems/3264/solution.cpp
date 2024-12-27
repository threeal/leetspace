#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<int> getFinalState(
      std::vector<int>& nums, int k, int multiplier) {
    while (k > 0) {
      auto it = std::min_element(nums.begin(), nums.end());
      *it *= multiplier;
      --k;
    }
    return nums;
  }
};
