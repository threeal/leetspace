#include <algorithm>
#include <vector>

class Solution {
 public:
  int maxCoins(std::vector<int>& piles) {
    std::sort(piles.begin(), piles.end());

    int total = 0;
    for (size_t i = 1; i <= piles.size() / 3; ++i) {
      total += piles[piles.size() - 2 * i];
    }

    return total;
  }
};
