#include <algorithm>
#include <vector>

class Solution {
 public:
  int maxFrequency(std::vector<int>& nums, int k, int numOperations) {
    std::sort(nums.begin(), nums.end());

    std::size_t maxFreq{0}, il{0}, i{0}, ih{0}, l{0}, m{0}, r{0};
    while (il < nums.size() || i < nums.size() || ih < nums.size()) {
      int num{nums.back() + k};
      if (il < nums.size() && nums[il] - k < num) num = nums[il] - k;
      if (i < nums.size() && nums[i] < num) num = nums[i];
      if (ih < nums.size() && nums[ih] + k < num) num = nums[ih] + k;

      while (m < nums.size() && nums[m] < num) ++m;

      int equals{0};
      while (m < nums.size() && nums[m] == num) ++equals, ++m;

      while (nums[l] < num - k) ++l;
      while (r < nums.size() && nums[r] <= num + k) ++r;

      std::size_t freq{std::min<std::size_t>(r - l, equals + numOperations)};
      if (freq > maxFreq) maxFreq = freq;

      while (il < nums.size() && nums[il] - k == num) ++il;
      while (i < nums.size() && nums[i] == num) ++i;
      while (ih < nums.size() && nums[ih] + k == num) ++ih;
    }

    return maxFreq;
  }
};
