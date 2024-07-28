#include <limits.h>
#include <stdlib.h>

int findTheCity(
    int n, int** edges, int edgesSize, int* edgesColSize,
    int distanceThreshold) {
  (void)edgesColSize;

  int** distances = malloc(n * sizeof(int*));
  for (int i = n - 1; i >= 0; --i) {
    distances[i] = malloc(n * sizeof(int));
    for (int j = n - 1; j > i; --j) {
      distances[i][j] = INT_MAX;
    }
    distances[i][i] = 0;
    for (int j = i - 1; j >= 0; --j) {
      distances[i][j] = INT_MAX;
    }
  }

  for (int i = edgesSize - 1; i >= 0; --i) {
    distances[edges[i][0]][edges[i][1]] = edges[i][2];
    distances[edges[i][1]][edges[i][0]] = edges[i][2];
  }

  for (int i = n - 1; i >= 0; --i) {
    for (int j = n - 1; j >= 0; --j) {
      if (distances[i][j] == INT_MAX) continue;
      for (int k = n - 1; k >= 0; --k) {
        if (distances[j][k] == INT_MAX) continue;
        if (distances[i][j] + distances[j][k] < distances[i][k]) {
          distances[i][k] = distances[i][j] + distances[j][k];
          distances[k][i] = distances[i][j] + distances[j][k];
        }
      }
    }
  }

  int theCity = n;
  int theCount = INT_MAX;
  for (int i = n - 1; i >= 0; --i) {
    int count = 0;
    for (int j = n - 1; j >= 0; --j) {
      if (distances[i][j] <= distanceThreshold) ++count;
    }

    if (count < theCount) {
      theCity = i;
      theCount = count;
    }
  }

  for (int i = n - 1; i >= 0; --i) {
    free(distances[i]);
  }
  free(distances);

  return theCity;
}
