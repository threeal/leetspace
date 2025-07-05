#include <vector>

extern "C" {
int wateringPlants(int* plants, int plantsSize, int capacity);
}

int solution_c(std::vector<int> plants, int capacity) {
  return wateringPlants(plants.data(), plants.size(), capacity);
}
