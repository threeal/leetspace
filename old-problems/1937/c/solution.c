#include <stdlib.h>
#include <string.h>

long long maxPoints(int** points, int pointsSize, int* pointsColSize) {
  const int n = pointsColSize[0];

  long long* current = malloc(n * sizeof(long long));
  long long* prev = malloc(n * sizeof(long long));
  memset(prev, 0, n * sizeof(long long));

  for (int i = 0; i < pointsSize; ++i) {
    long long max = 0;
    for (int j = 0; j < n; ++j) {
      max = max - 1 > prev[j] ? max - 1 : prev[j];
      current[j] = max;
    }

    max = 0;
    for (int j = n - 1; j >= 0; --j) {
      max = max - 1 > prev[j] ? max - 1 : prev[j];
      current[j] = points[i][j] + (max > current[j] ? max : current[j]);
    }

    long long* temp = current;
    current = prev;
    prev = temp;
  }

  long long max = 0;
  for (int i = 0; i < n; ++i) {
    if (prev[i] > max) max = prev[i];
  }

  free(current);
  free(prev);

  return max;
}
