#include <stdlib.h>

int maxProfit(int* prices, int pricesSize) {
  int* profits = malloc(pricesSize * sizeof(int));

  int prevPrice = prices[0], maxProfit = 0;
  for (int i = 0; i < pricesSize; ++i) {
    if (prices[i] >= prevPrice) {
      const int profit = prices[i] - prevPrice;
      if (profit > maxProfit) maxProfit = profit;
    } else {
      prevPrice = prices[i];
    }
    profits[i] = maxProfit;
  }

  prevPrice = prices[pricesSize - 1];
  maxProfit = profits[pricesSize - 1];

  for (int i = pricesSize - 1; i > 0; --i) {
    if (prices[i] <= prevPrice) {
      const int profit = profits[i - 1] + prevPrice - prices[i];
      if (profit > maxProfit) maxProfit = profit;
    } else {
      prevPrice = prices[i];
    }
  }

  return maxProfit;
}
