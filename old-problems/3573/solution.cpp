#include <algorithm>
#include <vector>

class Solution {
 public:
  long long maximumProfit(std::vector<int>& prices, int k) {
    std::vector<long long> profits(k + 1, 0);
    std::vector<long long> buys(k + 1, -prices[0]);
    std::vector<long long> sells(k + 1, prices[0]);

    for (std::size_t i{1}; i < prices.size(); ++i) {
      for (int kk{k}; kk > 0; --kk) {
        const long long profit{
            std::max(buys[kk] + prices[i], sells[kk] - prices[i])};

        if (profit > profits[kk]) profits[kk] = profit;

        const long long buy{profits[kk - 1] - prices[i]};
        if (buy > buys[kk]) buys[kk] = buy;

        const long long sell{profits[kk - 1] + prices[i]};
        if (sell > sells[kk]) sells[kk] = sell;
      }
    }

    return profits[k];
  }
};
