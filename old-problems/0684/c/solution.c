#include <stdlib.h>

static int findRoot(int* roots, int node);

int* findRedundantConnection(
    int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
  int* roots = malloc((edgesSize + 1) * sizeof(int));
  for (int i = 0; i < edgesSize + 1; ++i) roots[i] = i;

  int* rootSizes = malloc((edgesSize + 1) * sizeof(int));
  for (int i = 0; i < edgesSize + 1; ++i) rootSizes[i] = 1;

  for (int i = 0; i < edgesSize; ++i) {
    const int a = findRoot(roots, edges[i][0]);
    const int b = findRoot(roots, edges[i][1]);

    if (a == b) {
      *returnSize = edgesColSize[i];
      return edges[i];
    }

    if (rootSizes[a] <= rootSizes[b]) {
      roots[b] = a;
      rootSizes[a] += rootSizes[b];
    } else {
      roots[a] = b;
      rootSizes[b] += rootSizes[a];
    }
  }

  *returnSize = edgesColSize[0];
  return edges[0];
}

static int findRoot(int* roots, int node) {
  return roots[node] != node
      ? roots[node] = findRoot(roots, roots[node])
      : node;
}
