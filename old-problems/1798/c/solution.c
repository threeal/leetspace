#include <stdlib.h>

int compare(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int getMaximumConsecutive(int* coins, int coinsSize) {
  qsort(coins, coinsSize, sizeof(int), compare);

  int max = 1;
  for (int i = 0; i < coinsSize; ++i) {
    if (coins[i] > max) break;
    max += coins[i];
  }

  return max;
}
