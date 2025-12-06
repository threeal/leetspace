#include <vector>

extern "C" {
int shipWithinDays(int* weights, int weightsSize, int days);
}

int solution_c(std::vector<int> weights, int days) {
  return shipWithinDays(weights.data(), weights.size(), days);
}
