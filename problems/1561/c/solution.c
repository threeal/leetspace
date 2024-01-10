// The solution to maximize the number of coins is by always picking the second-highest pile.
// To do this, one can sort the piles and then iterate over the piles n / 3 times
// to get the second-highest pile in each iteration.

void reversedQuickSort(int* low, int* high);

int maxCoins(int* piles, int pilesSize) {
  // Sort each pile from highest to lowest.
  reversedQuickSort(piles, piles + pilesSize - 1);

  // Iterate n / 3 times to get the second-highest pile in each iteration.
  int total = 0;
  for (int i = 0; i < pilesSize / 3; ++i) {
    total += piles[2 * i + 1];
  }

  return total;
}

// This function implements quick sort to sort the given range of arrays.
// See: https://www.geeksforgeeks.org/quick-sort/
void reversedQuickSort(int* low, int* high) {
  if (low >= high) return;

  int* i = low - 1;

  for (int* j = low; j < high; ++j) {
    if (*j <= *high) continue;
    ++i;
    const int temp = *i;
    *i = *j;
    *j = temp;
  }

  ++i;
  const int temp = *i;
  *i = *high;
  *high = temp;

  reversedQuickSort(low, i - 1);
  reversedQuickSort(i + 1, high);
}
