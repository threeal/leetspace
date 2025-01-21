int waysToSplitArray(int* nums, int numsSize) {
  long long right = 0;
  for (int i = 0; i < numsSize; ++i) {
    right += nums[i];
  }

  --numsSize;

  long long left = 0;
  int count = 0;
  for (int i = 0; i < numsSize; ++i) {
    left += nums[i];
    right -= nums[i];
    if (left >= right) ++count;
  }

  return count;
}
