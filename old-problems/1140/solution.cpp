#include <algorithm>
#include <vector>

class Solution {
 public:
  int stoneGameII(std::vector<int>& piles) {
    std::vector<std::vector<std::int64_t>> caches(
        piles.size() + 1, std::vector<std::int64_t>(piles.size() + 1, -1));
    return pickPiles(caches, piles, 0, 1)[0];
  }

  std::int32_t* pickPiles(
      std::vector<std::vector<std::int64_t>>& caches,
      const std::vector<int>& piles, int i, int m) {
    std::int32_t* best =
        reinterpret_cast<std::int32_t*>(caches[i].data() + m - 1);

    if (best[0] >= 0) return best;
    *reinterpret_cast<std::int64_t*>(best) = 0;

    int stones{0};
    for (int j{0}; j < m * 2 && i + j < static_cast<int>(piles.size()); ++j) {
      stones += piles[i + j];
      const auto current =
          pickPiles(caches, piles, i + j + 1, std::max(m, j + 1));

      if (stones + current[1] > best[0]) {
        best[0] = stones + current[1];
        best[1] = current[0];
      }
    }

    return best;
  }
};
