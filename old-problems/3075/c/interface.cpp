#include <vector>

extern "C" {
long long maximumHappinessSum(int* happiness, int happinessSize, int k);
}

long long solution_c(std::vector<int> happiness, int k) {
  return maximumHappinessSum(happiness.data(), happiness.size(), k);
}
