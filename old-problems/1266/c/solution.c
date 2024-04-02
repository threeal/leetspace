#include <stdlib.h>

int minTimeToVisitAllPoints(int** points, int pointsSize, int* pointsColSize) {
  (void)pointsColSize;
  int time = 0;

  // Calculate the distance between each pair of points.
  for (int i = 1; i < pointsSize; ++i) {
    // The distance between two points is equal to the maximum distance between x and y axes.
    const int dx = abs(points[i][0] - points[i - 1][0]);
    const int dy = abs(points[i][1] - points[i - 1][1]);
    time += dx > dy ? dx : dy;
  }

  return time;
}
