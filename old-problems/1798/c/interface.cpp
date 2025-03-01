#include <vector>

extern "C" {
int getMaximumConsecutive(int* coins, int coinsSize);
}

int solution_c(std::vector<int> coins) {
  return getMaximumConsecutive(coins.data(), coins.size());
}
