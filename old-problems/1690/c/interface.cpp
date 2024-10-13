#include <vector>

extern "C" {
int stoneGameVII(int* stones, int stonesSize);
}

int solution_c(std::vector<int> stones) {
  return stoneGameVII(stones.data(), stones.size());
}
