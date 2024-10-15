#include <stdlib.h>

int compare(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int findMinDifference(char** timePoints, int timePointsSize) {
  int* minutes = malloc(timePointsSize * sizeof(int));
  for (int i = timePointsSize - 1; i >= 0; --i) {
    minutes[i] = (timePoints[i][0] - '0') * 600 +
        (timePoints[i][1] - '0') * 60 +
        (timePoints[i][3] - '0') * 10 +
        (timePoints[i][4] - '0');
  }

  qsort(minutes, timePointsSize, sizeof(int), compare);

  int min = 24 * 60 + minutes[0] - minutes[timePointsSize - 1];
  for (int i = timePointsSize - 1; i > 0; --i) {
    if (minutes[i] - minutes[i - 1] < min) min = minutes[i] - minutes[i - 1];
  }

  free(minutes);
  return min;
}
