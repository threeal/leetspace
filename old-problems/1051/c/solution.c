#include <stdlib.h>
#include <string.h>

int comp(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int heightChecker(int* heights, int heightsSize) {
  int* sortedHeights = malloc(heightsSize * sizeof(int));
  memcpy(sortedHeights, heights, heightsSize * sizeof(int));

  qsort(sortedHeights, heightsSize, sizeof(int), comp);

  int diff = 0;
  for (int i = heightsSize - 1; i >= 0; --i) {
    if (heights[i] != sortedHeights[i]) ++diff;
  }

  free(sortedHeights);

  return diff;
}
