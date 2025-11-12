int minOperations(int* nums, int numsSize) {
  int count = 0, n = -1;
  for (int i = 0; i < numsSize; ++i) {
    while (n >= 0 && nums[n] >= nums[i]) {
      if (nums[n] > nums[i]) ++count;
      --n;
    }
    if (nums[i] > 0) nums[++n] = nums[i];
  }
  return count + n + 1;
}
