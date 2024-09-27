#include <utility>
#include <vector>

class Solution {
 public:
  int numRollsToTarget(int n, int k, int target) {
    std::vector<int> prevCounts(target, 0), counts(target, 0);
    std::fill(prevCounts.begin(), prevCounts.begin() + std::min(k, target), 1);

    for (int i{1}; i < n; ++i) {
      long long sum{0};
      if (prevCounts.size() <= static_cast<std::size_t>(i + k)) {
        for (std::size_t j = i; j < prevCounts.size(); ++j) {
          sum = (sum + prevCounts[j - 1]) % 1000000007;
          counts[j] = sum;
        }
      } else {
        for (int j{i}; j < i + k; ++j) {
          sum = (sum + prevCounts[j - 1]) % 1000000007;
          counts[j] = sum;
        }
        for (std::size_t j = i + k; j < prevCounts.size(); ++j) {
          sum = (1000000007 + sum - prevCounts[j - 1 - k] + prevCounts[j - 1]) % 1000000007;
          counts[j] = sum;
        }
      }
      std::swap(counts, prevCounts);
    }

    return prevCounts.back();
  }
};
