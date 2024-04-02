#include <stdlib.h>

int* findErrorNums(int* nums, int numsSize, int* returnSize) {
  *returnSize = 2;
  int* returnData = malloc(*returnSize * sizeof(int));

  for (int i = 0; i < numsSize; ++i) {
    int num = nums[i];
    if (num < 0) num *= -1;

    if (nums[num - 1] < 0) {
      returnData[0] = num;
    } else {
      nums[num - 1] *= -1;
    }
  }

  for (int i = 0; i < numsSize; ++i) {
    if (nums[i] > 0) {
      returnData[1] = i + 1;
      break;
    }
  }

  return returnData;
}
