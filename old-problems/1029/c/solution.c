#include <stdlib.h>

int compare(const void* a, const void* b) {
  int* aa = *(int**)a;
  int* bb = *(int**)b;
  return (aa[0] - aa[1]) - (bb[0] - bb[1]);
}

int twoCitySchedCost(int** costs, int costsSize, int* costsColSize) {
  (void)costsColSize;
  qsort(costs, costsSize, sizeof(int*), compare);

  int sum = 0;
  const int half = costsSize / 2;
  for (int i = 0; i < half; ++i) sum += costs[i][0];
  for (int i = half; i < costsSize; ++i) sum += costs[i][1];
  return sum;
}
