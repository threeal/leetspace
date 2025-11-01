int alternatingSum(int* nums, int numsSize) {
  int sum = 0;
  for (int i = 0; i < numsSize; ++i) {
    sum += nums[i];
    if (++i == numsSize) break;
    sum -= nums[i];
  }
  return sum;
}
