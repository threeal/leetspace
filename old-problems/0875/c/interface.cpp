#include <vector>

extern "C" {
int minEatingSpeed(int* piles, int pilesSize, int h);
}

int solution_c(std::vector<int> piles, int h) {
  return minEatingSpeed(piles.data(), piles.size(), h);
}
