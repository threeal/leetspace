#include <vector>

extern "C" {
bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n);
}

bool solution_c(std::vector<int> flowerbed, int n) {
  return canPlaceFlowers(flowerbed.data(), flowerbed.size(), n);
}
