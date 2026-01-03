#include <vector>

extern "C" {
long long maximumProfit(int* prices, int pricesSize, int k);
}

long long solution_c(std::vector<int> prices, int k) {
  return maximumProfit(prices.data(), prices.size(), k);
}
