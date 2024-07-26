int maxProfit(int* prices, int pricesSize) {
  int highestProfit = 0;
  int lowestPrice = 10001;
  for (int i = 0; i < pricesSize; ++i) {
    if (prices[i] < lowestPrice) {
      lowestPrice = prices[i];
    } else if (prices[i] - lowestPrice > highestProfit) {
      highestProfit = prices[i] - lowestPrice;
    }
  }
  return highestProfit;
}
