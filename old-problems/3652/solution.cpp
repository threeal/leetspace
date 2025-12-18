#include <vector>

class Solution {
 public:
  long long maxProfit(
      std::vector<int>& prices, std::vector<int>& strategy, int k) {
    return prices.size() + strategy.size() + k;
  }
};
