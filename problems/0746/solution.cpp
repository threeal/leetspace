#include <algorithm>
#include <functional>
#include <vector>

class Solution {
 public:
  int minCostClimbingStairs(std::vector<int>& cost) {
    const auto n = cost.size();
    std::vector<int> cache(n, -1);

    std::function<int(size_t)> fn = [&](size_t i) {
      if (i >= n) return 0;
      if (cache[i] < 0) {
        cache[i] = cost[i] + std::min(fn(i + 1), fn(i + 2));
      }
      return cache[i];
    };

    return std::min(fn(0), fn(1));
  }
};
