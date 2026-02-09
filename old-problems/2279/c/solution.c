#include <stdlib.h>

int compare(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int maximumBags(
    int* capacity, int capacitySize, int* rocks, int rocksSize,
    int additionalRocks) {
  (void)rocksSize;

  for (int i = 0; i < capacitySize; ++i) capacity[i] -= rocks[i];
  qsort(capacity, capacitySize, sizeof(int), compare);

  int i = 0;
  while (i < capacitySize && capacity[i] <= additionalRocks) {
    additionalRocks -= capacity[i];
    ++i;
  }

  return i;
}
