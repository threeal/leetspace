int rob(int* nums, int numsSize) {
  if (numsSize >= 2) {
    if (nums[0] > nums[1]) nums[1] = nums[0];
    for (int i = 2; i < numsSize; ++i) {
      nums[i] += nums[i - 2];
      if (nums[i - 1] > nums[i]) nums[i] = nums[i - 1];
    }
  }

  return nums[numsSize - 1];
}
