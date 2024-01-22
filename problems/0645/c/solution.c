#include <stdlib.h>

int* findErrorNums(int* nums, int numsSize, int* returnSize) {
  *returnSize = 2;
  int* returnData = malloc(*returnSize * sizeof(int));

  returnData[0] = nums[0];
  returnData[1] = nums[numsSize - 1];

  return returnData;
}
