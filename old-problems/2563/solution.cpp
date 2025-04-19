#include <algorithm>
#include <vector>

class Solution {
 public:
  long long countFairPairs(std::vector<int>& nums, int lower, int upper) {
    std::sort(nums.begin(), nums.end());

    long long count{0};
    std::size_t l{0}, r{nums.size() - 1};
    while (l < r) {
      if (nums[l] + nums[r] > upper) {
        --r;
      } else {
        count += r - l;
        ++l;
      }
    }

    l = 0, r = nums.size() - 1;
    while (l < r) {
      if (nums[l] + nums[r] >= lower) {
        --r;
      } else {
        count -= r - l;
        ++l;
      }
    }

    return count;
  }
};
