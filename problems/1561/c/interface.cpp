#include <vector>

extern "C" {
int maxCoins(int* piles, int pilesSize);
}

int solution_c(std::vector<int> piles) {
  return maxCoins(piles.data(), piles.size());
}
