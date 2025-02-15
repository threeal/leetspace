int maxProfit(int* prices, int pricesSize) {
  int totalProfit = 0;
  for (int i = 1; i < pricesSize; ++i) {
    if (prices[i] > prices[i - 1]) totalProfit += prices[i] - prices[i - 1];
  }
  return totalProfit;
}
