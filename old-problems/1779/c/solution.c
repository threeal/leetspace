#include <limits.h>
#include <stdlib.h>

int nearestValidPoint(
    int x, int y, int** points, int pointsSize, int* pointsColSize) {
  (void)pointsColSize;

  int nearest = -1, distance = INT_MAX;
  for (int i = 0; i < pointsSize; ++i) {
    if (points[i][0] == x) {
      if (abs(points[i][1] - y) < distance) {
        nearest = i;
        distance = abs(points[i][1] - y);
      }
    } else if (points[i][1] == y) {
      if (abs(points[i][0] - x) < distance) {
        nearest = i;
        distance = abs(points[i][0] - x);
      }
    }
  }

  return nearest;
}
