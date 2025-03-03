#include <stdbool.h>
#include <stdlib.h>

static int findRoot(int* roots, int n);

bool* areConnected(
    int n, int threshold, int** queries, int queriesSize, int* queriesColSize,
    int* returnSize) {
  (void)queriesColSize;

  int* roots = malloc((n + 1) * sizeof(int));
  for (int i = 0; i <= n; ++i) roots[i] = i;

  int* rootSizes = malloc((n + 1) * sizeof(int));
  for (int i = 0; i <= n; ++i) rootSizes[i] = 1;

  for (int a = threshold + 1; a <= n; ++a) {
    int rootA = findRoot(roots, a);
    for (int b = a + a; b <= n; b += a) {
      const int rootB = findRoot(roots, b);
      if (rootSizes[rootA] < rootSizes[rootB]) rootA = rootB;
    }

    for (int b = a; b <= n; b += a) {
      const int rootB = findRoot(roots, b);
      if (rootB != rootA) {
        roots[rootB] = rootA;
        rootSizes[rootA] += rootSizes[rootB];
      }
    }
  }

  bool* outputs = malloc(queriesSize * sizeof(bool));
  for (int i = 0; i < queriesSize; ++i) {
    outputs[i] =
        findRoot(roots, queries[i][0]) == findRoot(roots, queries[i][1]);
  }

  *returnSize = queriesSize;
  return outputs;
}

static int findRoot(int* roots, int n) {
  return roots[n] == n ? n : (roots[n] = findRoot(roots, roots[n]));
}
