#include <algorithm>
#include <vector>

class Solution {
 public:
  int maxFrequency(std::vector<int>& nums, int k, int numOperations) {
    std::sort(nums.begin(), nums.end());

    std::size_t maxFreq{0}, l{0}, i{0}, r{0};
    for (int num{nums.front()}; num <= nums.back(); ++num) {
      while (nums[i] < num) ++i;

      int equals{0};
      while (i < nums.size() && nums[i] == num) ++equals, ++i;

      while (nums[l] < num - k) ++l;
      while (r < nums.size() && nums[r] <= num + k) ++r;

      std::size_t freq{std::min<std::size_t>(r - l, equals + numOperations)};
      if (freq > maxFreq) maxFreq = freq;
    }

    return maxFreq;
  }
};
