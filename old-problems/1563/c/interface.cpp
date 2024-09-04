#include <vector>

extern "C" {
int stoneGameV(int* stoneValue, int stoneValueSize);
}

int solution_c(std::vector<int> stoneValue) {
  return stoneGameV(stoneValue.data(), stoneValue.size());
}
