#include <stdlib.h>

int* singleNumber(int* nums, int numsSize, int* returnSize) {
  unsigned int sum = 0;
  for (int i = numsSize - 1; i >= 0; --i) {
    sum ^= nums[i];
  }

  unsigned int mask = 1;
  while ((sum & mask) == 0) {
    mask = mask << 1;
  }

  unsigned int a = 0;
  unsigned int b = 0;
  for (int i = numsSize - 1; i >= 0; --i) {
    if ((nums[i] & mask) == 0) {
      b ^= nums[i];
    } else {
      a ^= nums[i];
    }
  }

  *returnSize = 2;
  int* returnData = malloc(2 * sizeof(int));
  returnData[0] = a;
  returnData[1] = b;

  return returnData;
}
