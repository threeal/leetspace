#include <vector>

class Solution {
 public:
  int zigZagArrays(int n, int l, int r) {
    std::vector<int> counts(r - l + 1, 1);
    for (int i{1}; i < n; ++i) {
      int sum{0};
      for (std::size_t j{0}; j < counts.size(); ++j) {
        const int prevSum{sum};
        sum = (sum + counts[j]) % 1000000007;
        counts[j] = prevSum;
      }

      if (++i >= n) break;

      sum = 0;
      for (std::size_t j{counts.size()}; j > 0;) {
        --j;
        const int prevSum{sum};
        sum = (sum + counts[j]) % 1000000007;
        counts[j] = prevSum;
      }
    }

    int sum{0};
    for (const int count : counts) {
      sum = (sum + count) % 1000000007;
    }

    return (sum + sum) % 1000000007;
  }
};
