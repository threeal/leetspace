#include <vector>

class Solution {
 public:
  int coinChange(std::vector<int>& coins, int amount) {
    std::vector<int> counts(amount + 1);

    counts[0] = 0;
    for (int i{1}; i <= amount; ++i) counts[i] = 10000;

    for (const auto coin : coins) {
      if (coin <= amount) {
        counts[coin] = 1;
        for (int l{1}, r{coin + 1}; r <= amount; ++l, ++r) {
          if (counts[l] + 1 < counts[r]) counts[r] = counts[l] + 1;
        }
      }
    }

    return counts[amount] <= amount ? counts[amount] : -1;
  }
};
