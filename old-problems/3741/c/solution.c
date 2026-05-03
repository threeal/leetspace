#include <stdlib.h>

int* gNums;
int compare(const void* a, const void* b) {
  int aa = *(int*)a;
  int bb = *(int*)b;
  return gNums[aa] == gNums[bb] ? aa - bb : gNums[aa] - gNums[bb];
}

int minimumDistance(int* nums, int numsSize) {
  int* idxs = malloc(numsSize * sizeof(int));
  for (int i = 0; i < numsSize; ++i) idxs[i] = i;

  gNums = nums;
  qsort(idxs, numsSize, sizeof(int), compare);

  int minDist = numsSize;
  for (int i = 2; i < numsSize; ++i) {
    if (nums[idxs[i - 2]] == nums[idxs[i]] &&
        idxs[i] - idxs[i - 2] < minDist) {
      minDist = idxs[i] - idxs[i - 2];
    }
  }

  free(idxs);

  return minDist == numsSize ? -1 : minDist * 2;
}
