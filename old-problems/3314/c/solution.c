int* minBitwiseArray(int* nums, int numsSize, int* returnSize) {
  for (int i = 0; i < numsSize; ++i) {
    nums[i] = nums[i] != 2
        ? nums[i] - ((nums[i] + 1) & (-nums[i] - 1)) / 2
        : -1;
  }

  *returnSize = numsSize;
  return nums;
}
