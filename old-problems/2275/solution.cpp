#include <algorithm>
#include <vector>

class Solution {
 public:
  int largestCombination(std::vector<int>& candidates) {
    std::vector<int> counts(24, 0);
    for (const auto candidate : candidates) {
      for (int i{0}; i < 24; ++i) {
        if ((candidate & (1 << i)) > 0) ++counts[i];
      }
    }

    return *std::max_element(counts.begin(), counts.end());
  }
};
