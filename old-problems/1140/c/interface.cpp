#include <vector>

extern "C" {
int stoneGameII(int* piles, int pilesSize);
}

int solution_c(std::vector<int> piles) {
  return stoneGameII(piles.data(), piles.size());
}
