#include <vector>

extern "C" {
int maxProfit(int* prices, int pricesSize, int fee);
}

int solution_c(std::vector<int> prices, int fee) {
  return maxProfit(prices.data(), prices.size(), fee);
}
