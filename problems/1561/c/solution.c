// The solution to maximize the number of coins is by always picking the second-highest pile.
// To do this, one can sort the piles and then iterate over the piles n / 3 times
// to get the second-highest pile in each iteration.

#include <stdlib.h>

int comp(const void* a, const void* b) {
  return *(int*)b - *(int*)a;
}

int maxCoins(int* piles, int pilesSize) {
  // Sort each pile from highest to lowest.
  qsort(piles, pilesSize, sizeof(int), comp);

  // Iterate n / 3 times to get the second-highest pile in each iteration.
  int total = 0;
  for (int i = 0; i < pilesSize / 3; ++i) {
    total += piles[2 * i + 1];
  }

  return total;
}
