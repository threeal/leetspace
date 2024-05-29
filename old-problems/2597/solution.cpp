#include <vector>

class Solution {
 public:
  int beautifulSubsets(std::vector<int>& nums, int k) {
    std::vector<int> counts(1001, 0);
    return beautifulSubsets(counts.data(), nums.data(), nums.data() + nums.size(), k);
  }

  int beautifulSubsets(int* counts, const int* num, const int* end, int k) {
    if (num >= end) return 0;
    int subsets{0};

    if (counts[*num] == 0) {
      if (*num + k <= 1000) ++counts[*num + k];
      if (*num - k >= 0) ++counts[*num - k];

      subsets += 1 + beautifulSubsets(counts, num + 1, end, k);

      if (*num + k <= 1000) --counts[*num + k];
      if (*num - k >= 0) --counts[*num - k];
    }

    return subsets + beautifulSubsets(counts, num + 1, end, k);
  }
};
