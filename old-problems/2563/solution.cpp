#include <algorithm>
#include <vector>

class Solution {
 public:
  long long countFairPairs(std::vector<int>& nums, int lower, int upper) {
    std::sort(nums.begin(), nums.end());

    long long count{0};
    for (auto it = nums.begin(); it != nums.end(); ++it) {
      const auto left = std::lower_bound(
          std::next(it), nums.end(), lower - *it);

      if (left != nums.end()) {
        const auto right = std::upper_bound(left, nums.end(), upper - *it);
        count += std::distance(left, right);
      }
    }

    return count;
  }
};
