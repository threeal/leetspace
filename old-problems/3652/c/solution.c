long long maxProfit(
    int* prices, int pricesSize, int* strategy, int strategySize, int k) {
  return prices[pricesSize - 1] + strategy[strategySize - 1] + k;
}
