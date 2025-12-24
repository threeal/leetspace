#include <vector>

extern "C" {
long long getDescentPeriods(int* prices, int pricesSize);
}

long long solution_c(std::vector<int> prices) {
  return getDescentPeriods(prices.data(), prices.size());
}
