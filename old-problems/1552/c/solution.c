#include <stdlib.h>

int comp(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int maxDistance(int* position, int positionSize, int m) {
  qsort(position, positionSize, sizeof(int), comp);

  int low = 1;
  int high = (position[positionSize - 1] - position[0]) / (m - 1);
  while (low < high) {
    const int mid = (low + high + 1) / 2;

    int balls = 1;
    for (int i = positionSize - 2, prev = position[positionSize - 1]; i >= 0; --i) {
      if (prev - position[i] >= mid) {
        prev = position[i];
        ++balls;
      }
    }

    if (balls < m) {
      high = mid - 1;
    } else {
      low = mid;
    }
  }

  return high;
}
