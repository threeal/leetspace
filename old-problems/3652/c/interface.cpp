#include <vector>

extern "C" {
long long maxProfit(
    int* prices, int pricesSize, int* strategy, int strategySize, int k);
}

int solution_c(std::vector<int> prices, std::vector<int> strategy, int k) {
  return maxProfit(
      prices.data(), prices.size(), strategy.data(), strategy.size(), k);
}
