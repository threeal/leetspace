#include <stdlib.h>

int** gQueries;
int compareQueryIndices(const void* a, const void* b) {
  return gQueries[*(int*)b][1] - gQueries[*(int*)a][1];
}

int* leftmostBuildingQueries(
    int* heights, int heightsSize,
    int** queries, int queriesSize, int* queriesColSize,
    int* returnSize) {
  (void)queriesColSize;

  for (int i = 0; i < queriesSize; ++i) {
    if (queries[i][0] > queries[i][1]) {
      const int temp = queries[i][0];
      queries[i][0] = queries[i][1];
      queries[i][1] = temp;
    }
  }

  int* queryIndices = malloc(queriesSize * sizeof(int));
  for (int i = 0; i < queriesSize; ++i) queryIndices[i] = i;

  gQueries = queries;
  qsort(queryIndices, queriesSize, sizeof(int), compareQueryIndices);

  int* nexts = malloc(heightsSize * sizeof(int));
  int nextsSize = 0, nextsI = heightsSize - 1;

  int* output = malloc(queriesSize * sizeof(int));
  for (int i = 0; i < queriesSize; ++i) {
    const int alice = queries[queryIndices[i]][0];
    const int bob = queries[queryIndices[i]][1];

    if (alice == bob || heights[alice] < heights[bob]) {
      output[queryIndices[i]] = bob;
      continue;
    }

    while (nextsI > bob) {
      while (nextsSize > 0 &&
             heights[nexts[nextsSize - 1]] <= heights[nextsI]) {
        --nextsSize;
      }
      nexts[nextsSize++] = nextsI--;
    }

    while (nextsSize > 0 && heights[nexts[nextsSize - 1]] <= heights[bob]) {
      --nextsSize;
    }

    if (nextsSize == 0 || heights[nexts[0]] <= heights[alice]) {
      output[queryIndices[i]] = -1;
      continue;
    }

    int low = 0, high = nextsSize - 1;
    while (low < high) {
      const int mid = high - (high - low) / 2;
      if (heights[nexts[mid]] > heights[alice]) {
        low = mid;
      } else {
        high = mid - 1;
      }
    }

    output[queryIndices[i]] = low < nextsSize ? nexts[low] : -1;
  }

  free(queryIndices);
  free(nexts);

  *returnSize = queriesSize;
  return output;
}
