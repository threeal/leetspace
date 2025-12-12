#include <stdint.h>

int findChampion(int n, int** edges, int edgesSize, int* edgesColSize) {
  (void)edgesColSize;

  uint64_t isChild[2] = {0};
  for (int i = 0; i < edgesSize; ++i) {
    isChild[edges[i][1] / 64] |= (uint64_t)1 << (edges[i][1] % 64);
  }

  int parent = -1;
  for (int i = 0; i < n; ++i) {
    if ((isChild[i / 64] & ((uint64_t)1 << (i % 64))) == 0) {
      if (parent >= 0) return -1;
      parent = i;
    }
  }

  return parent;
}
