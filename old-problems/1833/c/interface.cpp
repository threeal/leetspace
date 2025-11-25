#include <vector>

extern "C" {
int maxIceCream(int* costs, int costsSize, int coins);
}

int solution_c(std::vector<int> costs, int coins) {
  return maxIceCream(costs.data(), costs.size(), coins);
}
