#include <limits.h>
#include <stdlib.h>

int countCoveredBuildings(
    int n, int** buildings, int buildingsSize, int* buildingsColSize) {
  (void)buildingsColSize;

  int* xMins = malloc((n + 1) * sizeof(int));
  int* xMaxs = malloc((n + 1) * sizeof(int));
  int* yMins = malloc((n + 1) * sizeof(int));
  int* yMaxs = malloc((n + 1) * sizeof(int));

  for (int i = 0; i <= n; ++i) {
    xMins[i] = INT_MAX;
    xMaxs[i] = INT_MIN;
    yMins[i] = INT_MAX;
    yMaxs[i] = INT_MIN;
  }

  for (int i = 0; i < buildingsSize; ++i) {
    int* b = buildings[i];
    if (b[0] < yMins[b[1]]) yMins[b[1]] = b[0];
    if (b[0] > yMaxs[b[1]]) yMaxs[b[1]] = b[0];
    if (b[1] < xMins[b[0]]) xMins[b[0]] = b[1];
    if (b[1] > xMaxs[b[0]]) xMaxs[b[0]] = b[1];
  }

  int count = 0;
  for (int i = 0; i < buildingsSize; ++i) {
    int* b = buildings[i];
    if (b[0] > yMins[b[1]] && b[0] < yMaxs[b[1]] &&
        b[1] > xMins[b[0]] && b[1] < xMaxs[b[0]]) ++count;
  }

  return count;
}
