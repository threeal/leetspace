int* transformArray(int* nums, int numsSize, int* returnSize) {
  int l = 0;
  for (int i = 0; i < numsSize; ++i) {
    if (nums[i] % 2 == 0) nums[l++] = 0;
  }
  while (l < numsSize) nums[l++] = 1;

  *returnSize = numsSize;
  return nums;
}
