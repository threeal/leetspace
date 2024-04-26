#include <stdbool.h>
#include <stdlib.h>

bool validPath(int n, int** edges, int edgesSize, int* edgesColSize, int source, int destination) {
  (void)edgesColSize;

  if (source == destination) return true;

  bool* visited = malloc(sizeof(bool) * n);
  for (int i = 0; i < n; ++i) {
    visited[i] = false;
  }
  visited[source] = true;

  int prevEdgesSize = edgesSize + 1;
  while (edgesSize != prevEdgesSize) {
    prevEdgesSize = edgesSize;
    for (int i = 0; i < edgesSize; ++i) {
      if (visited[edges[i][0]] != visited[edges[i][1]]) {
        visited[edges[i][0]] = true;
        visited[edges[i][1]] = true;

        edges[i] = edges[--edgesSize];
        --i;
      }
    }
    if (visited[destination]) return true;
  }

  return false;
}
