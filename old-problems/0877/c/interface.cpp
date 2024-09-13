#include <vector>

extern "C" {
bool stoneGame(int* piles, int pilesSize);
}

bool solution_c(std::vector<int> piles) {
  return stoneGame(piles.data(), piles.size());
}
