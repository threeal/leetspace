#include <vector>

class Solution {
 public:
  std::vector<int> countBits(int n) {
    std::vector<int> counts(n + 1);
    counts[0] = 0;
    for (int i{1}, e{1}; i <= n; ++i) {
      if (i == e * 2) e = i;
      counts[i] = counts[i - e] + 1;
    }
    return counts;
  }
};
