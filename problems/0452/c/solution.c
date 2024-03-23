#include <stdlib.h>

int comp(const void* a, const void* b) {
  return **(int**)a < **(int**)b ? -1 : 1;
}

int findMinArrowShots(int** points, int pointsSize, int* pointsColSize) {
  (void)pointsColSize;

  qsort(points, pointsSize, sizeof(int*), comp);

  int arrows = 1;
  int end = points[0][1];
  for (int i = 1; i < pointsSize; ++i) {
    if (points[i][0] > end) {
      ++arrows;
      end = points[i][1];
    } else if (points[i][1] < end) {
      end = points[i][1];
    }
  }

  return arrows;
}
