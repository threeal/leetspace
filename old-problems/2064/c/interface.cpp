#include <vector>

extern "C" {
int minimizedMaximum(int n, int* quantities, int quantitiesSize);
}

int solution_c(int n, std::vector<int> quantities) {
  return minimizedMaximum(n, quantities.data(), quantities.size());
}
