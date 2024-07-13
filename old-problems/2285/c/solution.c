#include <stdlib.h>
#include <string.h>

int reversedCompare(const void* a, const void* b) {
  return *(int*)b - *(int*)a;
}

long long maximumImportance(
    int n, int** roads, int roadsSize, int* roadsColSize) {
  (void)roadsColSize;

  int* counts = malloc(n * sizeof(int));
  memset(counts, 0, n * sizeof(int));

  for (int i = roadsSize - 1; i >= 0; --i) {
    ++counts[roads[i][0]];
    ++counts[roads[i][1]];
  }

  qsort(counts, n, sizeof(int), reversedCompare);

  long long importance = 0;
  long long id = 1;
  for (int i = n - 1; i >= 0; --i) {
    importance += id * counts[i];
    ++id;
  }

  free(counts);
  return importance;
}
