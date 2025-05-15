int subarraySum(int* nums, int numsSize) {
  int sum = nums[0];
  for (int i = 1; i < numsSize; ++i) {
    if (nums[i] < i) {
      sum -= nums[i - nums[i] - 1];
    }
    nums[i] += nums[i - 1];
    sum += nums[i];
  }
  return sum;
}
