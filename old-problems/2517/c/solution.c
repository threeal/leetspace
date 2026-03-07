#include <stdlib.h>

int compare(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int maximumTastiness(int* price, int priceSize, int k) {
  qsort(price, priceSize, sizeof(int), compare);

  int low = 0, high = price[priceSize - 1] - price[0];
  while (low < high) {
    const int mid = high - (high - low) / 2;

    int kk = 1, i = 0;
    while (kk < k) {
      int j = i + 1;
      while (j < priceSize && price[j] - price[i] < mid) ++j;
      if (j == priceSize) break;
      i = j;
      ++kk;
    }

    if (kk == k) {
      low = mid;
    } else {
      high = mid - 1;
    }
  }

  return low;
}
