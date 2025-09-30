#include <limits.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
  return (*(int**)a)[0] != (*(int**)b)[0]
      ? (*(int**)a)[0] - (*(int**)b)[0]
      : (*(int**)b)[1] - (*(int**)a)[1];
}

int numberOfPairs(int** points, int pointsSize, int* pointsColSize) {
  (void)pointsColSize;

  qsort(points, pointsSize, sizeof(int*), compare);

  int count = 0;
  for (int i = 0; i < pointsSize; ++i) {
    int xMin = points[i][0] - 1;
    int yMin = INT_MIN;

    for (int j = i + 1; j < pointsSize; ++j) {
      if (points[j][0] > xMin && points[j][1] > yMin &&
          points[j][1] <= points[i][1]) {
        ++count;
        xMin = points[j][0];
        yMin = points[j][1];
      }
    }
  }

  return count;
}
