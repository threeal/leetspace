#include <vector>

extern "C" {
int minimumCost(int* cost, int costSize);
}

int solution_c(std::vector<int> cost) {
  return minimumCost(cost.data(), cost.size());
}
