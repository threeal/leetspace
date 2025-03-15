#include <vector>

extern "C" {
int coinChange(int* coins, int coinsSize, int amount);
}

int solution_c(std::vector<int> coins, int amount) {
  return coinChange(coins.data(), coins.size(), amount);
}
