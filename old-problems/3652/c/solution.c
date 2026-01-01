long long maxProfit(
    int* prices, int pricesSize, int* strategy, int strategySize, int k) {
  (void)strategySize;

  const int k2 = k / 2;

  long long profit = 0;
  for (int i = 0; i < pricesSize; ++i) {
    profit += prices[i] * strategy[i];
  }

  long long maxProfit = profit;

  for (int i = 0; i < k2; ++i) {
    profit -= prices[i] * strategy[i];
  }

  for (int i = k2; i < k; ++i) {
    if (strategy[i] != 1) profit += prices[i] * (1 - strategy[i]);
  }

  if (profit > maxProfit) maxProfit = profit;

  for (int i = k; i < pricesSize; ++i) {
    if (strategy[i] != 1) profit += prices[i] * (1 - strategy[i]);
    profit -= prices[i - k2];
    profit += prices[i - k] * strategy[i - k];

    if (profit > maxProfit) maxProfit = profit;
  }

  return maxProfit;
}
