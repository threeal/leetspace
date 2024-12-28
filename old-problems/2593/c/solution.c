#include <stdlib.h>
#include <string.h>

int* gNums;

int compare(const void* a, const void* b) {
  const int aa = *(int*)a;
  const int bb = *(int*)b;
  return gNums[aa] == gNums[bb] ? aa - bb : gNums[aa] - gNums[bb];
}

long long findScore(int* nums, int numsSize) {
  gNums = nums;

  char* marked = malloc(numsSize * sizeof(char));
  memset(marked, 0, numsSize * sizeof(char));

  int* idxs = malloc(numsSize * sizeof(int));
  for (int i = 0; i < numsSize; ++i) idxs[i] = i;

  qsort(idxs, numsSize, sizeof(int), compare);

  long long score = 0;
  for (int i = 0; i < numsSize; ++i) {
    if (marked[idxs[i]]) continue;
    score += nums[idxs[i]];
    marked[idxs[i]] = 1;
    if (idxs[i] > 0) marked[idxs[i] - 1] = 1;
    if (idxs[i] < numsSize - 1) marked[idxs[i] + 1] = 1;
  }

  return score;
}
