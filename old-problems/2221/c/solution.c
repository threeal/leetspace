int triangularSum(int* nums, int numsSize) {
  for (int n = numsSize; n > 1; --n) {
    for (int i = 1; i < n; ++i) {
      nums[i - 1] = (nums[i - 1] + nums[i]) % 10;
    }
  }
  return nums[0];
}
