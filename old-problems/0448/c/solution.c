int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
  for (int i = 0; i < numsSize; ++i) {
    const int idx = nums[i] > 0 ? nums[i] - 1 : -nums[i] - 1;
    if (nums[idx] > 0) nums[idx] = -nums[idx];
  }

  int outSize = 0;
  for (int i = 0; i < numsSize; ++i) {
    if (nums[i] > 0) nums[outSize++] = i + 1;
  }

  *returnSize = outSize;
  return nums;
}
