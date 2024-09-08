#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

double maxProbability(
    int n, int** edges, int edgesSize, int* edgesColSize,
    double* succProb, int succProbSize, int start, int end) {
  (void)edgesColSize;
  (void)succProbSize;

  double* maxProb = malloc(n * sizeof(double));
  memset(maxProb, 0, n * sizeof(double));
  maxProb[start] = 1.0;

  bool updated = true;
  while (updated) {
    updated = false;
    for (int i = edgesSize - 1; i >= 0; --i) {
      if (maxProb[edges[i][0]] * succProb[i] > maxProb[edges[i][1]]) {
        maxProb[edges[i][1]] = maxProb[edges[i][0]] * succProb[i];
        updated = true;
      }

      if (maxProb[edges[i][1]] * succProb[i] > maxProb[edges[i][0]]) {
        maxProb[edges[i][0]] = maxProb[edges[i][1]] * succProb[i];
        updated = true;
      }
    }
  }

  return maxProb[end];
}
