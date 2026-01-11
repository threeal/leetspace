#include <stdlib.h>

int compare(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int distributeCandies(int* candyType, int candyTypeSize) {
  if (candyTypeSize == 2) return 1;

  qsort(candyType, candyTypeSize, sizeof(int), compare);

  int uniques = 1;
  const int half = candyTypeSize / 2;

  for (int i = 1; i < candyTypeSize; ++i) {
    if (candyType[i] != candyType[i - 1]) {
      ++uniques;
      if (uniques == half) break;
    }
  }

  return uniques;
}
