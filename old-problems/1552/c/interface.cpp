#include <vector>

extern "C" {
int maxDistance(int* position, int positionSize, int m);
}

int solution_c(std::vector<int> position, int m) {
  return maxDistance(position.data(), position.size(), m);
}
