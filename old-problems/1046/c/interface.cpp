#include <vector>

extern "C" {
int lastStoneWeight(int* stones, int stonesSize);
}

int solution_c(std::vector<int> stones) {
  return lastStoneWeight(stones.data(), stones.size());
}
