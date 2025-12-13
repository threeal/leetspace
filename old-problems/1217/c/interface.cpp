#include <vector>

extern "C" {
int minCostToMoveChips(int* position, int positionSize);
}

int solution_c(std::vector<int> position) {
  return minCostToMoveChips(position.data(), position.size());
}
