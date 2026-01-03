#include <vector>

extern "C" {
int minimumBoxes(int* apple, int appleSize, int* capacity, int capacitySize);
}

int solution_c(std::vector<int> apple, std::vector<int> capacity) {
  return minimumBoxes(
      apple.data(), apple.size(), capacity.data(), capacity.size());
}
