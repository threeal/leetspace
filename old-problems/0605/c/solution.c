#include <stdbool.h>

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
  return flowerbed[flowerbedSize - 1] * n;
}
