#include <stdlib.h>

int comp(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int eliminateMaximum(int* dist, int distSize, int* speed, int speedSize) {
  // Calculate the time required before enemies reach distance zero.
  (void)speedSize;

  for (int i = 0; i < distSize; ++i) {
    dist[i] = dist[i] / speed[i] + (dist[i] % speed[i] > 0 ? 1 : 0);
  }

  // Sort the time required from lowest to highest.
  qsort(dist, distSize, sizeof(int), comp);

  // Time equals to kills. Iterate through the time required as long as the current time is not greater than the time required.
  int kills = 0;
  for (int i = 0; i < distSize; ++i) {
    if (kills + 1 > dist[i]) break;
    ++kills;
  }

  return kills;
}
