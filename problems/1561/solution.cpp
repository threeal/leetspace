// The solution to maximize the number of coins is by always picking the second-highest pile.
// To do this, one can sort the piles and then iterate over the piles n / 3 times
// to get the second-highest pile in each iteration.

#include <algorithm>
#include <vector>

class Solution {
 public:
  int maxCoins(std::vector<int>& piles) {
    // Sort each pile from lowest to highest.
    std::sort(piles.begin(), piles.end());

    // Iterate n / 3 times to get the second-highest pile in each iteration.
    int total = 0;
    for (size_t i = 1; i <= piles.size() / 3; ++i) {
      total += piles[piles.size() - 2 * i];
    }

    return total;
  }
};
