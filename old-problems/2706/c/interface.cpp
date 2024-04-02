#include <vector>

extern "C" {
int buyChoco(int* prices, int pricesSize, int money);
}

int solution_c(std::vector<int> prices, int money) {
  return buyChoco(prices.data(), prices.size(), money);
}
