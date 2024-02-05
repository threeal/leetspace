#include <stdlib.h>

int comp(const void* a, const void* b) {
  return **(int**)a - **(int**)b;
}

int maxWidthOfVerticalArea(int** points, int pointsSize, int* pointsColSize) {
  (void)pointsColSize;

  // Sort the x coordinates.
  qsort(points, pointsSize, sizeof(int*), comp);

  // Find the maximum difference between two different x coordinates.
  int prev_x = points[0][0];
  int max_width = 0;
  for (int i = 1; i < pointsSize; ++i) {
    if (points[i][0] == prev_x) continue;
    if (points[i][0] - prev_x > max_width)
      max_width = points[i][0] - prev_x;
    prev_x = points[i][0];
  }

  return max_width;
}
