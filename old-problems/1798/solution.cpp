#include <algorithm>
#include <vector>

class Solution {
 public:
  int getMaximumConsecutive(std::vector<int>& coins) {
    std::sort(coins.begin(), coins.end());

    int max{1};
    for (const auto coin : coins) {
      if (coin > max) break;
      max += coin;
    }

    return max;
  }
};
