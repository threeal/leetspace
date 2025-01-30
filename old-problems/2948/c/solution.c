#include <stdlib.h>
#include <string.h>

int* gNums;
int compareIdxs(const void* a, const void* b) {
  return gNums[*(int*)a] - gNums[*(int*)b];
}

int compare(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int* lexicographicallySmallestArray(
    int* nums, int numsSize, int limit, int* returnSize) {
  int* numsIdxs = malloc(numsSize * sizeof(int));
  for (int i = 0; i < numsSize; ++i) numsIdxs[i] = i;

  gNums = nums;
  qsort(numsIdxs, numsSize, sizeof(int), compareIdxs);

  int* outputIdxs = malloc(numsSize * sizeof(int));
  memcpy(outputIdxs, numsIdxs, numsSize * sizeof(int));

  int prev = 0;
  for (int i = 1; i < numsSize; ++i) {
    if (nums[numsIdxs[i]] - nums[numsIdxs[i - 1]] > limit) {
      qsort(outputIdxs + prev, i - prev, sizeof(int), compare);
      prev = i;
    }
  }
  qsort(outputIdxs + prev, numsSize - prev, sizeof(int), compare);

  int* output = malloc(numsSize * sizeof(int));
  for (int i = 0; i < numsSize; ++i) {
    output[outputIdxs[i]] = nums[numsIdxs[i]];
  }

  *returnSize = numsSize;
  return output;
}
