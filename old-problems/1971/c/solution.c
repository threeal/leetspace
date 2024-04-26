#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

bool validPath(int n, int** edges, int edgesSize, int* edgesColSize, int source, int destination) {
  (void)edgesColSize;

  if (source == destination) return true;

  n = n / 8 + (n % 8 == 0 ? 0 : 1);
  uint8_t* visited = malloc(n);
  memset(visited, 0, n);
  visited[source / 8] |= 1 << source % 8;

  int prevEdgesSize = edgesSize + 1;
  while (edgesSize != prevEdgesSize) {
    prevEdgesSize = edgesSize;
    for (int i = 0; i < edgesSize; ++i) {
      if ((visited[edges[i][0] / 8] >> edges[i][0] % 8 & 1) != (visited[edges[i][1] / 8] >> edges[i][1] % 8 & 1)) {
        visited[edges[i][0] / 8] |= 1 << edges[i][0] % 8;
        visited[edges[i][1] / 8] |= 1 << edges[i][1] % 8;
        edges[i] = edges[--edgesSize];
        --i;
      }
    }
    if ((visited[destination / 8] >> destination % 8 & 1) == 1) return true;
  }

  return false;
}
