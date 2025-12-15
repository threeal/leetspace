#include <stdlib.h>

int* gMappedNums;
int compare(const void* a, const void* b) {
  const int aa = *(int*)a;
  const int bb = *(int*)b;
  return gMappedNums[aa] != gMappedNums[bb]
      ? gMappedNums[aa] - gMappedNums[bb]
      : aa - bb;
}

int* sortJumbled(
    int* mapping, int mappingSize, int* nums, int numsSize, int* returnSize) {
  (void)mappingSize;

  int* mappedNums = malloc(numsSize * sizeof(int));
  for (int i = 0; i < numsSize; ++i) {
    if (nums[i] == 0) {
      mappedNums[i] = mapping[0];
    } else {
      int num = nums[i], mappedNum = 0, exp = 1;
      while (num != 0) {
        mappedNum += mapping[num % 10] * exp;
        num /= 10;
        exp *= 10;
      }
      mappedNums[i] = mappedNum;
    }
  }

  int* indices = malloc(numsSize * sizeof(int));
  for (int i = 0; i < numsSize; ++i) indices[i] = i;

  gMappedNums = mappedNums;
  qsort(indices, numsSize, sizeof(int), compare);

  for (int i = 0; i < numsSize; ++i) {
    indices[i] = nums[indices[i]];
  }

  free(mappedNums);

  *returnSize = numsSize;
  return indices;
}
