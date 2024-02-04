#include <stdlib.h>

int** divideArray(int* nums, int numsSize, int k, int* returnSize, int** returnColumnSizes) {
  (void)nums;
  (void)k;

  *returnSize = numsSize / 3;

  int** returnData = malloc(*returnSize * sizeof(int*));
  *returnColumnSizes = malloc(*returnSize * sizeof(int));
  for (int i = 0; i < *returnSize; ++i) {
    returnData[i] = malloc(3 * sizeof(int));
    (*returnColumnSizes)[i] = 3;
  }

  return returnData;
}
