#include <algorithm>
#include <vector>

class Solution {
 public:
  long long maxPoints(std::vector<std::vector<int>>& points) {
    const int n = points.front().size();
    std::vector<long long> current(n), prev(n, 0);

    for (const auto& row : points) {
      long long max{0};
      for (int j{0}; j < n; ++j) {
        max = std::max(max - 1, prev[j]);
        current[j] = max;
      }

      max = 0;
      for (int j{n - 1}; j >= 0; --j) {
        max = std::max(max - 1, prev[j]);
        current[j] = row[j] + std::max(max, current[j]);
      }

      std::swap(current, prev);
    }

    return *std::max_element(prev.begin(), prev.end());
  }
};
