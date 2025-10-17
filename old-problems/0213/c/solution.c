int rob(int* nums, int numsSize) {
  if (numsSize == 1) return nums[0];

  int a0 = nums[0], a1 = 0, b0 = 0, b1 = 0;
  for (int i = 1; i + 1 < numsSize; ++i) {
    b0 = a0 >= b0 + nums[i] ? a0 : b0 + nums[i];
    b1 = a1 >= b1 + nums[i] ? a1 : b1 + nums[i];

    if (++i + 1 >= numsSize) {
      int max = a0;
      if (a1 + nums[numsSize - 1] > max) max = a1 + nums[numsSize - 1];
      if (b0 > max) max = b0;
      if (b1 > max) max = b1;
      return max;
    }

    a0 = b0 >= a0 + nums[i] ? b0 : a0 + nums[i];
    a1 = b1 >= a1 + nums[i] ? b1 : a1 + nums[i];
  }

  int max = a0;
  if (a1 > max) max = a1;
  if (b0 > max) max = b0;
  if (b1 + nums[numsSize - 1] > max) max = b1 + nums[numsSize - 1];
  return max;
}
