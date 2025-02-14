#include <vector>

extern "C" {
int maxProfit(int* prices, int pricesSize);
}

int solution_c(std::vector<int> prices) {
  return maxProfit(prices.data(), prices.size());
}
