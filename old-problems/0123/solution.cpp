#include <vector>

class Solution {
 public:
  int maxProfit(std::vector<int>& prices) {
    std::vector<int> profits(prices.size());

    int prevPrice{prices.front()}, maxProfit{0};
    for (std::size_t i{0}; i < prices.size(); ++i) {
      if (prices[i] >= prevPrice) {
        maxProfit = std::max(maxProfit, prices[i] - prevPrice);
      } else {
        prevPrice = prices[i];
      }
      profits[i] = maxProfit;
    }

    prevPrice = prices.back();
    maxProfit = profits.back();

    for (std::size_t i{prices.size() - 1}; i > 0; --i) {
      if (prices[i] <= prevPrice) {
        maxProfit = std::max(maxProfit, profits[i - 1] + prevPrice - prices[i]);
      } else {
        prevPrice = prices[i];
      }
    }

    return maxProfit;
  }
};
