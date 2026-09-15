#include <stdlib.h>

int* nextGreaterElements(int* nums, int numsSize, int* returnSize) {
  int greatestI = 0;
  for (int i = 1; i < numsSize; ++i) {
    if (nums[i] > nums[greatestI]) greatestI = i;
  }

  int* greaters = malloc(numsSize * sizeof(int));
  int greatersSize = 0;

  greaters[greatersSize++] = nums[greatestI];
  nums[greatestI] = -1;

  int i = greatestI == 0 ? numsSize - 1 : greatestI - 1;
  while (i != greatestI) {
    while (greatersSize != 0 && greaters[greatersSize - 1] <= nums[i]) {
      --greatersSize;
    }

    const int prev = nums[i];
    nums[i] = greatersSize == 0 ? -1 : greaters[greatersSize - 1];
    greaters[greatersSize++] = prev;

    if (i == 0) {
      i = numsSize - 1;
    } else {
      --i;
    }
  }

  free(greaters);

  *returnSize = numsSize;
  return nums;
}
