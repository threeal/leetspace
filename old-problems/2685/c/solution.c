#include <stdlib.h>

static int findRoot(int* roots, int i);

int countCompleteComponents(
    int n, int** edges, int edgesSize, int* edgesColSize) {
  (void)edgesColSize;

  int* roots = malloc(n * sizeof(int));
  int* rootNodes = malloc(n * sizeof(int));
  int* rootEdges = malloc(n * sizeof(int));

  for (int i = 0; i < n; ++i) {
    roots[i] = i;
    rootNodes[i] = 1;
    rootEdges[i] = 0;
  }

  for (int i = 0; i < edgesSize; ++i) {
    const int root0 = findRoot(roots, edges[i][0]);
    const int root1 = findRoot(roots, edges[i][1]);

    if (root0 == root1) {
      ++rootEdges[root0];
    } else {
      if (rootNodes[root0] >= rootNodes[root1]) {
        roots[root1] = root0;
        rootNodes[root0] += rootNodes[root1];
        rootEdges[root0] += 1 + rootEdges[root1];
      } else {
        roots[root0] = root1;
        rootNodes[root1] += rootNodes[root0];
        rootEdges[root1] += 1 + rootEdges[root0];
      }
    }
  }

  int count = 0;
  for (int i = 0; i < n; ++i) {
    if (roots[i] == i &&
        rootEdges[i] == (rootNodes[i] * (rootNodes[i] - 1)) / 2) {
      ++count;
    }
  }

  free(roots);
  free(rootNodes);
  free(rootEdges);

  return count;
}

static int findRoot(int* roots, int i) {
  return roots[i] == i ? i : (roots[i] = findRoot(roots, roots[i]));
}
