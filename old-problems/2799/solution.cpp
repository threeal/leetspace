#include <vector>

class Solution {
 public:
  int countCompleteSubarrays(std::vector<int>& nums) {
    int totalDistinct{0}, freqs[2001]{0};
    for (const int num : nums) {
      if (++freqs[num] == 1) ++totalDistinct;
    }

    for (const int num : nums) --freqs[num];

    int count{0}, distinct{0};
    std::size_t l{0}, r{0};
    while (true) {
      while (r < nums.size() && distinct < totalDistinct) {
        if (++freqs[nums[r]] == 1) ++distinct;
        ++r;
      }

      if (distinct != totalDistinct) break;
      count += nums.size() - r + 1;

      if (--freqs[nums[l]] == 0) --distinct;
      ++l;
    }

    return count;
  }
};
