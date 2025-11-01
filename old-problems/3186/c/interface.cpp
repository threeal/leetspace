#include <vector>

extern "C" {
long long maximumTotalDamage(int* power, int powerSize);
}

long long solution_c(std::vector<int> power) {
  return maximumTotalDamage(power.data(), power.size());
}
