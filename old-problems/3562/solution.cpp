#include <algorithm>
#include <limits>
#include <vector>

class Solution {
 public:
  int maxProfit(
      int n, std::vector<int>& present, std::vector<int>& future,
      std::vector<std::vector<int>>& hierarchy, int budget) {
    std::vector<std::vector<int>> children(n);
    for (std::size_t i{0}; i < hierarchy.size(); ++i) {
      children[hierarchy[i][0]].push_back(hierarchy[i][1]);
    }

    std::vector<std::vector<std::vector<int>>> caches(
        2, std::vector<std::vector<int>>(n));

    return std::max(
        findMaxProfit(caches, children, present, future, budget, 0, 0),
        findMaxProfit(caches, children, present, future, budget, 1, 0));
  }

 private:
  static int findMaxProfit(
      std::vector<std::vector<std::vector<int>>>& caches,
      const std::vector<std::vector<int>>& children,
      const std::vector<int>& present,
      const std::vector<int>& future,
      int budget,
      int parentBought,
      int employee) {
    auto& cache = caches[parentBought][employee];
    if (cache.empty()) {
      const int cost{parentBought ? present[employee] / 2 : present[employee]};

      int takeProfit{future[employee] - cost};
      int skipProfit{0};

      for (int child : children[employee]) {
        takeProfit += findMaxProfit(cache, children, present, future, 1, child, budget - cost);
        skipProfit += findMaxProfit(cache, children, present, future, 0, child, budget);
      }

      cache[parentBought][employee][budget] = std::max(takeProfit, skipProfit);
    }

    return *std::max_element(cache.begin(), cache.end());
  }
};
