#include <vector>

extern "C" {
int maximumEnergy(int* energy, int energySize, int k);
}

int solution_c(std::vector<int> energy, int k) {
  return maximumEnergy(energy.data(), energy.size(), k);
}
