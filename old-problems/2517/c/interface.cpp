#include <vector>

extern "C" {
int maximumTastiness(int* price, int priceSize, int k);
}

int solution_c(std::vector<int> price, int k) {
  return maximumTastiness(price.data(), price.size(), k);
}
