#include <stdlib.h>

long long maximumProfit(int* prices, int pricesSize, int k) {
  long long* profits = malloc((k + 1) * sizeof(long long));
  long long* buys = malloc((k + 1) * sizeof(long long));
  long long* sells = malloc((k + 1) * sizeof(long long));

  for (int i = 0; i <= k; ++i) {
    profits[i] = 0;
    buys[i] = -prices[0];
    sells[i] = prices[0];
  }

  for (int i = 1; i < pricesSize; ++i) {
    for (int kk = k; kk > 0; --kk) {
      const long long buyProfit = buys[kk] + prices[i];
      const long long sellProfit = sells[kk] - prices[i];
      const long long profit = buyProfit >= sellProfit ? buyProfit : sellProfit;

      if (profit > profits[kk]) profits[kk] = profit;

      const long long buy = profits[kk - 1] - prices[i];
      if (buy > buys[kk]) buys[kk] = buy;

      const long long sell = profits[kk - 1] + prices[i];
      if (sell > sells[kk]) sells[kk] = sell;
    }
  }

  const long long profit = profits[k];

  free(profits);
  free(buys);
  free(sells);

  return profit;
}
