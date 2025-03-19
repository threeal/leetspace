#include <vector>

extern "C" {
long long repairCars(int* ranks, int ranksSize, int cars);
}

long long solution_c(std::vector<int> ranks, int cars) {
  return repairCars(ranks.data(), ranks.size(), cars);
}
