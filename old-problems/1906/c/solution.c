#include <limits.h>
#include <stdlib.h>
#include <string.h>

int* minDifference(
    int* nums, int numsSize,
    int** queries, int queriesSize, int* queriesColSize,
    int* returnSize) {
  (void)queriesColSize;

  int* freqs = malloc((numsSize + 1) * 100 * sizeof(int));
  memset(freqs, 0, 100 * sizeof(int));

  for (int i = 0; i < numsSize; ++i) {
    memcpy(freqs + (i + 1) * 100, freqs + i * 100, 100 * sizeof(int));
    ++freqs[(i + 1) * 100 + nums[i] - 1];
  }

  int* diffs = malloc(queriesSize * sizeof(int));
  *returnSize = queriesSize;
  for (int i = 0; i < queriesSize; ++i) {
    int diff = INT_MAX;

    int prev = 0, j = 0;
    while (j < 100) {
      if (freqs[(queries[i][1] + 1) * 100 + j] - freqs[queries[i][0] * 100 + j] > 0) {
        prev = j;
        break;
      }
      ++j;
    }

    for (int j = prev + 1; j < 100; ++j) {
      if (freqs[(queries[i][1] + 1) * 100 + j] - freqs[queries[i][0] * 100 + j] > 0) {
        if (j - prev < diff) diff = j - prev;
        prev = j;
      }
    }

    diffs[i] = diff == INT_MAX ? -1 : diff;
  }

  free(freqs);

  return diffs;
}
