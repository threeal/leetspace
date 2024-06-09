#include <vector>

class Solution {
 public:
  int subarraysDivByK(std::vector<int>& nums, int k) {
    int count{0};
    std::vector<int> counts(k, 0);
    counts[0] = 1;

    int sum{0};
    for (const auto num : nums) {
      sum += num;

      int mod{sum % k};
      if (mod < 0) mod += k;

      count += counts[mod];
      ++counts[mod];
    }

    return count;
  }
};
