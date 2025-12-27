#include <limits.h>

int maxProfit(int* prices, int pricesSize, int fee) {
  int buy = INT_MIN, sell = 0;
  for (int i = 0; i < pricesSize; ++i) {
    if (sell - prices[i] > buy) buy = sell - prices[i];
    if (buy + prices[i] - fee > sell) sell = buy + prices[i] - fee;
  }
  return sell;
}
