#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<bool> checkArithmeticSubarrays(std::vector<int>& nums, std::vector<int>& l, std::vector<int>& r) {
    const auto n = std::min(l.size(), r.size());
    std::vector<bool> isArithmetics(n, true);

    for (size_t i = 0; i < n; ++i) {
      if (r[i] - l[i] <= 1) continue;
      std::vector<int> subnums(nums.begin() + l[i], nums.begin() + r[i] + 1);
      std::sort(subnums.begin(), subnums.end());

      const auto diff = subnums[1] - subnums[0];
      for (size_t j = 2; j < subnums.size(); ++j) {
        if (subnums[j] - subnums[j - 1] != diff) {
          isArithmetics[i] = false;
          break;
        }
      }
    }

    return isArithmetics;
  }
};
