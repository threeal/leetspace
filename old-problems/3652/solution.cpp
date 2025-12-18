#include <vector>

class Solution {
 public:
  long long maxProfit(
      std::vector<int>& prices, std::vector<int>& strategy, int k) {
    std::size_t kk = k, kk2{kk / 2};

    long long profit{0};
    for (std::size_t i{0}; i < prices.size(); ++i) {
      profit += prices[i] * strategy[i];
    }

    long long maxProfit{profit};

    for (std::size_t i{0}; i < kk2; ++i) {
      profit -= prices[i] * strategy[i];
    }

    for (std::size_t i{kk2}; i < kk; ++i) {
      if (strategy[i] != 1) profit += prices[i] * (1 - strategy[i]);
    }

    if (profit > maxProfit) maxProfit = profit;

    for (std::size_t i{kk}; i < prices.size(); ++i) {
      if (strategy[i] != 1) profit += prices[i] * (1 - strategy[i]);
      profit -= prices[i - kk2];
      profit += prices[i - kk] * strategy[i - kk];

      if (profit > maxProfit) maxProfit = profit;
    }

    return maxProfit;
  }
};
