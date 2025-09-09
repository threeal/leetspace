int maximumUniqueSubarray(int* nums, int numsSize) {
  int maxSum = 0, sum = 0;
  unsigned char uniques[12501] = {0};
  for (int l = 0, r = 0; r < numsSize; ++r) {
    while ((uniques[nums[r] / 8] >> (nums[r] % 8) & 1) != 0) {
      uniques[nums[l] / 8] &= ~(1 << (nums[l] % 8));
      sum -= nums[l];
      ++l;
    }
    uniques[nums[r] / 8] |= 1 << (nums[r] % 8);
    sum += nums[r];
    if (sum > maxSum) maxSum = sum;
  }
  return maxSum;
}
