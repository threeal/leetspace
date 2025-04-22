#include <stdbool.h>

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
  int i = 0;
  while (i < flowerbedSize && flowerbed[i] == 0) ++i;
  if (i == flowerbedSize) {
    n -= (i + 1) / 2;
    return n <= 0;
  };

  n -= i / 2;
  if (n <= 0) return true;

  int zeros = 0;
  while (i < flowerbedSize) {
    if (flowerbed[i] == 0) {
      ++zeros;
    } else {
      if (zeros > 2) {
        n -= (zeros - 1) / 2;
        if (n <= 0) return true;
      }
      zeros = 0;
    }
    ++i;
  }

  n -= zeros / 2;
  return n <= 0;
}
