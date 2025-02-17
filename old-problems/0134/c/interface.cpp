#include <vector>

extern "C" {
int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize);
}

int solution_c(std::vector<int> gas, std::vector<int> cost) {
  return canCompleteCircuit(gas.data(), gas.size(), cost.data(), cost.size());
}
