int countPartitions(int* nums, int numsSize) {
  int right = 0;
  for (int i = 0; i < numsSize; ++i) right += nums[i];

  --numsSize;

  int count = 0, left = 0;
  for (int i = 0; i < numsSize; ++i) {
    left += nums[i];
    right -= nums[i];

    if (left % 2 == right % 2) ++count;
  }

  return count;
}
