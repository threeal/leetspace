int* applyOperations(int* nums, int numsSize, int* returnSize) {
  int i = 0;
  for (int j = 1; j < numsSize; ++j) {
    if (nums[j - 1] == 0) continue;
    if (nums[j - 1] == nums[j]) {
      nums[i++] = 2 * nums[j - 1];
      nums[j] = 0;
      ++j;
    } else {
      nums[i++] = nums[j - 1];
    }
  }
  if (nums[numsSize - 1] > 0) nums[i++] = nums[numsSize - 1];
  while (i < numsSize) nums[i++] = 0;

  *returnSize = numsSize;
  return nums;
}
