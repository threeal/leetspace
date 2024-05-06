#include <stdlib.h>
#include <string.h>

void dfsCount(int** nexts, int* nextsSize, int* sums, int* counts, int node, int parent);
void dfsSum(int n, int** nexts, int* nextsSize, int* sums, int* counts, int node, int parent);

int* sumOfDistancesInTree(int n, int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
  (void)edgesColSize;

  int* nextsSize = malloc(n * sizeof(int));
  memset(nextsSize, 0, n * sizeof(int));
  for (int i = 0; i < edgesSize; ++i) {
    ++nextsSize[edges[i][0]];
    ++nextsSize[edges[i][1]];
  }

  int** nexts = malloc(n * sizeof(int*));
  for (int i = 0; i < n; ++i) {
    nexts[i] = malloc(nextsSize[i] * sizeof(int));
    nextsSize[i] = 0;
  }
  for (int i = 0; i < edgesSize; ++i) {
    nexts[edges[i][0]][nextsSize[edges[i][0]]++] = edges[i][1];
    nexts[edges[i][1]][nextsSize[edges[i][1]]++] = edges[i][0];
  }

  int* counts = malloc(n * sizeof(int));
  int* sums = malloc(n * sizeof(int));
  for (int i = 0; i < n; ++i) {
    counts[i] = 1;
    sums[i] = 0;
  }

  dfsCount(nexts, nextsSize, sums, counts, 0, -1);
  dfsSum(n, nexts, nextsSize, sums, counts, 0, -1);

  free(counts);
  for (int i = 0; i < n; ++i) free(nexts[i]);
  free(nexts);
  free(nextsSize);

  *returnSize = n;
  return sums;
}

void dfsCount(int** nexts, int* nextsSize, int* sums, int* counts, int node, int parent) {
  for (int i = 0; i < nextsSize[node]; ++i) {
    int next = nexts[node][i];
    if (next == parent) continue;
    dfsCount(nexts, nextsSize, sums, counts, next, node);
    counts[node] += counts[next];
    sums[node] += counts[next] + sums[next];
  }
}

void dfsSum(int n, int** nexts, int* nextsSize, int* sums, int* counts, int node, int parent) {
  for (int i = 0; i < nextsSize[node]; ++i) {
    int next = nexts[node][i];
    if (next == parent) continue;
    sums[next] = sums[node] + n - counts[next] * 2;
    dfsSum(n, nexts, nextsSize, sums, counts, next, node);
  }
}
