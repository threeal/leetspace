#include <list>
#include <tuple>
#include <vector>

class Solution {
 public:
  std::vector<int> sumOfDistancesInTree(int n, std::vector<std::vector<int>>& edges) {
    std::vector<std::list<int>> nexts(n);
    for (const auto& edge : edges) {
      nexts[edge[0]].push_back(edge[1]);
      nexts[edge[1]].push_back(edge[0]);
    }

    std::vector<int> sums(n, 0);
    std::vector<std::vector<std::tuple<int, int>>> cache(n, std::vector<std::tuple<int, int>>(n, {-1, -1}));

    while (--n >= 0) {
      for (const auto next : nexts[n]) {
        const auto [count, sum] = sumOfDistancesInTree(nexts, cache, n, next);
        sums[n] += count + sum;
      }
    }

    return sums;
  }

  std::tuple<int, int> sumOfDistancesInTree(const std::vector<std::list<int>>& nexts, std::vector<std::vector<std::tuple<int, int>>>& cache, int from, int to) {
    if (std::get<0>(cache[from][to]) < 0) {
      int counts{1};
      int sums{0};
      for (const auto next : nexts[to]) {
        if (next == from) continue;
        const auto [count, sum] = sumOfDistancesInTree(nexts, cache, to, next);
        counts += count;
        sums += count + sum;
      }
      cache[from][to] = {counts, sums};
    }
    return cache[from][to];
  }
};
