#include <algorithm>
#include <vector>

class Solution {
 public:
  long long countBadPairs(std::vector<int>& nums) {
    for (std::size_t i{0}; i < nums.size(); ++i) nums[i] -= i;
    std::sort(nums.begin(), nums.end());

    long long total = nums.size();
    total = total * (total - 1) / 2;

    long long freq{1};
    for (std::size_t i{1}; i < nums.size(); ++i) {
      if (nums[i] == nums[i - 1]) {
        ++freq;
      } else {
        total -= freq * (freq - 1) / 2;
        freq = 1;
      }
    }

    return total - freq * (freq - 1) / 2;
  }
};
