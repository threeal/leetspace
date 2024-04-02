#include <stdlib.h>

int compar(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int** divideArray(int* nums, int numsSize, int k, int* returnSize, int** returnColumnSizes) {
  qsort(nums, numsSize, sizeof(int), compar);

  for (int i = 2; i < numsSize; i += 3) {
    if (nums[i] - nums[i - 2] > k) {
      *returnSize = 0;
      return NULL;
    }
  }

  *returnSize = numsSize / 3;

  int** returnData = malloc(*returnSize * sizeof(int*));
  *returnColumnSizes = malloc(*returnSize * sizeof(int));
  for (int i = 0; i < *returnSize; ++i) {
    returnData[i] = malloc(3 * sizeof(int));
    (*returnColumnSizes)[i] = 3;
  }

  for (int i = 0; i < *returnSize; ++i) {
    for (int j = 0; j < 3; ++j) {
      returnData[i][j] = nums[i * 3 + j];
    }
  }

  return returnData;
}
