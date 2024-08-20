#include <algorithm>
#include <tuple>
#include <vector>

class Solution {
 public:
  int stoneGameII(std::vector<int>& piles) {
    std::vector<std::vector<std::tuple<int, int>>> caches(piles.size() + 1);
    const auto& [alice, bob] = pickPiles(caches, piles, 0, 1);
    return alice;
  }

  std::tuple<int, int> pickPiles(
      std::vector<std::vector<std::tuple<int, int>>>& caches,
      const std::vector<int>& piles, int i, int m) {
    if (static_cast<int>(caches[i].size()) < m) caches[i].resize(m, {-1, -1});
    auto& [bestCurrent, bestOther] = caches[i][m - 1];
    if (bestCurrent >= 0) return {bestCurrent, bestOther};

    bestCurrent = 0;
    bestOther = 0;

    int stones{0};
    for (int j{0}; j < m * 2 && i + j < static_cast<int>(piles.size()); ++j) {
      stones += piles[i + j];
      const auto& [other, current] =
          pickPiles(caches, piles, i + j + 1, std::max(m, j + 1));

      if (stones + current > bestCurrent) {
        bestCurrent = stones + current;
        bestOther = other;
      }
    }

    return {bestCurrent, bestOther};
  }
};
