int* finalPrices(int* prices, int pricesSize, int* returnSize) {
  for (int i = 0; i < pricesSize; ++i) {
    for (int j = i + 1; j < pricesSize; ++j) {
      if (prices[j] <= prices[i]) {
        prices[i] -= prices[j];
        break;
      }
    }
  }
  *returnSize = pricesSize;
  return prices;
}
