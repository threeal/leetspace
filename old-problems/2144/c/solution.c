#include <stdlib.h>

int compare(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int minimumCost(int* cost, int costSize) {
  qsort(cost, costSize, sizeof(int), compare);

  int total = 0;
  int i = costSize - 2;
  while (i >= 0) {
    total += cost[i] + cost[i + 1];
    i -= 3;
  }
  if (i == -1) total += cost[0];

  return total;
}
