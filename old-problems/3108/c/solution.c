#include <stdlib.h>

static int findRoot(int* roots, int n);

int* minimumCost(
    int n, int** edges, int edgesSize, int* edgesColSize,
    int** query, int querySize, int* queryColSize, int* returnSize) {
  (void)edgesColSize;
  (void)queryColSize;

  int* roots = malloc(n * sizeof(int));
  int* rootSizes = malloc(n * sizeof(int));
  int* rootCosts = malloc(n * sizeof(int));
  for (int i = 0; i < n; ++i) {
    roots[i] = i;
    rootSizes[i] = 1;
    rootCosts[i] = ~0;
  }

  for (int i = 0; i < edgesSize; ++i) {
    const int root0 = findRoot(roots, edges[i][0]);
    const int root1 = findRoot(roots, edges[i][1]);
    if (root0 == root1) {
      rootCosts[root0] &= edges[i][2];
    } else {
      if (rootSizes[root0] >= rootSizes[root1]) {
        roots[root1] = root0;
        rootSizes[root0] += rootSizes[root1];
        rootCosts[root0] &= rootCosts[root1] & edges[i][2];
      } else {
        roots[root0] = root1;
        rootSizes[root1] += rootSizes[root0];
        rootCosts[root1] &= rootCosts[root0] & edges[i][2];
      }
    }
  }

  int* output = malloc(querySize * sizeof(int));
  for (int i = 0; i < querySize; ++i) {
    const int root0 = findRoot(roots, query[i][0]);
    output[i] = root0 == findRoot(roots, query[i][1]) ? rootCosts[root0] : -1;
  }

  free(roots);
  free(rootSizes);
  free(rootCosts);

  *returnSize = querySize;
  return output;
}

static int findRoot(int* roots, int n) {
  return roots[n] == n ? n : (roots[n] = findRoot(roots, roots[n]));
}
