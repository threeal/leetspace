#include <vector>

extern "C" {
int maximumBags(
    int* capacity, int capacitySize, int* rocks, int rocksSize,
    int additionalRocks);
}

int solution_c(
    std::vector<int> capacity, std::vector<int> rocks, int additionalRocks) {
  return maximumBags(
      capacity.data(), capacity.size(), rocks.data(), rocks.size(),
      additionalRocks);
}
