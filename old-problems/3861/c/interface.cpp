#include <vector>

extern "C" {
int minimumIndex(int* capacity, int capacitySize, int itemSize);
}

int solution_c(std::vector<int> capacity, int itemSize) {
  return minimumIndex(capacity.data(), capacity.size(), itemSize);
}
