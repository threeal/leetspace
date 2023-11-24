// The solution to maximize the number of coins is by always picking the second-highest pile.
// To do this, one can sort the piles and then iterate over the piles n / 3 times
// to get the second-highest pile in each iteration.

#include <algorithm>
#include <vector>

class Solution {
 public:
  int maxCoins(std::vector<int>& piles) {
    // Sort each pile from highest to lowest.
    std::sort(piles.begin(), piles.end(), std::greater<int>());

    // Iterate n / 3 times to get the second-highest pile in each iteration.
    int total = 0;
    for (size_t i = 0; i < piles.size() / 3; ++i) {
      total += piles[2 * i + 1];
    }

    return total;
  }
};
