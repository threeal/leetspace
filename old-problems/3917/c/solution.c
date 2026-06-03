int* countOppositeParity(int* nums, int numsSize, int* returnSize) {
  int even = 0, odd = 0;
  for (int i = numsSize; i > 0;) {
    --i;
    if (nums[i] % 2 == 0) {
      nums[i] = odd;
      ++even;
    } else {
      nums[i] = even;
      ++odd;
    }
  }
  *returnSize = numsSize;
  return nums;
}
