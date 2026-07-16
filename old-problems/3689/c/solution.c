long long maxTotalValue(int* nums, int numsSize, int k) {
  int min = nums[0], max = nums[0];
  for (int i = 1; i < numsSize; ++i) {
    if (nums[i] < min) {
      min = nums[i];
    } else if (nums[i] > max) {
      max = nums[i];
    }
  }
  return (long long)(max - min) * k;
}
