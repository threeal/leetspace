int maxAscendingSum(int* nums, int numsSize) {
  int sum = nums[0], maxSum = 0;
  for (int i = 1; i < numsSize; ++i) {
    if (nums[i] > nums[i - 1]) {
      sum += nums[i];
    } else {
      if (sum > maxSum) maxSum = sum;
      sum = nums[i];
    }
  }
  return sum > maxSum ? sum : maxSum;
}
